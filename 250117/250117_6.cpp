/*
¦���� �����ϱ�

���ĺ� �ҹ��ڷ� ������ ���ڿ����� ���� ���ĺ��� 2�� �پ� �ִ� ¦�� ã�´�.
¦�� ã�� �������� �� ���� ������ �� �յڷ� ���ڿ��� �̾���δ�.
�� ������ �ݺ��ؼ� ���ڿ��� ��� �����Ѵٸ� ¦���� �����ϱⰡ ����.
���ڿ� S�� �־����� �� ¦���� �����ϱ⸦ ���������� ������ �� �ִ��� ��ȯ�ϴ� �Լ��� �ϼ�
���������� ������ �� ������ 1��, �ƴϸ� 0�� ��ȯ���ָ��
���� ��� ���ڿ� S�� baabaa -> bbaa -> aa ������ ���ڿ��� ��� ������ �� �����Ƿ� 1�� ��ȯ

���� ����
	- ���ڿ��� ���� : 1,000,000������ �ڿ���
	- ���ڿ��� ��� �ҹ��ڷ� �̷���� �ִ�.

������Ÿ��
int solution(string s)

*/

#include <iostream>
#include <string>
#include <stack>

using namespace std;

int solution(string str)
{
	stack<char> stk;
	int i;

	for (i = 0; i < str.length(); i++)
	{
		if (stk.empty() || stk.top() != str[i])
		{
			stk.push(str[i]);
		}
		else
		{
			stk.pop();
		}
	}
	return stk.empty();
}

int main()
{
	cout << solution("baabaa") << endl;
	cout << solution("cdcd") << endl;

	return 0;
}