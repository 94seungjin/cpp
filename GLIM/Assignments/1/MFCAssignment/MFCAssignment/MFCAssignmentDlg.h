// MFCAssignmentDlg.h: 헤더 파일
//
#pragma once

#include <vector>
#include <cmath>
#include <gdiplus.h>

#pragma comment(lib, "gdiplus.lib")

using namespace std;
using namespace Gdiplus;

// CMFCAssignmentDlg 대화 상자
class CMFCAssignmentDlg : public CDialogEx
{
// 생성입니다.
public:
	CMFCAssignmentDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCASSIGNMENT_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

private:
	vector<CPoint> m_clickPoints;	// 클릭된 좌표를 저장
	int m_radius;					// 사용자 입력 반지름
	int m_thickness;				// 외곽선의 두께
	GdiplusStartupInput gdiplusStartupInput;
	ULONG_PTR gdiplusToken = 0;
	int m_dragIndex = -1;			// 드래그 중인 점의 인덱스
	bool m_isDragging = false;		// 현재 드래그 상태인지 여부

	void UpdateCoordinatesUI();

public:
	void OnDestroy();
	void OnLButtonDown(UINT nFlags, CPoint point);
	void OnMouseMove(UINT nFlags, CPoint point);
	void OnLButtonUp(UINT nFlags, CPoint point);	
	afx_msg void OnBnClickedBtnReset();
	afx_msg void OnBnClickedBtnRandom();
	afx_msg void OnEnChangeEditRadius();
	afx_msg void OnEnChangeEditThickness();
	afx_msg void OnStnClickedStaticCoordinates();
};
