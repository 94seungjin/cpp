/*
기능개발

프로그래머스팀에서는 기능 개선 작업을 수행 중입니다. 각 기능은 진도가 100%일 때 서비스에 반영할 수 있음.
또, 각 기능의 개발 속도는 모두 다르므로 뒤의 기느이 앞의 기능보다 먼저 개발될 수도 있음.
이때, 뒤의 기능은 앞의 기능이 배포될 때 함께 배포되어야 함.
배포 순서대로 작업 진도가 적힌 정수 배열 progresses와 각 작업의 개발 속도가 적힌 정수 배열 speeds가 주어질 대 각 배포마다
몇 개의 기능이 배포되는지를 반환하도록 solution()함수를 완성하라.

제약 조건
	- 작업 개수(progresses, speeds의 배열 길이)는 100개 이하
	- 작업 진도는 100미만의 자연수.
	- 작업 속도는 100이하의 자연수
	- 배포는 하루에 한 번만 할 수 있으며, 하루의 끝에 이루어진다고 가정. 예를 들어 진도율이 95%인 작업의 개발 속도가
	하루에 4%라면 배포는 2일 뒤에 이루어짐.

입출력의 예
progresses			speeds			return
[93, 30, 55]		[1,30,5]		[2,1]
[95,90,99,99,80,99]	[1,1,1,1,1,1]	[1,3,2]

프로토타입
vector<int> solution(vector<int> progresses, vector<int>speeds)
*/

/*
1. 각 진행상태 큐에 푸시
2. 팝 -> 작업 완료 검사 -> 완료 x -> 푸시 -> 100이 되어 나갈 때까지 푸시(반복문)
3. 
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> days; // 작업별 완료까지 필요한 일수

    // 각 작업별 완료 일수 계산
    for (size_t i = 0; i < progresses.size(); i++)
    {
        int remaining = 100 - progresses[i];
        int required_days = (remaining + speeds[i] - 1) / speeds[i]; // 올림 계산
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
