#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> vector = { 1,2,3,4,3,5,3 };

	int ret = count(vector.begin(), vector.end(), 3);
	cout << ret << endl;

	return 0;
}