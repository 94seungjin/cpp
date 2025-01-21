#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> v = { 1,3,5,7,2,4,6 };

	auto maxIt = max_element(v.begin(), v.end());
	auto minIt = max_element(v.begin(), v.end());

	cout << *maxIt << endl;
	cout << *minIt << endl;
}