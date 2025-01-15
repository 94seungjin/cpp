#include <vector>
#include <algorithm>

using namespace std;

bool compare(int a, int b)
{
	return a > b;
}

vector<int> solution(vector<int> lst)
{
	sort(lst.begin(), lst.end(), compare);
	lst.erase(unique(lst.begin(), lst.end()), lst.end());

	return lst;
}

#include <iostream>
#include <iterator>

void print(vector<int> vec)
{
	copy(vec.begin(), vec.end(), std::ostream_iterator<int>(cout, " "));
	cout << endl;
}

int main()
{
	print(solution({ 4,2,2,1,1,3,4 }));
	print(solution({ 2,1,1,3,2,5,4 }));

	return 0;
}