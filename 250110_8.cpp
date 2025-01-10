#include <iostream>
#include <map>

using namespace std;

int main()
{
	// 생성
	map<string, int> studentScores;

	// 키-값 pair 추가
	studentScores["John"] = 98;
	studentScores["Johnson"] = 89;
	studentScores["JohnWick"] = 79;

	// []연산자를 사용하여 키에 접근 - 키가 있는 경우
	int score1 = studentScores["John"];
	cout << score1 << endl;

	// []연산자를 사용하여 키에 접근 - 키가 없는 경우
	int score2 = studentScores["Bob"];
	cout << score2 << endl;

	// find() 메서드를 사용해서 키에 접근
	auto it = studentScores.find("Johnson");
	if (it != studentScores.end())
	{
		int score3 = it->second;
		cout << score3 << endl;
	}

	return 0;
}