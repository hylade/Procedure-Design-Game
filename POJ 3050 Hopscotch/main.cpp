#include <iostream>
#include <cstdio>
#include <set>
#include <string>
#include <algorithm>
using namespace std;
/*
当前的状态可以定义为当前位置、当前数字长度、当前数字这三个要素
利用状态转移 dfs 可遍历所有情况。对于数字储存可以使用 set 来满足要求
*/
// 场地，即数字
int field[5][5];
// 用于保存以后的数字组合
set<int> results;
// 移动方向
int direction[4][2] = {
    {0, 1},
    {0, -1},
    {-1, 0},
    {1, 0},
    };

    // dfs 函数
void dfs(const int& x, const int& y, const int& step, const int& number)
{
    // 跳房子结束时
	if (step == 5)
	{
	    // insert 将数值插入同时将返回数值的迭代器和一个 bool 值
		results.insert(number);
		return;
	}

	// 方向漫游
    for (int i = 0; i < 4; i++)
    {
        // 移动后点的位置
        int nx = x + direction[i][0];
        int ny = y + direction[i][1];

        // 判断移动后的点是否出界
        if (nx >= 0 && nx < 5 && ny >= 0 && ny < 5)
        {
            // 若没有出界，则作为新起点，继续漫游
            dfs(nx, ny, step + 1, number * 10 + field[nx][ny]);
        }
    }
}

int main()
{
    // 输入
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            scanf("%d", &field[i][j]);
        }
    }

    // 将每个点作为起点做遍历
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            dfs(i, j, 0, field[i][j]);
        }
    }

    printf("%d", results.size());

    return 0;
}
