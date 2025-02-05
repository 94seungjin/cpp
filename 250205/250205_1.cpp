/*
할인 행사

XYZ마트는 일정 금액을 지불하면 10일 동안 회원 자격을 부여합니다.
XYZ마트에서는 회원을 대상으로 매일 1가지 제품을 할인하는 행사를 한다.
할인 제품은 하루에 하나만 구매할 수 있다.
알뜰한 정현이는 자신이 원하는 제품과 수량이 할인하는 날짜와 10일 연속으로 일치할 때에 맞춰서 회원가입을 하려고 한다.
예를 들어 정현이가 원하는 제품이 바나나 3개, 사과 2개, 쌀 2개, 돼지고기 2개, 냄비 1개이고, XYZ마트에서 14일간 회원을
대상으로 할인하는 제품이 날짜 순서대로 치킨, 사과, 사과, 바나나, 쌀, 사과, 돼지고기, 바나나, 돼지고기 쌀, 냄비, 바나나,
사과, 바나나면 첫째 날부터 열흘 동안은 냄비는 할인하지 않으므로 첫째 날에는 회원가입을 하지 않는다.
둘째 날부터 열흘 동안은 바나나를 원하는 만큼 할인 구매할 수 없으므로 둘째 날에도 회원가입을 하지 않습니다.
셋째, 넷째, 다섯째 날부터 각각 열흘 동안은 원하는 제품과 수량이 일치하므로 셋 중 하루에 회원가입을 한다.

정현이가 원하는 제품을 나타내는 문자열 배열 want와 정현이가 원하는 제품의 수량을 나타내는 정수 배열 number, XYZ마트에서 할인하는 제품을
나타내는 문자열 배열 discount가 있을 때 회원가입 시 정현이가 원하는 제품을 모두 할인받을 수 있는 회원 등록 날짜의 총 일수를 반환하는
solution()함수를 완성하라. 가능한 날이 없으면 0을 return한다.

제약조건
1<=want의 길이 = number의 길이 <= 10
	- 1 <= number의 원소 <= 10
	- number[i]는 want[i]의 수량
	- number의 총합 10
10<=discount의 길이 <= 100,000
want와 discount의 원소들은 알파벳 소문자로 이루어진 문자열
	- 1<=want의 원소와 길이, discount의 원소의 길이 <=12

입출력의 예
want										number		discount																														result
["banana", "apple", "rice", "pork", "pot"]	[3,2,2,2,1]	["chicken", "apple", "apple", "banana", "rice", "apple", "pork", "banana", "pork", "rice", "pot", "banana", "apple", "banana"]	3
["apple"]									[10]		["banana", "banana", "banana", "banana", "banana", "banana", "banana", "banana", "banana", "banana"]							0

프로토타입
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

	// want 리스트를 맵에 저장
	for (int i = 0; i < want.size(); i++)
	{
		wantMap[want[i]] = number[i];
	}

	// 첫 10일 구간 맵 초기화
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
