#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;
/*
先满足最短路求解，再寻找最短路中的最低花费
*/
int N, M;
// 边结构体
struct edge
{
    int to, distance, cost;
    edge(int _to, int _distance, int _cost):to(_to), distance(_distance), cost(_cost){}
};
vector<edge> G[20001];
typedef pair<int, int> P;
int d[10001];

// dijkstra 算法
void dijkstra(int s)
{
    priority_queue<P, vector<P>, greater<P> > que;
    memset(d, 0x3f3f3f3f, sizeof(d));
    d[s] = 0;
    que.push(P(0, s));

    while (!que.empty())
    {
        P p = que.top();
        que.pop();
        int v = p.second;
        if (d[v] < p.first) continue;
        for (vector<edge>::size_type i = 0; i < G[v].size(); i++)
        {
            edge e = G[v][i];
            if (d[e.to] > d[v] + e.distance)
            {
                d[e.to] = d[v] + e.distance;
                que.push(P(d[e.to], e.to));
            }
        }
    }
}

int main()
{
    while (scanf("%d %d", &N, &M))
    {
        // 为 0 时跳出
        if (N == 0 && M == 0) break;
        // 清空
        for (int i = 0; i < N; i++)
        {
            G[i].clear();
        }
        // 赋值
        for (int i = 0; i < M; i++)
        {
            int f, t, d, c;
            scanf("%d %d %d %d", &f, &t, &d, &c);
            --f, --t;
            G[f].push_back(edge(t, d, c));
            G[t].push_back(edge(f, d, c));
        }
        dijkstra(0);
        int ans = 0;
        for (int i = 1; i < N; i++)
        {
            // 对于每个点，开始搜索的花费值初始化为 minx ，如此求最小值
            int minx = 0x3f3f3f3f;
            for (vector<edge>::size_type j = 0; j < G[i].size(); j++)
            {
                // 表示从 i 点到 j 点，若 j 点的最小距离加上两者距离等于 i 点最小距离
                // 说明此时路径为最短路径，此时取花费最小的路径
                // 代码目标为已知终点回溯起点，并只为求解最短路
                if (d[G[i][j].to] + G[i][j].distance == d[i] && G[i][j].cost < minx)
                {
                    minx = G[i][j].cost;
                }
            }
            ans += minx;
        }
        printf("%d", ans);
    }
    return 0;
}
