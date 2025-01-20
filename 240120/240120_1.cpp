/*
문제 12 주식 가격
초 단위로 기록된 주식 가격이 담긴 배열 prices가 매개변수로 주어질 때,
가격이 떨어지지 않은 기간은 몇 초인지를 반환하도록 solution()함수를 완성하세요.

제약조건
	- prices의 각 가격은 1이상 10,000이하인 자연수
	- prices의 길이는 2이상 100,000이하

입출력
	- 1초 시점의 W1은 끝까지 가격이 떨어지지 않았음
	- 2초 시점의 W2은 끝까지 가격 떨어지지 않음
	- 3초 시점의 W3은 1초 뒤에 가격이 떨어짐. 따라서 1초간 가격이 떨어지지 않은 것으로 봄
	- 4초 시점의 W2는 1초간 가격이 떨어지지 않았음
	- 5초 시점의 W3은 0초간 가격 떨어지지 않았음

프로토타입
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