/*
전화번호 목록

전화번호부에 적힌 전화번호 중 한 번호가 다른 번호의 접두어인 경우가 있는지 확인하려 합니다.
전화번호가 다음과 같을 경우 구조대 전화번호는 영석이 전화번호 접두사입니다.
	- 구조대 : 119
	- 박준영 : 97 674 223
	- 지영석 : 11 9952 4421

전화번호부에 적힌 전화번호를 담은 배열 phone_book이 solution()함수의 매개변수로 주어질 때 어떤 번호가 다른 번호의
접두어이면 False, 그렇지 않으면 True를 반환하는 solution()함수를 작성해주세요.

제약 조건
1. phone_book의 길이는 1이상 1,000,000이하입니다.
	- 각 전화번호의 길이는 1이상 20이하
	- 같은 전화번호가 중복해서 들어 있지 않음.

입출력의 예
phone_book							result
["119", "97674223", "1195524421"]	False
["123", "456", "789"]				True
["12", "123", "1235", "567", "88"]	False

프로토타입
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