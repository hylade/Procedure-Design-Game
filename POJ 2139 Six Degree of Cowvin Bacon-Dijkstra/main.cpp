#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;

int N, M;
int cost[301][301];
int visit[301];
int d[301];
int a[301];
int next;
#define inf 0x3f3f3f3f

void dijkstra(int s)
{
    // 先更新起到与其邻点的路径
    for (int i = 0; i < N; i++)
    {
        d[i] = cost[s][i];
    }
    // 起点已经访问过
    visit[s] = 1;

    // 找到未访问过点中，与起点距离最小的点
    for (int i = 0; i < N; i++)
    {
        int min = inf;
        for (int j = 0; j < N; j++)
        {
            if (!visit[j] && d[j] < min)
            {
                next = j;
                min = d[j];
            }
        }

        // 更新该点到其邻点的距离
        visit[next] = 1;
        for (int j = 0; j < N; j++)
        {
            if (!visit[j] && d[j] > d[next] + cost[next][j])
            {
                d[j] = d[next] + cost[next][j];
            }
        }
    }
}
int main()
{
    scanf("%d %d", &N, &M);
    // 初始化
    memset(cost, inf, sizeof(cost));
    for (int i = 0; i < N; i++)
    {
        cost[i][i] = 0;
    }

    // 输入
    while (M--)
    {
        int T;
        scanf("%d", &T);
        for (int i = 0; i < T; i++)
        {
            scanf("%d", &a[i]);
            a[i]--;
        }
        for (int i = 0; i < T; i++)
        {
            for (int j = 0; j < T; j++)
            {
                if (a[i] != a[j])
                {
                    cost[a[i]][a[j]] = cost[a[j]][a[i]] = 1;
                }
            }
        }
    }

    double ans = inf;
    // 枚举每一头牛，从而找到最小度
    for (int i = 0; i < N; i++)
    {
        double sum = 0;
        dijkstra(i);
        // 记录度数和，并更新 ans
        for (int j = 0; j < N; j++)
        {
            if (i != j) sum += d[j];
        }
        ans = min(ans, sum);
    }
    ans = ans * 100 / (N - 1);
    printf("%lf", ans);

    return 0;
}
