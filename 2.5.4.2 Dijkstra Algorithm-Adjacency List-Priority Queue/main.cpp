#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
/*
采用邻接表时，相比邻接矩阵能节省存贮空间，但是不加以优化的话，时间复杂度仍为 O(n^2)
故此处使用邻接表 + 优先度列的方式加以优化
*/
#define inf 0x7f7f7f7f
int V, E; // 顶点和边的数量
int start, final; // 起点和终点
int from, to, cost;

// d 表示最短距离， u 表示顶点编号
struct Headnode{
    int d, u;
    // 从小到大排序
    bool operator < (const Headnode& rhs) const
    {
        return d > rhs.d;
    }
};
struct edge{
    int to;
    int cost;
    edge(int t, int c): to(t), cost(c){}
};
vector<edge> G[1000]; // 按照 edge 类型的 vector ，记录与顶点相邻的点和他们组成边的权值
bool visit[1000];
int d[1000];

void dijkstra()
{
    // 初始化
    fill(d+1, d+V+1, inf);
    d[start] = 0;
    // 优先队列
    priority_queue<Headnode> que;
    que.push((Headnode){0, start}); // 将类 Headnode 创建的一个实例 push 到 que 中
    while (!que.empty())
    {
        // 取出距离最短的
        Headnode x = que.top();
        que.pop();
        int u = x.u;
        // 根据编号查看是否已经访问过
        if (visit[u]) continue;
        visit[u] = 1;
        for (vector<edge>::size_type i = 0; i < G[u].size(); i++)
        {
            // 根据连通的边更新距离
            edge e = G[u][i];
            if (d[e.to] > d[u] + e.cost)
            {
                d[e.to] = d[u] + e.cost;
                que.push((Headnode){d[e.to], e.to});
            }
        }
    }

}

int main()
{
    scanf("%d %d", &V, &E);
    scanf("%d %d", &start, &final);
    // 录入无权图
    for (int i = 1; i <= E; i++)
    {
        scanf("%d %d %d", &from, &to, &cost);
        G[from].push_back(edge(to, cost));
        G[to].push_back(edge(from, cost));
    }
    // dijkstra 算法
    dijkstra();
    // 结果输出
    if (d[final] == inf)
    {
        printf("-1");
    }
    else
    {
        printf("%d", d[final]);
    }
    return 0;
}
