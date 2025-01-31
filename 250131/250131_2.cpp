#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

string solution(vector<string> participant, vector<string> completion)
{
	sort(participant.begin(), participant.end());
	sort(completion.begin(), completion.end());

	for (int i = 0; i < completion.size(); i++)
	{
		if (participant[i] != completion[i])
		{
			return participant[i];
		}
	}

	return participant[participant.size() - 1];
}

int main()
{
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
