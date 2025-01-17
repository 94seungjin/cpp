#include <iostream>
#include <stack>

using namespace std;

int main()
{
	stack<int> stack;

	stack.push(10);
	stack.push(20);
	stack.push(30);

	while (!stack.empty())
	{
		cout << stack.top() << " ";
		stack.pop();
	}

	cout << endl;

	return 0;
}