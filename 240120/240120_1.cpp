/*
���� 12 �ֽ� ����
�� ������ ��ϵ� �ֽ� ������ ��� �迭 prices�� �Ű������� �־��� ��,
������ �������� ���� �Ⱓ�� �� �������� ��ȯ�ϵ��� solution()�Լ��� �ϼ��ϼ���.

��������
	- prices�� �� ������ 1�̻� 10,000������ �ڿ���
	- prices�� ���̴� 2�̻� 100,000����

�����
	- 1�� ������ W1�� ������ ������ �������� �ʾ���
	- 2�� ������ W2�� ������ ���� �������� ����
	- 3�� ������ W3�� 1�� �ڿ� ������ ������. ���� 1�ʰ� ������ �������� ���� ������ ��
	- 4�� ������ W2�� 1�ʰ� ������ �������� �ʾ���
	- 5�� ������ W3�� 0�ʰ� ���� �������� �ʾ���

������Ÿ��
	vector<int> solution(vector<int> prices)
*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices)
{
	int n = prices.size();
	vector<int> answer(n, 0);
	stack<int> s;

	for (int i = 0; i < n; ++i)
	{
		while (!s.empty() && prices[s.top()] > prices[i])
		{
			int index = s.top();
			s.pop();
			answer[index] = i - index;
		}
		s.push(i);
	}
	while (!s.empty())
	{
		int index = s.top();
		s.pop();
		answer[index] = n - 1 - index;
	}

	return answer;

}

int main()
{
	vector<int> prices = { 1,2,3,2,3 };
	vector<int> result = solution(prices);

	for (int r : result)
	{
		cout << r << " ";
	}

	return 0;
}