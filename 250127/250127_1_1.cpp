#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool solution(vector<int> arr, int target)
{
	unordered_set<int> seen;

	for (int num : arr)
	{
		int complement = target - num;

		if (seen.count(complement))
		{
			return true;
		}
		seen.insert(num);
	}
	return false;
}

int main()
{
	vector<int> arr1 = { 1,2,3,4,8 };
	int target1 = 6;
	cout << (solution(arr1, target1) ? "true" : "false") << endl;

	vector<int> arr2 = { 2,3,5,9 };
	int target2 = 10;
	cout << (solution(arr2, target2) ? "true" : "false") << endl;

	return 0;
}