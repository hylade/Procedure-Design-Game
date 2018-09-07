#include <iostream>
#include <cstdio>
#include <string.h>
#include <algorithm>
using namespace std;

int T;
int N, M, W;
int map[501][501];
#define inf 0x3f3f3f3f

bool floyd()
{
    for (int k = 1; k <= N; k++)
    {
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                if (map[i][j] > map[i][k] + map[k][j])
                    map[i][j] = map[i][k] + map[k][j];
            }
            if (map[i][i] < 0) return 1; // 若回到某一点的距离为负值，说明存在负圈
        }
    }
    return 0;
}
int main()
{
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d %d %d", &N, &M, &W);
        // 初始化
        memset(map, inf, sizeof(map));
        for (int i = 1; i <= N; i++)
        {
            map[i][i] = 0;
        }
        // 输入
        for (int i = 0; i < M; i++)
        {
            int s, e, t;
            scanf("%d %d %d", &s, &e, &t);
            map[s][e] = map[e][s] = t;
        }
        for (int i = 0; i < W; i++)
        {
            int s, e, t;
            scanf("%d %d %d", &s, &e, &t);
            map[s][e] = -t;
        }
        if (floyd())
        {
            printf("Yes\n");
        }
        else{
            printf("No\n");
        }

    }
    return 0;
}
