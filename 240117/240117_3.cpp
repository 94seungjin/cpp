/*
10진수 -> 2진수

10진수 decimal을 입력받아 2진수로 변환해서 문자열 형태로 반환하는 solution() 함수를 구현해라

제약조건
	- x

입출력의 예
	10 -> 1010
	27 -> 11011
	12345 -> 11000000111001

프로토타입
string solution(int decimal)

분석
	- 일단 10진수 N을 2로 나눈 나머지가 2진수가 됨
	- 
*/

#include <iostream>
#include <stack>
#include <string>

using namespace std;

string solution(int decimal)
{
	// 1. 일단 입력값이 0인 경우 바로 0
	if (decimal == 0)
		return "0";

	stack<int> stack;
	while (decimal > 0)
	{
		// 2. 2로 나눈 나머지를 스택에 삽입
		stack.push(decimal % 2);
		decimal /= 2;
	}

	string binary = "";
	while (!stack.empty())
	{
		// 3. 스택에 차례대로 top()에 해당되는 값 binary에도 추가
		binary += to_string(stack.top());
		stack.pop();
	}
	return binary;
}

int main()
{
	cout << solution(10) << endl;
	cout << solution(27) << endl;
	cout << solution(12345) << endl;

	return 0;
}