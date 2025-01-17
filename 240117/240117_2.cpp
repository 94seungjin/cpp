/*
괄호 짝 맞추기

소괄호는 짝을 맞춘 열린 괄호 '('와 닫힌 괄호')'로 구성.
문제에서는 열린 괄호나 닫힌 괄호가마구 뒤섞인 문자열 s를 줌
이때 소괄호가 정상으로 열고 닫혔는지 판별하는 solution()함수를 구현.
만약 소괄호가 정상적으로 열고 닫혔다면 true, 그렇지 않다면 false 반환

제약조건
	- 열린 괄호는 자신과 가장 가까운 닫힌 괄호를 만나면 상쇄
	- 모든 괄호가 상세되어 더 이상 아무 괄호도 없어야맍 ㅓㅇ상으로 열고 닫혔다고 할 수 있음
	- 더 상쇄할 괄호가 없을 때까지 상쇄를 반복

입출력의 예
	
*/

#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
	stack<int> stack;
	char c;

	for (char c : s)
	{
		// 1. '(' 괄호 나올 경우, 스택에 푸시
		if (c == '(')
		{
			stack.push(c);
		}
		else if (c == ')')
		{
			// 2. ')' 괄호가 나올 경우, 스택이 비어있는지 확인
			if (stack.empty())
			{
				// 3. 스택이 비어있다면 괄호 짝 맞지 않음 -> false 반환
				return false;
			}
			else
			{
				// 4. 스택이 비어있지 않다면 pop연산
				stack.pop();
			}
		}
	}
	// 5. 스택이 비어있다면 괄호 잘 닫힌것 -> true 반환, 아니라면 false
	return stack.empty();
}

int main()
{
	cout << solution("(())()") << endl;
	cout << solution("((())()") << endl;

	return 0;
}