#include <string>
#include <unordered_set>
#include <iostream>

using namespace std;

int main()
{
	unordered_set<string> set;

	auto result = set.insert("apple");

	result = set.insert("apple");

	result = set.insert("banana");

	return 0;
}