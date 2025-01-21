#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> v = { 2,3,4,5 };

	v.insert(v.begin(), 1);	// v: {1,2,3,4,5}
	v.erase(v.begin());	// v: {2,3,4,5}

	return 0;
}