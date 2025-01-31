#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

unordered_map<string, int> phoneBook;

bool isPrefix(const string& phoneNumber)
{
	string prefix = "";
	for (char digit : phoneNumber)
	{
		prefix += digit;

		if (phoneBook.find(prefix) != phoneBook.end() && prefix != phoneNumber)
		{
			return true;
		}
	}
	return false;
}

bool solution(vector<string> phoneNumbers)
{
	for (const string& phoneNumber : phoneNumbers)
	{
		phoneBook[phoneNumber] = 1;
	}

	for (const string& phoneNumber : phoneNumbers)
	{
		if (isPrefix(phoneNumber))
		{
			return false;
		}
	}
	return true;
}

int main()
{
	vector<string> case1 = { "119", "97674223", "1195524421" };
	vector<string> case2 = { "123", "456", "789" };
	vector<string> case3 = { "12", "123", "1235", "567", "88" };

	cout << (solution(case1) ? "True" : "False") << endl;
	cout << (solution(case2) ? "True" : "False") << endl;
	cout << (solution(case3) ? "True" : "False") << endl;

	return 0;
}