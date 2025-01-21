#include <iostream>
#include <queue>

using namespace std;

int main()
{
	queue<int> q;

	q.push(10);
	q.push(20);
	q.push(30);

	cout << "Front : " << q.front() << endl;

	while (!q.empty())
	{
		cout << q.front() << "�� ť���� �����߽��ϴ�." << endl;
		q.pop();
	}

	cout << "ť�� �������?" << (q.empty() ? "Yes" : "No") << endl;

	return 0;
}