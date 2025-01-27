/*
���ڿ� �ؽ��� �̿��� �˻� �Լ� �����

���ڿ� �迭 string_list�� ���� �迭 query_list�� ���� �� �� ���� �迭�� �ִ� ���ڿ��� string_list�� ���ڿ� �迭�� �ִ��� ���θ� Ȯ��.
���ڿ��� ������ true, ������ false�� �˴ϴ�. �� ���ڿ��� ���ؼ� ���ڿ��� ���� ���θ� �迭 ���·� ��ȯ�ϴ� solution()�Լ� �ۼ��϶�.

��������
1. �Է� ���ڿ��� ���� �ҹ��ڷθ� �̷���� ����
2. ���ڿ��� �ִ� ���̴� 10^6
3. �ؽ� �浹�� ������� ����
4. �Ʒ��� ���� ���ڿ� �ؽ� ����� Ȱ���ؼ� �ؽ� �Լ��� ����
5. ���� �Ŀ��� p�� 31, m�� 1,000,000,007�� �Ѵ�.
	- hash(s)=(s[0]+s[1]*p+s[2]*p^2 .....s[n-1]*p^n-1)mod m

������� ��
string_list						query_list							result
["apple","banana","cherry"]		["banana,"kiwi","melon","apple"]	[true, false, false, true]

������Ÿ��
vector<bool> solution(vector<string> string_list, vector<string> query_list)
	
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

long long polynomial_hash(const string& str)
{
	const int p = 31;
	const long long m = 1000000007;
	long long hash_value = 0;

	for (char c : str)
	{
		hash_value = (hash_value * p + c) % m;
	}
	return hash_value;
}

vector<bool> solution(vector<string> string_list, vector<string>query_list)
{
	unordered_set<long long> hash_set;

	for (const string& str : string_list)
	{
		long long hash = polynomial_hash(str);
		hash_set.insert(hash);
	}

	vector<bool> result;

	for (const string& query : query_list)
	{
		long long query_hash = polynomial_hash(query);
		bool found = (hash_set.find(query_hash) != hash_set.end());
		result.push_back(found);
	}

	return result;
}

#include <iterator>

void print(vector<bool> vec)
{
	copy(vec.begin(), vec.end(), ostream_iterator<bool>(cout, " "));
	cout << endl;
}

int main()
{
	print(solution({ "apple", "banana", "cherry" }, { "banana", "kiwi", "melon", "apple" }));

	return 0;
}