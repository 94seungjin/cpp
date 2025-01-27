/*
두 개의 수로 특정 값 만들기

n개의 양의 정수로 이루어진 배열 arr와 정수 target이 주어졌을 때 이 중에서 합이 target인 두 수가 arr에 있는지 찾고,
있으면 true, 없으면 false를 반환하는 solution()함수를 작성하라

제약 조건
1. n은 2이상 10,000이하의 자연수
2. arr의 각 원소는 1이상 10,000이하의 자연수
3. arr의 원소 중 중복되는 원소는 없음
4. target은 1이상 20,000이하의 자연수

입출력의 예
arr				target			result
[1,2,3,4,8]		6				true
[2,3,5,9]		10				false

프로토타입
bool solution(vector<int> arr, int target)

*/

#include <iostream>
#include <vector>

using namespace std;

// mapping 함수 만들기(vector에 int형인 hash, vector에 int형인 arr, int target)
void mapping(vector<int>& hash, const vector<int>& arr, int target)
{
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i] > target)
			continue;
		hash[arr[i]] = 1;
	}
}

bool solution(vector<int> arr, int target)
{
	vector<int> hash(target + 1, 0);	// 모든 가능 숫자 범위
	mapping(hash, arr, target);

	for (int i = 0; i < arr.size(); i++)
	{
		int num = target - arr[i];		
		if (arr[i] == num)				// 동일 값 두번 금지
			continue;
		if (num < 0)					// 음수 값 존재 x
			continue;
		if (hash[num])
			return true;
	}

	return false;
}

int main()
{
	cout << solution({ 1, 2, 3, 4, 8 }, 6) << endl;
	cout << solution({ 2, 3, 5, 9 }, 10) << endl;

	return 0;
}