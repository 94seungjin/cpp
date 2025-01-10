#include <iostream>
#include <vector>

using namespace std;

double get_average(const vector<int>& array, int N)
{
	if (array.empty())
	{
		return -1;
	}

	if (N == 0)
	{
		return -1;
	}

	int sum = 0;
	for (int num : array)
	{
		sum += num;
	}

	return sum / N;
}