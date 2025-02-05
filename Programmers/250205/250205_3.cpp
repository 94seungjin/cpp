/*
코딩 기초 트레이닝
문자열 반복해서 출력하기
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    int i;
    int n;

    cin >> str;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << str;
    }
    cout << endl;

    return 0;
}