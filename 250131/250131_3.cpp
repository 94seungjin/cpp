/*
���� �����ձ�

1���� n���� ��Ȥ �پ� �ִ� n���� ����� ���� �����ձ⸦ �մϴ�. ���� �����ձ�� ������ ���� ��Ģ���� ����˴ϴ�.
1. 1������ ��ȣ ������� �� ����� �ܾ ���Ѵ�
2. ������ ����� �ܾ ���� �������� �ٽ� 1������ ������
3. �ջ���� ���� �ܾ��� ������ ���ڷ� �����ϴ� �ܾ ���ؾ� ��
4. ������ �����ߴ� �ܾ�� ����� �� ����
5. �� ������ �ܾ�� �������� ����.

������ 3���� �����ձ⸦ �ϴ� ��Ȳ�� ��Ÿ��.
	- tank -> kick -> know -> wheel -> land -> dream -> mother -> robot -> tank
���� �����ձ�� ������ ���� ����˴ϴ�.
	- 1�� ����� �ڽ��� ù ��° ���ʿ� tank�� ����
	- 2�� ����� �ڽ��� ù ��° ���ʿ� kick�� ����
	- 3�� ����� �ڽ��� ù ��° ���ʿ� know�� ����
	- 1�� ����� �ڽ��� �� ��° ���ʿ� wheel�� ����
	- (��� ����)
�����ձ⸦ ��� �����ϴ� ���� 3�� ����� ���� tank�� ������ �����ߴ� �ܾ��̹Ƿ� Ż��.
��� �� n�� ������� ������� ���� �ܾ� words�� �Ű������� �־����� �� ���� ���� Ż���ϴ� ����� ��ȣ�� �� �����
�ڽ��� �� ��° ���ʿ� Ż���ߴ��� ��ȯ�ϴ� solution()�Լ��� �ϼ�

���� ����
	- �����ձ⿡ �����ϴ� ����� �� n�� 2�̻� 10������ �ڿ���
	- words�� �����ձ⿡ ����� �ܾ���� ������� ��� �ִ� �迭, ���̴� n�̻� 100����
	- �ܾ��� ���̴� 2�̻� 50����
	- ��� �ܾ�� ���ĺ� �ҹ��ڷθ� �̷���� ����
	- �����ձ⿡ ���Ǵ� �ܾ��� ��(�ǹ�)�� �Ű� ���� �ʾƵ� ��
	- ������ [��ȣ, ����] ���·� ��ȯ
	- ���� �־��� �ܾ��� Ż���ڰ� ������ �ʴ´ٸ� [0,0]�� ��ȯ

������� ��
n	words																			result
3	["tank", "kick", "know", "wheel", "land", "dream", "mother", "robot", "tank"]	[3, 3]
5	["hello", "observe", "effect", "take", "either", "recognize", "encourage", "ensure", "establish", "hang", "gather", "refer", "reference", "estimate", "executive"]	[0,0]
2	["hello", "one", "even", "never", "now", "world", "draw"]						[1, 3]

������Ÿ��
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
