/*
��ɰ���

���α׷��ӽ��������� ��� ���� �۾��� ���� ���Դϴ�. �� ����� ������ 100%�� �� ���񽺿� �ݿ��� �� ����.
��, �� ����� ���� �ӵ��� ��� �ٸ��Ƿ� ���� ����� ���� ��ɺ��� ���� ���ߵ� ���� ����.
�̶�, ���� ����� ���� ����� ������ �� �Բ� �����Ǿ�� ��.
���� ������� �۾� ������ ���� ���� �迭 progresses�� �� �۾��� ���� �ӵ��� ���� ���� �迭 speeds�� �־��� �� �� ��������
�� ���� ����� �����Ǵ����� ��ȯ�ϵ��� solution()�Լ��� �ϼ��϶�.

���� ����
	- �۾� ����(progresses, speeds�� �迭 ����)�� 100�� ����
	- �۾� ������ 100�̸��� �ڿ���.
	- �۾� �ӵ��� 100������ �ڿ���
	- ������ �Ϸ翡 �� ���� �� �� ������, �Ϸ��� ���� �̷�����ٰ� ����. ���� ��� �������� 95%�� �۾��� ���� �ӵ���
	�Ϸ翡 4%��� ������ 2�� �ڿ� �̷����.

������� ��
progresses			speeds			return
[93, 30, 55]		[1,30,5]		[2,1]
[95,90,99,99,80,99]	[1,1,1,1,1,1]	[1,3,2]

������Ÿ��
vector<int> solution(vector<int> progresses, vector<int>speeds)
*/

/*
1. �� ������� ť�� Ǫ��
2. �� -> �۾� �Ϸ� �˻� -> �Ϸ� x -> Ǫ�� -> 100�� �Ǿ� ���� ������ Ǫ��(�ݺ���)
3. 
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> days; // �۾��� �Ϸ���� �ʿ��� �ϼ�

    // �� �۾��� �Ϸ� �ϼ� ���
    for (size_t i = 0; i < progresses.size(); i++)
    {
        int remaining = 100 - progresses[i];
        int required_days = (remaining + speeds[i] - 1) / speeds[i]; // �ø� ���
        days.push(required_days);
    }

    while (!days.empty())
    {
        int current = days.front();
        days.pop();
        int count = 1;

        
        while (!days.empty() && days.front() <= current)
        {
            count++;
            days.pop();
        }

        answer.push_back(count);
    }

    return answer;
}

int main()
{
    
    vector<int> progresses1 = { 93, 30, 55 };
    vector<int> speeds1 = { 1, 30, 5 };
    vector<int> result1 = solution(progresses1, speeds1);

    for (int num : result1)
    {
        cout << num << " ";
    }
    cout << endl;

    vector<int> progresses2 = { 95, 90, 99, 99, 80, 99 };
    vector<int> speeds2 = { 1, 1, 1, 1, 1, 1 };
    vector<int> result2 = solution(progresses2, speeds2);

    for (int num : result2)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
