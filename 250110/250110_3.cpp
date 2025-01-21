#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> v = { 2,3,4,5 };

	v.push_back(6);
	v.pop_back();

	return 0;
}