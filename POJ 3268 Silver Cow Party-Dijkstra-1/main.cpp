#include <iostream>
#include <cstdio>
#include <vector>
#include <string.h>
#include <queue>
using namespace std;
/*
修改传统 dijkstra 算法，使其支持任意两点最短路算法
*/
int N, M, X;
// 从顶点 from 指向顶点 to 的权值为 cost 的边
struct Edge{
    int to, cost;
    Edge(int _to, int _cost): to(_to), cost(_cost){}
};
// 图
vector<Edge> G[1001];
// 距离
int d[1001][1001];
// first 为最短路径， second 为顶点编号
typedef pair<int, int> P;
#define inf 0x3f3f3f3f

// 求解从顶点 s 到所有点的最短距离
void dijkstra(int s)
{
    priority_queue<P, vector<P>, greater<P> > que;
    memset(d[s], inf, 1001 * sizeof(int));
    d[s][s] = 0;
    que.push(P(0, s));

    while (!que.empty())
    {
        P p = que.top();
        que.pop();
        int v = p.second;
        if (d[s][v] < p.first) continue;
        for (vector<Edge>::size_type i = 0; i < G[v].size(); i++)
        {
            Edge e = G[v][i];
            if (d[s][e.to] > d[s][v] + e.cost)
            {
                d[s][e.to] = d[s][v] + e.cost;
                que.push(P(d[s][e.to], e.to));
            }
        }
    }
}

int main()
{
    scanf("%d %d %d", &N, &M, &X);
    X--;
    while (M--)
    {
        int s, e, t;
        // 输入
        scanf("%d %d %d", &s, &e, &t);
        s--, e--;
        G[s].push_back(Edge(e, t));
    }
    // 求解从各点到其他各点的距离
    for (int i = 0; i < N; i++)
    {
        dijkstra(i);
    }
    int ans = 0;
    // 找到最大值
    for (int i = 0 ; i < N; i++)
    {
        if (i == X) continue;
        ans = max(ans, d[i][X] + d[X][i]);
    }
    printf("%d", ans);

    return 0;
}
