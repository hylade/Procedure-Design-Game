#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define inf 0x7f7f7f7f
int V, E;
struct Edge
{
    int u, v;
    int cost;
};
Edge edge[100];
int d[100];

bool Bellman_Ford(int s)
{
    // 初始化
    for (int i = 1; i <= V; i++)
    {
        d[i] = inf;
    }
    d[s] = 0;
    // 检查每个点和其连接的边
    for (int i = 0; i <= V-1; i++)
    {
        for (int j = 1; j <= E; j++)
        {
            if (d[edge[j].v] > d[edge[j].u] + edge[j].cost)
            {
                d[edge[j].v] = d[edge[j].u] + edge[j].cost;
            }
        }
    }
    // 负环检查
    bool flag = 1;
    for (int i = 1; i <= E; i++)
    {
        if (d[edge[i].v] > d[edge[i].u] + edge[i].cost)
        {
            flag = 0;
            break;
        }
    }
    return flag;
}


int main()
{
    scanf("%d %d", &V, &E);
    // 输入有向边
    for (int i = 1; i <= E; i++)
    {
        scanf("%d %d %d", &edge[i].u, &edge[i].v, &edge[i].cost);
    }
    if (Bellman_Ford(1))
    {
        for (int i = 1; i <= V; i++)
        {
            printf("%d\n", d[i]);
        }
    }
    else
    {
        printf("Negative circle\n");
    }


    return 0;
}
