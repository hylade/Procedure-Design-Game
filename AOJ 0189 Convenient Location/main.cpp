#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;
/*
点数量不多，可以使用 Floyd 算法
*/
int N;
int from, to, dis;
#define inf 0x3f3f3f3f // 这里需要定义如此，这样无穷大相加也不会溢出，出现负数情况
int cost[11][11]; // 表示边 i-j 的权值，当 i=j 时， 权值为 0
int V;

int main()
{
    while (scanf("%d", &N) && N)
    {
        V = 0;
        memset(cost, inf, sizeof(cost));
        for (int i = 0; i < N; i++)
        {
            cost[i][i] = 0;
        }
        // 输入
        for (int i = 0; i < N; i++)
        {
            scanf("%d %d %d", &from, &to, &dis);
            cost[from][to] = dis;
            cost[to][from] = dis;
            V = max(V, max(from, to));
        }

        // Floyd 算法
        for (int k = 0; k <= V; k++)
        {
            for (int i = 0; i <= V; i++)
            {
                for (int j = 0; j <= V; j++)
                {
                    cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
                }
            }
        }

        // 找到一个与其他各点距离最短的点
        int ans = inf, loc;
        for (int i = 0; i <= V; i++)
        {
            int t = 0;
            for (int j = 0; j <= V; j++)
            {
                if (i == j) continue;
                t += cost[i][j];
            }
            if (t < ans) ans = t, loc = i;
        }

        printf("%d %d", ans, loc);
    }
    return 0;
}
