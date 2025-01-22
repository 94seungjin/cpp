/*
ī�� ��ġ

�ڴϴ� ���� �ܾ ���� ī�� ��ġ 2���� ������ �޾ҽ��ϴ�.
�ڴϴ� ������ ���� ��Ģ���� ī�忡 ���� �ܾ���� ����� ���ϴ� ������ �ܾ� �迭�� ���� �� �ִ��� �˰� ����.
	- ���ϴ� ī�� ��ġ���� ī�带 ������� �� �徿 �����
	- �� �� ����� ī��� �ٽ� ����� �� ����
	- ī�带 ������� �ʰ� ���� ī��� �Ѿ �� ����
	- ������ �־��� ī�� ��ġ�� �ܾ� ������ �ٲ� �� ����

������� ��
ù ��° ī�� ��ġ(cards1)		�� ��° ī�� ��ġ(cards2)		goal									result
["i", "drink", "water"]			["want", "to"]					["i", "want", "to", "drink", "water"]	"Yes"
["i", "water", "drink"]			["want", "to"]					["i", "want", "to", "drink", "water"]	"No"

��������
1. 1 <= cards1�� ����, cards2�� ���� <= 10
	- 1 <= cards1[i]�� ����, cards2[i]�� ���� <= 10
	- cards1�� cards2���� ���� �ٸ� �ܾ ����
2. 2 <= goal�� ���� <= cards1�� ���� + cards2�� ����
	- 1<= goal[i]�� ���� <= 10
	- goal�� ���Ҵ� cards1�� cards2�� ���ҵ�θ� �̷���� ����
3. cards1, cards2, goal�� ���ڿ����� ��� ���ĺ� �ҹ��ڷθ� �̷���� ����.

������Ÿ��
string solution(vector<string> cards1, vector<string> cards2, vector<string> goal)

*/

/*
1. goal�� front�� cards1 Ȥ�� cards2�� front���� ��
	1-1) ����� �� �ִ� ī�尡 �ִٸ� �ش� ť�� goal���� ���� ��
	1-2) ����Ҽ� �ִ� ī�尡 ���ٸ� �ƹ� ���۵� ���� ����
	1-3) cards1, cards2 �� �� ���� üũ���� ����
*/

#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal)
{
	queue<string> c1, c2, g;

	for (const string& s : cards1)
		c1.push(s);
	for (const string& s : cards2)
		c2.push(s);
	for (const string& s : goal)
		g.push(s);

	while (!g.empty())
	{
		if (!c1.empty() && c1.front() == g.front())
		{
			c1.pop();
			g.pop();
		}
		else if (!c2.empty() && c2.front() == g.front())
		{
			c2.pop();
			g.pop();
		}
		else
		{
			break;
		}
	}

	return g.empty() ? "Yes" : "No";
}

int main()
{
	cout << solution({ "i", "drink", "water" }, { "want", "to" }, { "i", "want", "to", "drink", "water" }) << endl; // "Yes"
	cout << solution({ "i", "water", "drink" }, { "want", "to" }, { "i", "want", "to", "drink", "water" }) << endl; // "No"
	return 0;

}