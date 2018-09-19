#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;
/*
邻接表，需要手动加边
*/
int V, E; // 顶点和边的数量
int from, to, cost;
int edge; // 用于记录相应的边的编号
int head[100]; // 用于匹配边的编号和边
int dis[100]; // 距离
bool visit[100]; // 是否访问过
#define inf 0x7f7f7f7f

struct node
{
    int to, w; // 下个点和距离
    int next; // 连接同个顶点下一条边
}e[100];

// 初始化编号
void init()
{
    memset(head, -1, sizeof(head));
    edge = 0;
}

// 添加边，若是同个顶点的第一条边则 next 为 -1 ，否则根据 head 来区分
void add(int u, int v, int c)
{
    e[edge].to = v;
    e[edge].w = c;
    e[edge].next = head[u];
    head[u] = edge++; // 注意，由于是 edge++ ，故需要先放 edge ，再 edge++
}

void dijkstra(int s)
{
    // 初始化访问数组
    memset(visit, 0, sizeof(visit));
    // 初始化距离数组
    for (int i =1; i <= V; i++)
    {
        dis[i] = inf;
    }
    // 跟新距离，直到 i 为 -1 ，此处 ~i 为按位取反
    for (int i = head[s]; ~i; i = e[i].next)
    {
        int v = e[i].to;
        dis[v] = min(dis[v], e[i].w);
    }

    // 初始化起点信息
    visit[s] = 1;
    dis[s] = 0;

    // 开始搜索各个点间的最短距离
    for (int i = 0; i < V-1; i++)
    {
        int k = s;
        int mn = inf;
        // 搜索当前情况下，没有访问过的距离最短的点
        for (int j = 1; j <= V; j++)
        {
            if (!visit[j] && dis[j] < mn)
            {
                k = j;
                mn = dis[j];
            }
        }

        visit[k] = 1;
        // 对于找到的点，更新与之相邻的点的距离
        for (int i = head[k]; ~i; i = e[i].next)
        {
            int v = e[i].to;
            if (!visit[v] && dis[k] + e[i].w < dis[v])
            {
                dis[v] = dis[k] + e[i].w;
            }
        }
    }
}
int main()
{
    scanf("%d %d", &V, &E);
    init();
    // 输入邻接表
    for (int i = 0; i < E; i++)
    {
        scanf("%d %d %d", &from, &to, &cost);
        add(from, to, cost);
        add(to, from, cost);
    }

    // 核心算法
    dijkstra(1);
    // 输出
    printf("%d\n", dis[V]);

    return 0;
}
