#include <iostream>
#include <cstdio>
using namespace std;

int H, W;
char field[100][100];
int ans = 0;

void dfs(int x, int y, char c)
{
    if (x < 0 || x > H || y < 0 || y > W) // 当超过尺寸时，则不用判断
        return ;
    field[x][y] = '!'; // 将当前判断过的点置为 '!'
    if (field[x - 1][y] == c)
    {
        dfs(x - 1, y, c);
    }
    if (field[x + 1][y] == c)
    {
        dfs(x + 1, y, c);
    }
    if (field[x][y - 1] == c)
    {
        dfs(x, y - 1, c);
    }
    if (field[x][y + 1] == c)
    {
        dfs(x, y + 1, c);
    }
}
int main()
{
    while(scanf("%d %d", &H, &W) != EOF) // 多次运行
    {
        if (H == 0 && W == 0)
        {
            break; // 当输入面积不存在时，结束
        }
        for (int i = 0; i < H; i++)
        {
            scanf("%s", field[i]); // 场地
        }

        for (int i = 0; i < H; i++)
        {
            for (int j = 0; j < W; j++)
            {
                if (field[i][j] != '!') // 若该点还没有判断过，则进行操作
                {
                    dfs(i, j, field[i][j]); // 通过 dfs 判断周围相同的点，并且将相同的点都置为 '!'
                    ans += 1; // 块数量加 1
                }
            }
        }
        printf("%d", ans);
    }

    return 0;
}
