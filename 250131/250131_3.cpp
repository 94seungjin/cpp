/*
영어 끝말잇기

1부터 n까지 번혹 붙어 있는 n명의 사람이 영어 끝말잇기를 합니다. 영어 끝말잇기는 다음과 같은 규칙으로 진행됩니다.
1. 1번부터 번호 순서대로 한 사람씩 단어를 말한다
2. 마지막 사람이 단어를 말한 다음에는 다시 1번부터 시작함
3. 앞사람이 말한 단어의 마지막 문자로 시작하는 단어를 말해야 함
4. 이전에 등장했던 단어는 사용할 수 없음
5. 한 글자인 단어는 인정되지 않음.

다음은 3명이 끝말잇기를 하는 상황을 나타냄.
	- tank -> kick -> know -> wheel -> land -> dream -> mother -> robot -> tank
위의 끝말잇기는 다음과 같이 진행됩니다.
	- 1번 사람이 자신의 첫 번째 차례에 tank를 말함
	- 2번 사람이 자신의 첫 번째 차례에 kick을 말함
	- 3번 사람이 자신의 첫 번째 차례에 know를 말함
	- 1번 사람이 자신의 두 번째 차례에 wheel을 말함
	- (계속 진행)
끝말잇기를 계속 진행하다 보면 3번 사람이 말한 tank는 이전에 등장했던 단어이므로 탈락.
사람 수 n과 사람들이 순서대로 말한 단어 words가 매개변수로 주어졌을 때 가장 먼저 탈락하는 사람의 번호와 그 사람이
자신의 몇 번째 차례에 탈락했는지 반환하는 solution()함수를 완성

제약 조건
	- 끝말잇기에 참여하는 사람의 수 n은 2이상 10이하의 자연수
	- words는 끝말잇기에 사용한 단어들이 순서대로 들어 있는 배열, 길이는 n이상 100이하
	- 단어의 길이는 2이상 50이하
	- 모든 단어는 알파벳 소문자로만 이루어져 있음
	- 끝말잇기에 사용되는 단어의 뜻(의미)은 신경 쓰지 않아도 됨
	- 정답은 [번호, 차례] 형태로 반환
	- 만약 주어진 단어들로 탈락자가 생기지 않는다면 [0,0]을 반환

입출력의 예
n	words																			result
3	["tank", "kick", "know", "wheel", "land", "dream", "mother", "robot", "tank"]	[3, 3]
5	["hello", "observe", "effect", "take", "either", "recognize", "encourage", "ensure", "establish", "hang", "gather", "refer", "reference", "estimate", "executive"]	[0,0]
2	["hello", "one", "even", "never", "now", "world", "draw"]						[1, 3]

프로토타입
vector<int> solution(int n, vector<string> words)

*/

#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

vector<int> solution(int n, vector<string> words)
{
	vector<int> answer(2, 0);
	unordered_set<string> usedWords;

	usedWords.insert(words[0]);

	for (int i = 1; i < words.size(); i++)
	{ 
		if (!usedWords.insert(words[i]).second || words[i].front() != words[i - 1].back())
		{
			answer[0] = i % n + 1;
			answer[1] = i / n + 1;

			return answer;
		}
	}
	return answer;
}


int main()
{
	vector<string> words1 = { "tank", "kick", "know", "wheel", "land", "dream", "mother", "robot", "tank" };
	vector<string> words2 = { "hello", "observe", "effect", "take", "either", "recognize", "encourage", "ensure", "establish", "hang", "gather", "refer", "reference", "estimate", "executive" };
	vector<string> words3 = { "hello", "one", "even", "never", "now", "world", "draw" };

	vector<int> result1 = solution(3, words1);
	cout << "[" << result1[0] << ", " << result1[1] << "]" << endl; // [3, 3]

	vector<int> result2 = solution(5, words2);
	cout << "[" << result2[0] << ", " << result2[1] << "]" << endl; // [0, 0]

	vector<int> result3 = solution(2, words3);
	cout << "[" << result3[0] << ", " << result3[1] << "]" << endl; // [1, 3]

	return 0;
}
