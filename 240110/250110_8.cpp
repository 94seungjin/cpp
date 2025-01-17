#include <iostream>
#include <map>

using namespace std;

int main()
{
	// ����
	map<string, int> studentScores;

	// Ű-�� pair �߰�
	studentScores["John"] = 98;
	studentScores["Johnson"] = 89;
	studentScores["JohnWick"] = 79;

	// []�����ڸ� ����Ͽ� Ű�� ���� - Ű�� �ִ� ���
	int score1 = studentScores["John"];
	cout << score1 << endl;

	// []�����ڸ� ����Ͽ� Ű�� ���� - Ű�� ���� ���
	int score2 = studentScores["Bob"];
	cout << score2 << endl;

	// find() �޼��带 ����ؼ� Ű�� ����
	auto it = studentScores.find("Johnson");
	if (it != studentScores.end())
	{
		int score3 = it->second;
		cout << score3 << endl;
	}

	return 0;
}