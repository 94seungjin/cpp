/*
완주하지 못한 선수

많은 선수 중 단 한 명의 선수를 제외하고 모든 선수가 마라톤을 완주하였습니다.
마라톤에 참여한 선수들의 이름이 담긴 배열 participant와 완주한 선수들의 이름이 담긴 배열 completion이 있을 때
완주하지 못한 선수의 이름을 반환하는 solution() 함수를 작성하세요.

제약조건
	- 마라톤 경기에 참여한 선수 수는 1명이상 100,000이하입니다.
	- completion 길이는  participant 길이보다 1작다.
	- 참가자 이름은 1개 이상 20개 이하의 알파벳 소문자로 이루어져 있다.
	- 참가자 중에는 동명이인이 있을 수 있음.

입출력의 예
participant											completion									result
["leo", "kiki", "eden"]								["eden", "kiki"]							"leo"
["marina", "josipa", "nikola", "vinko", "filipa"]	["josipa", "filipa", "mariana", "nikola"]	"vinko"
["mislav", "stanko", "mislab", "ana"]				["stanko", "ana", "mislav"]					"mislav"

프로토타입
string solution(vector<string> participant, vector<string> completion)


*/

#include <string>
#include <unordered_map>
#include <vector>
#include <iostream>

using namespace std;

string solution(vector<string> participant, vector<string> completion)
{
	unordered_map<string, int> participantHashtable;

	for (int i = 0; i < participant.size(); i++)
	{
		participantHashtable[participant[i]]++;
	}

	for (int i = 0; i < completion.size(); i++)
	{
		participantHashtable[completion[i]]--;

		if (participantHashtable[completion[i]] == 0)
		{
			participantHashtable.erase(participantHashtable.find(completion[i]));
		}
	}

	return participantHashtable.begin()->first;
}

int main() {
	vector<string> participant1 = { "leo", "kiki", "eden" };
	vector<string> completion1 = { "eden", "kiki" };
	cout << solution(participant1, completion1) << endl; // 결과: "leo"

	vector<string> participant2 = { "marina", "josipa", "nikola", "vinko", "filipa" };
	vector<string> completion2 = { "josipa", "filipa", "marina", "nikola" };
	cout << solution(participant2, completion2) << endl; // 결과: "vinko"

	vector<string> participant3 = { "mislav", "stanko", "mislav", "ana" };
	vector<string> completion3 = { "stanko", "ana", "mislav" };
	cout << solution(participant3, completion3) << endl; // 결과: "mislav"

	return 0;
}