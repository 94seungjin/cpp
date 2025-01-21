/*
짝지어 제거하기

알파벳 소문자로 구성된 문자열에서 같은 알파벳이 2개 붙어 있는 짝을 찾는다.
짝을 찾은 다음에는 그 둘을 제거한 뒤 앞뒤로 문자열을 이어붙인다.
이 과정을 반복해서 문자열을 모두 제거한다면 짝지어 제거하기가 종료.
문자열 S가 주어졌을 때 짝지어 제거하기를 성공적으로 수행할 수 있는지 반환하는 함수를 완성
성공적으로 수행할 수 있으면 1을, 아니면 0을 반환해주면됨
예를 들어 문자열 S가 baabaa -> bbaa -> aa 순서로 문자열을 모두 제거할 수 있으므로 1을 반환

제약 조건
	- 문자열의 길이 : 1,000,000이하의 자연수
	- 문자열을 모두 소문자로 이루어져 있다.

프로토타입
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