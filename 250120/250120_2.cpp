#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves)
{
    // board의 열 크기만큼 스택 벡터 생성
    vector<stack<int>> lanes(board[0].size());

    // board 가장 밑의 행부터 위로 올라가면서 순회
    for (int i = board.size() - 1; i >= 0; --i)
    {
        for (size_t j = 0; j < board[0].size(); ++j)
        {
            if (board[i][j])
            {
                lanes[j].push(board[i][j]);
            }
        }
    }

    // 바구니와 사라진 인형의 개수를 저장할 변수
    stack<int> bucket;
    int answer = 0;

    // moves에 따라 크레인 작동
    for (int m : moves)
    {
        int column = m - 1; // moves는 1부터 시작하므로 0 기반 인덱스로 변환
        if (!lanes[column].empty())
        {
            int doll = lanes[column].top(); // 인형 꺼내기
            lanes[column].pop();

            // 바구니의 맨 위와 같은 인형인지 확인
            if (!bucket.empty() && bucket.top() == doll)
            {
                bucket.pop();
                answer += 2; // 같은 인형 두 개가 터짐
            }
            else
            {
                bucket.push(doll);
            }
        }
    }
    return answer;
}

int main()
{
    vector<vector<int>> board = {
        {0, 0, 0, 0, 0},
        {0, 0, 1, 0, 3},
        {0, 2, 5, 0, 1},
        {4, 2, 4, 4, 2},
        {3, 5, 1, 3, 1} };
    vector<int> moves = { 1, 5, 3, 5, 1, 2, 1, 4 };

    cout << solution(board, moves) << endl; // 출력: 4
    return 0;
}
