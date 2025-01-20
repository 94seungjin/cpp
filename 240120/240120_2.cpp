#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves)
{
    // board�� �� ũ�⸸ŭ ���� ���� ����
    vector<stack<int>> lanes(board[0].size());

    // board ���� ���� ����� ���� �ö󰡸鼭 ��ȸ
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

    // �ٱ��Ͽ� ����� ������ ������ ������ ����
    stack<int> bucket;
    int answer = 0;

    // moves�� ���� ũ���� �۵�
    for (int m : moves)
    {
        int column = m - 1; // moves�� 1���� �����ϹǷ� 0 ��� �ε����� ��ȯ
        if (!lanes[column].empty())
        {
            int doll = lanes[column].top(); // ���� ������
            lanes[column].pop();

            // �ٱ����� �� ���� ���� �������� Ȯ��
            if (!bucket.empty() && bucket.top() == doll)
            {
                bucket.pop();
                answer += 2; // ���� ���� �� ���� ����
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

    cout << solution(board, moves) << endl; // ���: 4
    return 0;
}
