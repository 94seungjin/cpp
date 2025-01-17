#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array)
{
	sort(array.begin(), array.end());

	return array;
}

void print(vector<int> vec)
{
	copy(vec.begin(), vec.end(), std::ostream_iterator<int>(cout, " "));
	cout << endl;
}

int main()
{
	print(solution({ 1, -5, 2, 4, 3 }));
	print(solution({ 2, 1, 1, 3, 2, 5, 4 }));
	print(solution({ 6, 1, 7 }));

	return 0;
}