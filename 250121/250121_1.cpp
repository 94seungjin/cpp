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
		cout << q.front() << "을 큐에서 삭제했습니다." << endl;
		q.pop();
	}

	cout << "큐가 비었나요?" << (q.empty() ? "Yes" : "No") << endl;

	return 0;
}