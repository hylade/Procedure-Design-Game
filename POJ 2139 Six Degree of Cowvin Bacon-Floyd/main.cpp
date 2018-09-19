#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;
/*
到所有牛的度数平均值最小，也就是找到所有的度数总和最小，那么就是找到这头牛到其他每头牛的最小度
也就是最短路径，相加再除以 n-1 既得最小平均值。可以枚举获得最小路径，再记录最小平均值
*/
int N, M;
int cost[301][301];
int a[301];
#define inf 0x3f3f3f3f

// 核心算法
void Floyd()
{
    for (int k = 0; k < N; k++)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
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
        // 此处需要注意输入的特点，每次都是 a[i] a[i]+1 a[i]+2 ...
        for (int i = 0; i < T; i++)
        {
            for (int j = i+1; j < T; j++)
            {
                cost[a[i]][a[j]] = cost[a[j]][a[i]] = 1;
            }
        }
    }

    Floyd();
    // 找到最小值并输出
    int ans = inf;
    for (int i = 0; i < N; i++)
    {
        int sum = 0;
        for (int j = 0; j < N; j++)
        {
            sum += cost[i][j];
        }
        ans = min(ans, sum);
    }
    ans = 100 * ans / (N-1);
    printf("%d", ans);

    return 0;
}
