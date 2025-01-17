/*
괄호 회전하기

다음 규칙을 지키는 문자열을 올바른 괄호 문자열이라고 함
	- "()", "[]", "{}"는 모두 올바른 괄호 문자열
	- 만약 A가 올바른 괄호 문자열이라면, "(A)", "[A]", "{A}"는 모두 올바른 괄호 문자열. "[]"가 올바른 괄호 문자열이므로, "([])"도 올바름
	- 만약 A, B가 올바른 괄호 문자열이라면, AB도 올바른 괄호 문자열. "{}", "([])"가 올바른 괄호 문자열 -> "{}([])"도 올바름

대괄호, 중괄호, 그리고 소괄호로 이루어진 문자열 s가 매개변수로 주어짐.
이 s를 왼쪽으로 x(0 <= x <(s의 길이))칸만큼 회전시켰을 때 s가 올바른 괄호 문자열이 되게 하는 x의 개수를 반환하는 solution 함수 완성

제약조건
	- s의 길이는 1이상 1,000이하

*/

#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>

using namespace std;

// 1. 닫힌 괄호의 짝 확인(map은 정렬됨, unorderedmap은 정렬 안됨)
unordered_map<char, char> bracketPair = { {')', '('}, {']', '['}, {'}', '{'} };

// 2.인수로 받은 문자열 기준 괄호의 짝이 맞는지 확인
bool isValid(string& s, int start)
{
	stack<int> stack;
	unsigned int sz = s.size();

	// 3. 문자열 순회
	for (int i = 0; i < sz; i++)
	{
		char ch = s[(start + i) % sz];

		// 4. ch가 닫힌 괄호의 경우
		if (bracketPair.count(ch))
		{
			// 5. 스택이 비었거나 top 원소가 ch와 짝이 맞는 열린괄호가 아니면 false 반환
			if (stack.empty() || stack.top() != bracketPair[ch])
			{
				return false;
			}
			// 6. ch와 짝이 맞는 열린 괄호면 해당 열린 괄호 제거
			stack.pop();
		}
		else
		{
			// 7. 열린 괄호면 스택에 푸시
			stack.push(ch);
		}
	}

	// 8. 스택이 비었으면 true를 반환(괄호짝 맞음)
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