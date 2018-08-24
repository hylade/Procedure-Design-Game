#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define inf 0x7f7f7f7f
int V, E;
int prev[100]; // 最短路上的前驱点
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
                prev[edge[j].v] = edge[j].u; // 记录前驱点
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

// 路径关键函数
vector<int> get_path(int t)
{
    vector<int> path;
    // 倒退路径
    for(; t != -1; t = prev[t])
    {
        path.push_back(t);
    }
    // 逆序排列
    reverse(path.begin(), path.end());
    return path;
}

int main()
{
    scanf("%d %d", &V, &E);
    // 输入有向边
    for (int i = 1; i <= E; i++)
    {
        scanf("%d %d %d", &edge[i].u, &edge[i].v, &edge[i].cost);
    }
    fill(prev+1, prev+V+1, -1);
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

    vector<int> path;
    path = get_path(V);
    // 输出路径
    for (vector<int>::size_type i = 0; i < path.size(); i++)
    {
        cout << path[i] << " ";

    }
    cout << endl;

    return 0;
}
