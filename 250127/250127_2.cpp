/*
문자열 해싱을 이용한 검색 함수 만들기

문자열 배열 string_list와 쿼리 배열 query_list가 있을 때 각 쿼리 배열에 있는 문자열이 string_list의 문자열 배열에 있는지 여부를 확인.
문자열이 있으면 true, 없으면 false가 됩니다. 각 문자열에 대해서 문자열의 존재 여부를 배열 형태로 반환하는 solution()함수 작성하라.

제약조건
1. 입력 문자열은 영어 소문자로만 이루어져 있음
2. 문자열의 최대 길이는 10^6
3. 해시 충돌은 고려하지 않음
4. 아래와 같은 문자열 해싱 방법을 활용해서 해싱 함수를 구현
5. 다음 식에서 p는 31, m은 1,000,000,007로 한다.
	- hash(s)=(s[0]+s[1]*p+s[2]*p^2 .....s[n-1]*p^n-1)mod m

입출력의 예
string_list						query_list							result
["apple","banana","cherry"]		["banana,"kiwi","melon","apple"]	[true, false, false, true]

프로토타입
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