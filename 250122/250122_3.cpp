/*
카드 뭉치

코니는 영어 단어가 적힌 카드 뭉치 2개를 선물로 받았습니다.
코니는 다음과 같은 규칙으로 카드에 적힌 단어들을 사용해 원하는 순서의 단어 배열을 만들 수 있는지 알고 싶음.
	- 원하는 카드 뭉치에서 카드를 순서대로 한 장씩 사용함
	- 한 번 사용한 카드는 다시 사용할 수 없음
	- 카드를 사용하지 않고 다음 카드로 넘어갈 수 없음
	- 기존에 주어진 카드 뭉치의 단어 순서는 바꿀 수 없음

입출력의 예
첫 번째 카드 뭉치(cards1)		두 번째 카드 뭉치(cards2)		goal									result
["i", "drink", "water"]			["want", "to"]					["i", "want", "to", "drink", "water"]	"Yes"
["i", "water", "drink"]			["want", "to"]					["i", "want", "to", "drink", "water"]	"No"

제약조건
1. 1 <= cards1의 길이, cards2의 길이 <= 10
	- 1 <= cards1[i]의 길이, cards2[i]의 길이 <= 10
	- cards1과 cards2에는 서로 다른 단어만 있음
2. 2 <= goal의 길이 <= cards1의 길이 + cards2의 길이
	- 1<= goal[i]의 길이 <= 10
	- goal의 원소는 cards1과 cards2의 원소들로만 이루어져 있음
3. cards1, cards2, goal의 문자열들을 모두 알파벳 소문자로만 이루어져 있음.

프로토타입
string solution(vector<string> cards1, vector<string> cards2, vector<string> goal)

*/

/*
1. goal의 front와 cards1 혹은 cards2의 front값과 비교
	1-1) 사용할 수 있는 카드가 있다면 해당 큐와 goal에서 각각 팝
	1-2) 사용할수 있는 카드가 없다면 아무 동작도 하지 않음
	1-3) cards1, cards2 중 빈 곳은 체크하지 않음
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