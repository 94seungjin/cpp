/*
 ���� ä�ù�
 īī���� ���� ä�ù濡���� ģ���� �ƴ� ������ ��ȭ�� �� �� �ִµ� ���� �г����� �ƴ� ������ �г����� ����� ä�ù濡 �� �� �ִ�.
 ���Ի���� ��ũ��� ī�� ���� ä�ù��� ������ ����� ���� �پ��� ������� ������ ������ ���� ���Ѻ� �� �ִ� ������ â�� �������ߴ�.
 ���� ��� ä�ù濡 �������� ������ ���� �޽����� ��µ�.
 "[�г���]���� ���Խ��ϴ�."
 ä�ù濡�� ������ ������ ���� �޽����� ��µ�.
 "[�г���]���� �������ϴ�."
 ä�ù濡�� �г����� �����ϴ� ����� ������ ���� �� ������.
 - ä�ù��� ���� ��, ���ο� �г������� �ٽ� ����.
 - ä�ù濡�� �г����� �����Ѵ�.
 �г����� ������ ���� ������ ä�ù濡 ��µǾ� �ִ� �޽����� �г��ӵ� ���� �ٲ��.
 ���� ��� ä�ù濡 Muzi�� Prodo��� �г����� ����ϴ� ����� ������� ������ ä�ù濡�� ������ ���� �޽����� ��µȴ�.
 - "Muzi���� ���Խ��ϴ�."
 - "Prodo���� ���Խ��ϴ�."
 ä�ù濡 �ִ� ����� ������ ä�ù濡�� ������ ���� �޽����� �����ϴ�.
 - "Muzi���� ���Խ��ϴ�."
 - "Prodo���� ���Խ��ϴ�."
 - "Muzi���� �������ϴ�."
 Muzi�� ���� �� �ٽ� ���� ��, Prodo��� �г������� ���� ��� ������ ä�ù濡 ���� �ִ� Muzi�� Prodo�� ������ ���� ����ȴ�.
 - "Prodo���� ���Խ��ϴ�."
 - "Prodo���� ���Խ��ϴ�."
 - "Prodo���� �������ϴ�."
 - "Prodo���� ���Խ��ϴ�."
 ä�ù��� �ߺ� �г����� ����ϹǷ� ���� ä�ù濡�� Prodo��� �г����� ����ϴ� ����� �θ��Դϴ�. ���� �� ó�� ä�ù濡 �� ��°�� ���Դ� Prodo�� Ryan���� �г����� �����ϸ� ä�ù� �޽����� ������ ���� ����ȴ�.
 - "Prodo���� ���Խ��ϴ�."
 - "Ryan���� ���Խ��ϴ�."
 - "Prodo���� �������ϴ�."
 - "Prodo���� ���Խ��ϴ�."
 ä�ù濡 ������ �����ų� �г����� ������ ����� ��� ���ڿ� �迭 record�� �Ű������� �־��� �� ��� ����� ó���� ���� �������� ���� ������ ����� ���� �޽����� ���ڿ� �迭 ���·� ��ȯ�ϴ� solution()�Լ��� �ϼ��ض�.
 
 ��������
 - record�� ������ ���� ���ڿ��� ��� �迭�̸� ���̴� 1�̻� 100,000����
 ������ record�� ��� ���ڿ��� ���� ����
 - ��� ������ [���� ���̵�]�� ����
 - [���� ���̵�] ����ڰ� [�г���]���� ä�ù濡 ����
 - "Enter[���� ���̵�][�г���]"(�� : "Enter ui1234 Muzi")
 - [���� ���̵�] ����ڰ� ä�ù濡�� ����
 - "Leave[���� ���̵�]"(�� : "Leave uid1234")
 - [���� ���̵�]����ڰ� �г�����[�г���]���� ����
 - "Change[���� ���̵�][�г���]"(�� : "Change uid1234 Muzi")
 - ù �ܾ�� Enter, Leave, Change �� �ϳ�
 - �� �ܾ�� �������� ���еǾ� ������, ���ĺ� �빮��, �ҹ���, ���ڷθ� �̷����
 - ���� ���̵�� �г����� ���ĺ� �빮��, �ҹ��ڸ� ����
 - ���� ���̵�� �г����� ���̴� 1�̻� 10����
 - ä�ù濡�� ���� ������ �г����� �����ϴ� �� �߸��� �Է��� �־����� ����.
 
 ������� ��
 record																											result
 ["Enter uid1234 Muzi", "Enter uid4567 Prodo", "Leave uid1234", "Enter uid1234 Prodo", "Change uid4567 Ryan"]	["Prodo���� ���Խ��ϴ�.", "Ryan���� ���Խ��ϴ�.", "Prodo���� �������ϴ�.", "Prodo���� ���Խ��ϴ�."]

 ������Ÿ��
 vector<string> solution(vector<string> record)

*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <iterator>

using namespace std;

vector<string> solution(vector<string> record)
{
	vector<string> answer;
	unordered_map<string, string> userId;

	for (const auto& line : record)
	{
		stringstream ss(line);
		string cmd;
		string id;
		string nickname;
		ss >> cmd >> id;

		if (cmd != "Leave")
		{
			ss >> nickname;
			userId[id] = nickname;
		}
	}

	for (const auto& line : record)
	{
		stringstream ss(line);
		string cmd, id;
		ss >> cmd >> id;

		if (cmd == "Enter")
		{
			answer.push_back(userId[id] + "���� ���Խ��ϴ�.");
		}
		else if (cmd == "Leave")
		{
			answer.push_back(userId[id] + "���� �������ϴ�.");
		}
	}

	return answer;
}

void print(vector<string> vec)
{
	copy(vec.begin(), vec.end(), std::ostream_iterator<string>(cout, " "));
	cout << endl;
}

int main()
{
	print(solution({ "Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234", "Enter uid1234 Prodo","Change uid4567 Ryan" }));	  

	return 0;
}