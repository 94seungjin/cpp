#include <iostream>
#include <map>

using namespace std;

int main()
{
	map<string, int> myMap = { {"Apple", 1}, {"Banana", 2}, {"Grape", 3} };

	myMap["Banana"] = 10;

	return 0;
}