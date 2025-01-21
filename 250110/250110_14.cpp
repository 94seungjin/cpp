#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> v = { 4,2,3,5,1 };

	sort(v.begin(), v.end());

	sort(v.rbegin(), v.rend());

	return 0;
}