
// MFCAssignmentDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "MFCAssignment.h"
#include "MFCAssignmentDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCAssignmentDlg 대화 상자



CMFCAssignmentDlg::CMFCAssignmentDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCASSIGNMENT_DIALOG, pParent), m_radius(0), m_thickness(0), gdiplusToken(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCAssignmentDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCAssignmentDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_BN_CLICKED(IDC_BTN_RESET, &CMFCAssignmentDlg::OnBnClickedBtnReset)
	ON_BN_CLICKED(IDC_BTN_RANDOM, &CMFCAssignmentDlg::OnBnClickedBtnRandom)
	ON_EN_CHANGE(IDC_EDIT_RADIUS, &CMFCAssignmentDlg::OnEnChangeEditRadius)
	ON_EN_CHANGE(IDC_EDIT_THICKNESS, &CMFCAssignmentDlg::OnEnChangeEditThickness)
	ON_STN_CLICKED(IDC_STATIC_COORDINATES, &CMFCAssignmentDlg::OnStnClickedStaticCoordinates)
END_MESSAGE_MAP()


// CMFCAssignmentDlg 메시지 처리기

BOOL CMFCAssignmentDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// GDI+ 초기화
	if (GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, nullptr) != Ok)
	{
		AfxMessageBox(L"GDI+ initialization failed!");
		return FALSE; // 초기화 실패 시 종료
	}

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CMFCAssignmentDlg::OnDestroy()
{
	GdiplusShutdown(gdiplusToken); // GDI+ 해제
	CDialogEx::OnDestroy();
}


void CMFCAssignmentDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CMFCAssignmentDlg::OnPaint()
{
	CPaintDC dc(this); // Device context

	if (IsIconic())
	{
		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		Graphics graphics(dc.GetSafeHdc());

		// 클라이언트 영역 가져오기
		CRect clientRect;
		GetClientRect(&clientRect);

		// 펜 및 브러시 설정
		Pen pen(Color(255, 0, 0, 0), static_cast<REAL>(max(3,m_thickness))); // 빨간색 펜
		SolidBrush brush(Color(255, 0, 0, 0));                          // 검은색 브러시

		// 클릭된 점 그리기
		for (const auto& point : m_clickPoints)
		{
			if (clientRect.PtInRect(point)) // 점이 클라이언트 영역 안에 있을 때만 그림
			{
				graphics.FillEllipse(&brush, static_cast<REAL>(point.x - 10), static_cast<REAL>(point.y - 10), 20.0f, 20.0f);
			}
		}

		// 클릭이 3개일 경우 원 그리기
		if (m_clickPoints.size() == 3)
		{
			double x1 = static_cast<double>(m_clickPoints[0].x);
			double y1 = static_cast<double>(m_clickPoints[0].y);
			double x2 = static_cast<double>(m_clickPoints[1].x);
			double y2 = static_cast<double>(m_clickPoints[1].y);
			double x3 = static_cast<double>(m_clickPoints[2].x);
			double y3 = static_cast<double>(m_clickPoints[2].y);

			// 삼각형 외접원의 중심
			double A = x1 * (y2 - y3) - y1 * (x2 - x3) + x2 * y3 - x3 * y2;
			double B = (x1 * x1 + y1 * y1) * (y3 - y2) +
				(x2 * x2 + y2 * y2) * (y1 - y3) +
				(x3 * x3 + y3 * y3) * (y2 - y1);
			double C = (x1 * x1 + y1 * y1) * (x2 - x3) +
				(x2 * x2 + y2 * y2) * (x3 - x1) +
				(x3 * x3 + y3 * y3) * (x1 - x2);

			REAL cx = static_cast<REAL>(-B / (2.0 * A));
			REAL cy = static_cast<REAL>(-C / (2.0 * A));
			REAL r = static_cast<REAL>(sqrt((cx - x1) * (cx - x1) + (cy - y1) * (cy - y1)));

			// 외접원의 중심과 반지름이 클라이언트 영역 안에 있을 경우만 그림
			if (clientRect.PtInRect(CPoint(static_cast<int>(cx), static_cast<int>(cy))))
			{
				graphics.DrawEllipse(&pen, static_cast<REAL>(cx - r), static_cast<REAL>(cy - r),
					static_cast<REAL>(2 * r), static_cast<REAL>(2 * r));
			}
		}
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CMFCAssignmentDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CMFCAssignmentDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	m_dragIndex = -1;
	m_isDragging = false;

	// 클릭된 점 중 가까운 점 찾기
	for (int i = 0; i < m_clickPoints.size(); i++)
	{
		if (abs(m_clickPoints[i].x - point.x) <= 10 && abs(m_clickPoints[i].y - point.y) <= 10)
		{
			m_dragIndex = i;	// 드래그할 점의 인덱스 저장
			m_isDragging = true;
			break;
		}
	}

	// 드래그 중이 아니고, 새로운 점을 추가할 수 있다면 추가
	if (m_clickPoints.size() < 3)
	{
		m_clickPoints.push_back(point);	// 클릭 좌표 저장
		UpdateCoordinatesUI();
		Invalidate();					// 화면 갱신
		UpdateWindow();
	}

	if (m_clickPoints.size() == 3)
	{
		Invalidate();
	}

	CDialogEx::OnLButtonDown(nFlags, point);
}

void CMFCAssignmentDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	CRect clientRect;
	GetClientRect(&clientRect);

	if (m_isDragging && m_dragIndex != -1)
	{
		// 드래그 좌표를 클라이언트 영역 안으로 제한
		point.x = max(clientRect.left, min(point.x, clientRect.right));
		point.y = max(clientRect.top, min(point.y, clientRect.bottom));

		m_clickPoints[m_dragIndex] = point;
		UpdateCoordinatesUI();
		Invalidate(); // 화면 갱신
	}

	CDialogEx::OnMouseMove(nFlags, point);
}

void CMFCAssignmentDlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	if (m_isDragging)
	{
		m_isDragging = false;  // 드래그 종료
		m_dragIndex = -1;      // 선택 해제
	}

	CDialogEx::OnLButtonUp(nFlags, point);
}

void CMFCAssignmentDlg::OnBnClickedBtnReset()
{
	m_clickPoints.clear();	// 클릭 좌표 초기화
	Invalidate();			// 화면 다시 그리기
}


void CMFCAssignmentDlg::OnBnClickedBtnRandom()
{
	srand(static_cast<unsigned int>(time(nullptr)));

	CRect clientRect;
	GetClientRect(&clientRect);

	if (m_clickPoints.size() == 3)
	{
		for (auto& point : m_clickPoints)
		{
			point.x = clientRect.left + rand() % (clientRect.Width());
			point.y = clientRect.top + rand() % (clientRect.Height());
		}
		UpdateCoordinatesUI();
		Invalidate();
		UpdateWindow();
	}
	else
	{
		AfxMessageBox(L"점 3개를 먼저 찍어야합니다.");
	}
}


void CMFCAssignmentDlg::OnEnChangeEditRadius()
{
	CString strValue;
	GetDlgItemText(IDC_EDIT_RADIUS, strValue);
	m_radius = _ttoi(strValue);
}


void CMFCAssignmentDlg::OnEnChangeEditThickness()
{
	CString strValue;
	GetDlgItemText(IDC_EDIT_THICKNESS, strValue);
	m_thickness = _ttoi(strValue);
}


void CMFCAssignmentDlg::OnStnClickedStaticCoordinates()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}

void CMFCAssignmentDlg::UpdateCoordinatesUI()
{
	CString coordinatesText;
	
	if (m_clickPoints.size() == 3)
	{
		coordinatesText.Format(L"Point 1 : (%d, %d) /\n Point 2 : (%d, %d) /\n Point 3 : (%d, %d)",
			m_clickPoints[0].x, m_clickPoints[0].y,
			m_clickPoints[1].x, m_clickPoints[1].y,
			m_clickPoints[2].x, m_clickPoints[2].y);
	}
	else
	{
		coordinatesText = L"점 3개를 클릭하시오";
	}
	SetDlgItemText(IDC_STATIC_COORDINATES, coordinatesText);
}