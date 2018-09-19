#include <iostream>
#include <cstdio>
/*
本题解法，可以从任意的 W 开始，不停地将邻接的部分用 "." 替换，当完成一次 DFS 后，与 W 相邻的 W 都被替换为 "." ，直到图中不再存在 W 为止
总共进行的 DFS 次数便是答案

由于共有 8 个方向，代表 8 种状态转移，每个格子作为 DFS 的参数至多被调用一次，所以复杂度为 O(8 * N * M) = O(N * M)

个人理解，只需要对右侧、右下侧、下侧、左下侧进行查验即可，这样能略微减少复杂度，此时为 O(4 * N * M) = O(N * M)
*/

const int MAX_N = 100, MAX_M = 100;

void dfs(int i, int j, char field[][100], int n, int m)
{
    // 替换现在位置处的字符
    field[i][j] = '.';
    for (int dx = 0; dx <= 1; dx++)
    {
        for (int dy = -1; dy <= 1; dy++)
        {
            // 移动坐标，从而查看四个方向处是否存在 'W'
            int nx = i + dx;
            int ny = j + dy;
            // 判断 (nx, ny) 是否在园子内，以及是否有积水
            if ((nx >= 0) && (nx <= n) && (ny >= 0) && (ny <= m) && field[nx][ny] == 'W')
            {
                dfs(nx, ny, field, n, m);
            }
        }
        /*
        上述代码中使用的四个方向，若需要对 8 个方向都进行检查，只需要将
        for (int dx = 0; dx <= 1; dx++) 变为
        for (int dx = -1; dx <= 1; dx++)
        */
    }
    return ;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    char field[n][100]; // 创建数组的时候，最好直接使用 field[100][100] 的方式，不存在变量，虽然 n 在前一行代码中已经赋值，但是仍是变量；
                        // 对于 const 定义的则非变量，此时也可以作为常量创建数组
    // 创建院园子
    for (int i = 0; i < n; i++)
    {
        /*
        for (int j = 0; j < m; j++)
        {
            scanf("%c", &field[i][j]); // 当使用 "%c" 读入单字符时，由于回车键也会作为字符被读入，所以只能读入一般的数据
        }
        */
        scanf("%s", field[i]); //此时 "%s" 读入字符串，且不会吃回车键，故可行，同时由于数组中为地址，故不需要取地址符
    }


    int time = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // 从有 'W' 开始使用深度优先搜索
            if (field[i][j] == 'W')
                {
                    dfs(i, j, field, n, m);
                    time += 1;
                }
        }
    }
    printf("%d", time);


    return 0;
}
