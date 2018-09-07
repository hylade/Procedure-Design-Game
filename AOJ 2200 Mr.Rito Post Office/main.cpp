#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;
/*
先用 floyd 处理单独走水路或者陆路时，两点之间的最短路
用d[i][j] 表示当人运动到 i 点时，船停在 j 的最短路
若对于中间状态， d[i-1][k] ，若 j == k 时，说明没使用船，此时直接加两点之间的陆路最短路
若 j != k 时，说明使用船，说明先从 i-1 走陆路到中间状态 m ，从 m 走水路到 j ，再从 j 走陆路到 i
此时船便停留在 j
*/
int N, M, R;
int s[201][201];
int l[201][201]; // s 和 l 数组分别表示水路和陆路的边的权值，当不存在时为 inf ，且同一点时为 0
int b[1000];
int d[2000][201]; // d[i][j] 表示去第 i 个位置，船留在 j 位置的最短距离
#define inf 0x3f3f3f3f

// 使用 floyd 算法计算水路和陆路两点之间的最短路
void floyd(int n)
{
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                s[i][j] = min(s[i][j], s[i][k] + s[k][j]);
                l[i][j] = min(l[i][j], l[i][k] + l[k][j]);
            }
        }
    }
}

int main()
{
    while (scanf("%d %d", &N, &M))
    {
        // 初始化数组
        memset(s, inf, sizeof(s));
        memset(l, inf, sizeof(l));
        memset(d, inf, sizeof(d));
        //memset(b, 0, sizeof(b));

        if (N == 0 && M == 0) break;
        while (M--)
        {
            int f, t, c;
            char x[2];
            // 输入
            scanf("%d %d %d %s", &f, &t, &c, x);
            if (x[0] == 'L')
            {
                l[f][t] = min(l[f][t], c);
                l[t][f] = min(l[t][f], c);
            }
            else
            {
                s[f][t] = min(s[f][t], c);
                s[t][f] = min(s[t][f], c);
            }
        }

        // 同一点的边的权值为 0
        for (int i = 1; i <= N ;i++)
        {
            s[i][i] = 0;
            l[i][i] = 0;
        }
        // 输入需要经过点的顺序
        scanf("%d", &R);
        for (int i = 1; i <= R; i++)
        {
            scanf("%d", &b[i]);
        }

        floyd(N);
        // 若人处在 1 号，船处于 i 号位置时，说明需要坐船到 i ，并且走路回到 1
        for (int i = 1; i <= N; i++)
        {
            d[1][i] = min(d[1][i], s[b[1]][i] + l[i][b[1]]);
        }

        // 对于不同目标终点 i ，船位于 j ，前一状态位于 k 时
        for (int i = 1; i <= R; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                for (int k = 1; k <= N; k++)
                {
                    // 当船舶位置不变时，说明只需要走路就行，便在前一状态基础上加两点之间的陆路最短距
                    if (j == k)
                    {
                        if (l[b[i-1]][b[i]] < inf)
                        {
                            d[i][j] = min(d[i][j], d[i-1][k] + l[b[i-1]][b[i]]);
                        }
                    }
                    // 若船停放位置变化，说明需要考虑从 i-1 状态走路到 k ，从 k 坐船到 j ，在从 j 走路到 i
                    else
                    {
                        if (l[b[i-1]][k] < inf && s[k][j] < inf && l[j][b[i]] < inf)
                        {
                            d[i][j] = min(d[i][j], d[i-1][k] + l[b[i-1]][k] + s[k][j] + l[j][b[i]]);
                        }
                    }
                }
            }
        }
        // 对于同一终点 R ，不同的船停放位置，输出最短运动距离
        int ans = inf;
        for (int j = 1; j <= N; j++)
        {
            ans = min(ans, d[R][j]);
        }
        printf("%d", ans);
    }
    return 0;
}
