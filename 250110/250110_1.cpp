#include <iostream>
#include <vector>

using namespace std;

// ºó 2Â÷¿ø º¤ÅÍ ¼±¾ð
vector <vector<int>> v1;

// 2d vector initialized by specific size
int rows = 3;
int cols = 4;
vector<vector<int>> v2(rows, vector<int>(cols));

// 2d vector initialized by specific value
int value = 9;
vector<vector<int>> v3(rows, vector<int>(cols, value));

// initialize 2d vector used by initilized list
vector <vector<int>> v4 = {
	{1,2,3},
	{4,5,6},
	{7,8,9}
};