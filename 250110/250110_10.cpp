#include <iostream>
#include <map>

using namespace std;

int main()
{
	map<int, string> myMap;

	// insert
	myMap.insert(make_pair(1, "Apple"));
	myMap.insert({ 2, "Banana" });
	myMap[3] = "Cherry";

	for (const auto& pair : myMap)
	{
		cout << pair.first << ": " << pair.second << endl;
	}

	// delete
	myMap.erase(2);
	
	for (const auto& pair : myMap)
	{
		cout << pair.first << ": " << pair.second << endl;
	}

	auto it = myMap.find(3);
	if (it != myMap.end())
	{
		myMap.erase(it);
	}

	// print map after delete
	for (const auto& pair : myMap)
	{
		cout << pair.first << ": " << pair.second << endl;
	}

	return 0;
}