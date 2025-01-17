/*
��ȣ ȸ���ϱ�

���� ��Ģ�� ��Ű�� ���ڿ��� �ùٸ� ��ȣ ���ڿ��̶�� ��
	- "()", "[]", "{}"�� ��� �ùٸ� ��ȣ ���ڿ�
	- ���� A�� �ùٸ� ��ȣ ���ڿ��̶��, "(A)", "[A]", "{A}"�� ��� �ùٸ� ��ȣ ���ڿ�. "[]"�� �ùٸ� ��ȣ ���ڿ��̹Ƿ�, "([])"�� �ùٸ�
	- ���� A, B�� �ùٸ� ��ȣ ���ڿ��̶��, AB�� �ùٸ� ��ȣ ���ڿ�. "{}", "([])"�� �ùٸ� ��ȣ ���ڿ� -> "{}([])"�� �ùٸ�

���ȣ, �߰�ȣ, �׸��� �Ұ�ȣ�� �̷���� ���ڿ� s�� �Ű������� �־���.
�� s�� �������� x(0 <= x <(s�� ����))ĭ��ŭ ȸ�������� �� s�� �ùٸ� ��ȣ ���ڿ��� �ǰ� �ϴ� x�� ������ ��ȯ�ϴ� solution �Լ� �ϼ�

��������
	- s�� ���̴� 1�̻� 1,000����

*/

#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>

using namespace std;

// 1. ���� ��ȣ�� ¦ Ȯ��(map�� ���ĵ�, unorderedmap�� ���� �ȵ�)
unordered_map<char, char> bracketPair = { {')', '('}, {']', '['}, {'}', '{'} };

// 2.�μ��� ���� ���ڿ� ���� ��ȣ�� ¦�� �´��� Ȯ��
bool isValid(string& s, int start)
{
	stack<int> stack;
	unsigned int sz = s.size();

	// 3. ���ڿ� ��ȸ
	for (int i = 0; i < sz; i++)
	{
		char ch = s[(start + i) % sz];

		// 4. ch�� ���� ��ȣ�� ���
		if (bracketPair.count(ch))
		{
			// 5. ������ ����ų� top ���Ұ� ch�� ¦�� �´� ������ȣ�� �ƴϸ� false ��ȯ
			if (stack.empty() || stack.top() != bracketPair[ch])
			{
				return false;
			}
			// 6. ch�� ¦�� �´� ���� ��ȣ�� �ش� ���� ��ȣ ����
			stack.pop();
		}
		else
		{
			// 7. ���� ��ȣ�� ���ÿ� Ǫ��
			stack.push(ch);
		}
	}

	// 8. ������ ������� true�� ��ȯ(��ȣ¦ ����)
	return stack.empty();
}

int solution(string s)
{
	int answer = 0;
	int n = s.size();

	for (int i = 0; i < n; i++)
	{
		answer += isValid(s, i);
	}
	return answer;
}

int main()
{
	cout << solution("[](){}") << endl;
	cout << solution("}]()[{") << endl;
	cout << solution("[)(]") << endl;
	cout << solution("}}}") << endl;
	return 0;
}