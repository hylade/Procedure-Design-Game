#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
/*
dijkstra 算法只针对没有负边的情况，由于 bellman-ford 算法中
若 d[i] 还不是最短距离，那么即使进行 d[j] = d[i] + (从 i 到 j 边的权值) 更新
那么 d[j] 也不会变成最短距离，同时，若 d[i] 没有变化，也会循环检查从 i 出发的所有边
那样很浪费时间

故在 dijkstra 算法中进行了如下修改：
1. 找到最短距离已经确定的顶点，从它出发更新相邻顶点的最短距离
2. 此后不再需要关心 1 中的"最短距离已经确定的顶点"

故需要确定最短距离确定的点，最开始，只有起点的最短举例是确定的，而在尚未使用过的顶点中
距离 d[i] 最小的顶点就是最短距离确定的顶点

使用邻接矩阵实现 dijkstra 算法，复杂度为 O(V^2)
*/
#define inf 0x7f7f7f7f // 权值上限
int mat[100][100]; // 邻接矩阵
int V, E; // 顶点及边数量
int f, t, dis;
// 对于自定义类型，必须重载 operator < 或者写比较函数
// 顶点节点，保存 id 和到源顶点的距离
struct node
{
    int id, weight;
    // 因要实现最小堆，需升序排列，故重载运算符，以小为先
    friend bool operator < (node a, node b)
    {
        return a.weight > b.weight;
    }
};
priority_queue<node> que;
// 源点到所有顶点的最短路
node d[100];
// 判断是否已经找到最短路径
bool visited[100];
// 用于保存父亲节点，可以删除
int parent[100];
void dijkstra(int s)
{
    // 初始化
    for (int i = 1; i <= V; i++)
    {
        d[i].id = i;
        // 初始距离无穷大
        d[i].weight = inf;
        // 都不具有父节点且初始情况，都没有访问过
        parent[i] = -1;
        visited[i] = false;
    }
    // 源点权值为 0
    d[s].weight = 0;
    que.push(d[s]);
    while (!que.empty())
    {
        // 去最下值估算到顶点距离
        node cd = que.top();
        que.pop();
        int u = cd.id;
        if (visited[u])
        {
            continue;
        }
        visited[u] = true;
        // 松弛操作
        for (int v = 1; v <= V; v++)
        {
            // 找到所有与之相邻的顶点，进行松弛操作，更新距离，并 push 到 que 中
            if (v != u && !visited[v] && d[v].weight > d[u].weight + mat[u][v])
            {
                d[v].weight = d[u].weight + mat[u][v];
                parent[v] = u;
                que.push(d[v]);
            }
        }
    }
}


int main()
{
    while (scanf("%d %d", &V, &E))
    {
        if (V == 0 && E == 0)
        {
            break;
        }
        // 邻接矩阵初始化
        for(int i = 1; i <= V; i++)
        {
            for (int j = i; j <= V; j++)
            {
                mat[i][j] = mat[j][i] = inf;
            }
        }

        // 定义能连通的节点距离
        for (int i = 0; i < E; i++)
        {
            scanf("%d %d %d", &f, &t, &dis);
            if (dis < mat[f][t])
            {
                mat[f][t] = mat[t][f] = dis;
            }
        }
        dijkstra(1);
        printf("%d", d[7].weight);
    }
    return 0;
}
