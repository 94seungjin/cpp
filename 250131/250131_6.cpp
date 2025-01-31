#include <iostream>
#include <string>

using namespace std;

int main()
{
	string example = "Hello, World!";

	string sub2 = example.substr(7);
	string sub1 = example.substr(7, 5);
	string sub3 = example.substr(0, 5);

	string sub4 = example.substr(15, 5);

	return 0;
}