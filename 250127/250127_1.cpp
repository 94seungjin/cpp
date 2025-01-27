/*
�� ���� ���� Ư�� �� �����

n���� ���� ������ �̷���� �迭 arr�� ���� target�� �־����� �� �� �߿��� ���� target�� �� ���� arr�� �ִ��� ã��,
������ true, ������ false�� ��ȯ�ϴ� solution()�Լ��� �ۼ��϶�

���� ����
1. n�� 2�̻� 10,000������ �ڿ���
2. arr�� �� ���Ҵ� 1�̻� 10,000������ �ڿ���
3. arr�� ���� �� �ߺ��Ǵ� ���Ҵ� ����
4. target�� 1�̻� 20,000������ �ڿ���

������� ��
arr				target			result
[1,2,3,4,8]		6				true
[2,3,5,9]		10				false

������Ÿ��
bool solution(vector<int> arr, int target)

*/

#include <iostream>
#include <vector>

using namespace std;

// mapping �Լ� �����(vector�� int���� hash, vector�� int���� arr, int target)
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
	vector<int> hash(target + 1, 0);	// ��� ���� ���� ����
	mapping(hash, arr, target);

	for (int i = 0; i < arr.size(); i++)
	{
		int num = target - arr[i];		
		if (arr[i] == num)				// ���� �� �ι� ����
			continue;
		if (num < 0)					// ���� �� ���� x
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