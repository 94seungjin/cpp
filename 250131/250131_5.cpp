/*
��ȭ��ȣ ���

��ȭ��ȣ�ο� ���� ��ȭ��ȣ �� �� ��ȣ�� �ٸ� ��ȣ�� ���ξ��� ��찡 �ִ��� Ȯ���Ϸ� �մϴ�.
��ȭ��ȣ�� ������ ���� ��� ������ ��ȭ��ȣ�� ������ ��ȭ��ȣ ���λ��Դϴ�.
	- ������ : 119
	- ���ؿ� : 97 674 223
	- ������ : 11 9952 4421

��ȭ��ȣ�ο� ���� ��ȭ��ȣ�� ���� �迭 phone_book�� solution()�Լ��� �Ű������� �־��� �� � ��ȣ�� �ٸ� ��ȣ��
���ξ��̸� False, �׷��� ������ True�� ��ȯ�ϴ� solution()�Լ��� �ۼ����ּ���.

���� ����
1. phone_book�� ���̴� 1�̻� 1,000,000�����Դϴ�.
	- �� ��ȭ��ȣ�� ���̴� 1�̻� 20����
	- ���� ��ȭ��ȣ�� �ߺ��ؼ� ��� ���� ����.

������� ��
phone_book							result
["119", "97674223", "1195524421"]	False
["123", "456", "789"]				True
["12", "123", "1235", "567", "88"]	False

������Ÿ��
bool solution(vector<string> phoneBook)

*/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool solution(vector<string> phoneBook)
{
	sort(phoneBook.begin(), phoneBook.end());

	for (int i = 0; i < phoneBook.size() - 1; ++i)
	{
		if (phoneBook[i] == phoneBook[i + 1].substr(0, phoneBook[i].size()))
		{
			return false;
		}
	}

	return true;
}

int main()
{
	vector<string> case1 = { "119", "97674223", "1195524421" };
	vector<string> case2 = { "123", "456", "789" };
	vector<string> case3 = { "12", "123", "1235", "567", "88" };

	cout << (solution(case1) ? "True" : "False") << endl;
	cout << (solution(case2) ? "True" : "False") << endl;
	cout << (solution(case3) ? "True" : "False") << endl;

	return 0;
}