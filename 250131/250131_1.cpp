/*
�������� ���� ����

���� ���� �� �� �� ���� ������ �����ϰ� ��� ������ �������� �����Ͽ����ϴ�.
�����濡 ������ �������� �̸��� ��� �迭 participant�� ������ �������� �̸��� ��� �迭 completion�� ���� ��
�������� ���� ������ �̸��� ��ȯ�ϴ� solution() �Լ��� �ۼ��ϼ���.

��������
	- ������ ��⿡ ������ ���� ���� 1���̻� 100,000�����Դϴ�.
	- completion ���̴�  participant ���̺��� 1�۴�.
	- ������ �̸��� 1�� �̻� 20�� ������ ���ĺ� �ҹ��ڷ� �̷���� �ִ�.
	- ������ �߿��� ���������� ���� �� ����.

������� ��
participant											completion									result
["leo", "kiki", "eden"]								["eden", "kiki"]							"leo"
["marina", "josipa", "nikola", "vinko", "filipa"]	["josipa", "filipa", "mariana", "nikola"]	"vinko"
["mislav", "stanko", "mislab", "ana"]				["stanko", "ana", "mislav"]					"mislav"

������Ÿ��
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
	cout << solution(participant1, completion1) << endl; // ���: "leo"

	vector<string> participant2 = { "marina", "josipa", "nikola", "vinko", "filipa" };
	vector<string> completion2 = { "josipa", "filipa", "marina", "nikola" };
	cout << solution(participant2, completion2) << endl; // ���: "vinko"

	vector<string> participant3 = { "mislav", "stanko", "mislav", "ana" };
	vector<string> completion3 = { "stanko", "ana", "mislav" };
	cout << solution(participant3, completion3) << endl; // ���: "mislav"

	return 0;
}