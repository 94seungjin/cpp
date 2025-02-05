/*
���� ���

XYZ��Ʈ�� ���� �ݾ��� �����ϸ� 10�� ���� ȸ�� �ڰ��� �ο��մϴ�.
XYZ��Ʈ������ ȸ���� ������� ���� 1���� ��ǰ�� �����ϴ� ��縦 �Ѵ�.
���� ��ǰ�� �Ϸ翡 �ϳ��� ������ �� �ִ�.
�˶��� �����̴� �ڽ��� ���ϴ� ��ǰ�� ������ �����ϴ� ��¥�� 10�� �������� ��ġ�� ���� ���缭 ȸ�������� �Ϸ��� �Ѵ�.
���� ��� �����̰� ���ϴ� ��ǰ�� �ٳ��� 3��, ��� 2��, �� 2��, ������� 2��, ���� 1���̰�, XYZ��Ʈ���� 14�ϰ� ȸ����
������� �����ϴ� ��ǰ�� ��¥ ������� ġŲ, ���, ���, �ٳ���, ��, ���, �������, �ٳ���, ������� ��, ����, �ٳ���,
���, �ٳ����� ù° ������ ���� ������ ����� �������� �����Ƿ� ù° ������ ȸ�������� ���� �ʴ´�.
��° ������ ���� ������ �ٳ����� ���ϴ� ��ŭ ���� ������ �� �����Ƿ� ��° ������ ȸ�������� ���� �ʽ��ϴ�.
��°, ��°, �ټ�° ������ ���� ���� ������ ���ϴ� ��ǰ�� ������ ��ġ�ϹǷ� �� �� �Ϸ翡 ȸ�������� �Ѵ�.

�����̰� ���ϴ� ��ǰ�� ��Ÿ���� ���ڿ� �迭 want�� �����̰� ���ϴ� ��ǰ�� ������ ��Ÿ���� ���� �迭 number, XYZ��Ʈ���� �����ϴ� ��ǰ��
��Ÿ���� ���ڿ� �迭 discount�� ���� �� ȸ������ �� �����̰� ���ϴ� ��ǰ�� ��� ���ι��� �� �ִ� ȸ�� ��� ��¥�� �� �ϼ��� ��ȯ�ϴ�
solution()�Լ��� �ϼ��϶�. ������ ���� ������ 0�� return�Ѵ�.

��������
1<=want�� ���� = number�� ���� <= 10
	- 1 <= number�� ���� <= 10
	- number[i]�� want[i]�� ����
	- number�� ���� 10
10<=discount�� ���� <= 100,000
want�� discount�� ���ҵ��� ���ĺ� �ҹ��ڷ� �̷���� ���ڿ�
	- 1<=want�� ���ҿ� ����, discount�� ������ ���� <=12

������� ��
want										number		discount																														result
["banana", "apple", "rice", "pork", "pot"]	[3,2,2,2,1]	["chicken", "apple", "apple", "banana", "rice", "apple", "pork", "banana", "pork", "rice", "pot", "banana", "apple", "banana"]	3
["apple"]									[10]		["banana", "banana", "banana", "banana", "banana", "banana", "banana", "banana", "banana", "banana"]							0

������Ÿ��
int solution(vector<string> want, vector<int> number, vector<string> discount)

*/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount)
{
	int totalDays = 0;
	int n = discount.size();
	unordered_map<string, int> wantMap;

	// want ����Ʈ�� �ʿ� ����
	for (int i = 0; i < want.size(); i++)
	{
		wantMap[want[i]] = number[i];
	}

	// ù 10�� ���� �� �ʱ�ȭ
	unordered_map<string, int> currentWindow;

	for (int i = 0; i < 10 && i < n; i++)
	{
		currentWindow[discount[i]]++;
	}

	auto matchesWant = [&]()
	{
		for (const auto& item : wantMap)
		{
			if (currentWindow[item.first] != item.second)
			{
				return false;
			}
		}
		return true;
	};

	if (matchesWant())
	{
		totalDays++;
	}

	for (int i = 10; i < n; i++)
	{
		currentWindow[discount[i]]++;
		currentWindow[discount[i - 10]]--;
		if (currentWindow[discount[i - 10]] == 0)
		{
			currentWindow.erase(discount[i - 10]);
		}

		if (matchesWant())
		{
			totalDays++;
		}
	}
	return totalDays;
}

int main() {
	vector<string> want1 = { "banana", "apple", "rice", "pork", "pot" };
	vector<int> number1 = { 3, 2, 2, 2, 1 };
	vector<string> discount1 = { "chicken", "apple", "apple", "banana", "rice", "apple", "pork", "banana", "pork", "rice", "pot", "banana", "apple", "banana" };
	cout << solution(want1, number1, discount1) << endl; // 3

	vector<string> want2 = { "apple" };
	vector<int> number2 = { 10 };
	vector<string> discount2 = { "banana", "banana", "banana", "banana", "banana", "banana", "banana", "banana", "banana", "banana" };
	cout << solution(want2, number2, discount2) << endl; // 0

	return 0;
}
