/*
10���� -> 2����

10���� decimal�� �Է¹޾� 2������ ��ȯ�ؼ� ���ڿ� ���·� ��ȯ�ϴ� solution() �Լ��� �����ض�

��������
	- x

������� ��
	10 -> 1010
	27 -> 11011
	12345 -> 11000000111001

������Ÿ��
string solution(int decimal)

�м�
	- �ϴ� 10���� N�� 2�� ���� �������� 2������ ��
	- 
*/

#include <iostream>
#include <stack>
#include <string>

using namespace std;

string solution(int decimal)
{
	// 1. �ϴ� �Է°��� 0�� ��� �ٷ� 0
	if (decimal == 0)
		return "0";

	stack<int> stack;
	while (decimal > 0)
	{
		// 2. 2�� ���� �������� ���ÿ� ����
		stack.push(decimal % 2);
		decimal /= 2;
	}

	string binary = "";
	while (!stack.empty())
	{
		// 3. ���ÿ� ���ʴ�� top()�� �ش�Ǵ� �� binary���� �߰�
		binary += to_string(stack.top());
		stack.pop();
	}
	return binary;
}

int main()
{
	cout << solution(10) << endl;
	cout << solution(27) << endl;
	cout << solution(12345) << endl;

	return 0;
}