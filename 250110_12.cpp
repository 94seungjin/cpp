#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
	unordered_map<string, int> myUnorderedmap;

	// »ğÀÔ
	myUnorderedmap["apple"] = 3;
	myUnorderedmap["banana"] = 1;
	myUnorderedmap["cherry"] = 4;
	myUnorderedmap["date"] = 2;

	for (const auto& pair : myUnorderedmap)
	{
		cout << pair.first << ": " << pair.second << endl;
	}

	return 0;
}