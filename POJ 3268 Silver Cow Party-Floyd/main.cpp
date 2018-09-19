#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;
/*
使用 floyd 算法， O(n^3) 不是很好，测试用例很容易爆
*/
int N, M, X;
int map[1001][1001];
#define inf 0x3f3f3f3f

// 找到点间距离
void floyd()
{
    for (int k = 0; k < N; k++)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (map[i][j] > map[i][k] + map[k][j])
                    map[i][j] = map[i][k] + map[k][j];
            }
        }
    }
}

int main()
{
    scanf("%d %d %d", &N, &M, &X);
    X--;
    // 初始化
    memset(map, inf, sizeof(map));
    for (int i = 0; i < N; i++)
    {
        map[i][i] = 0;
    }
    // 输入
    while (M--)
    {
        int s, e, t;
        scanf("%d %d %d", &s, &e, &t);
        s--, e--;
        map[s][e] = t;
    }
    floyd();
    int ans = 0;
    // 找最大值
    for (int i = 0; i < N; i++)
    {
        ans = max(ans, map[i][X] + map[X][i]);
    }
    printf("%d", ans);

    return 0;
}
