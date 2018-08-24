#include <iostream>
#include <cstdio>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;
/*
普通 Dijkstra 算法，通过邻接矩阵实现
添加了路径还原
*/
// 邻接矩阵
int map[100][100];
int V, E;
// 是否访问过
int visit[100];
// 最短路径
int minroad[100];
#define inf 0x7f7f7f7f
int f, t, cost;
int next;
int prev[100];

void dijkstra(int s)
{
    memset(visit, 0, sizeof(visit));
    fill(minroad, minroad+V+1, inf);
    fill(prev, prev+V+1, -1);
    minroad[s] = 0;

    while (true)
    {
        int v = -1;
        // 从未使用过的顶点中选个一个距离最小的顶点
        for (int u = 0; u < V; u++)
        {
            if (!visit[u] && (v == -1 || minroad[u] < minroad[v]))
            {
                v = u;
            }
        }
        if (v == -1) break;
        visit[v] = true;
        for (int u = 0; u <= V; u++)
        {
            if (minroad[u] > minroad[v] + map[v][u])
            {
                minroad[u] = minroad[v] + map[v][u];
                prev[u] = v;
            }
        }
    }
}

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
    while (scanf("%d %d", &V, &E), V || E)
    {
        // 初始化
        for (int i = 0; i <= V; i++)
        {
            for (int j = 0; j <= V; j++)
            {
                map[i][j] = inf;
            }
        }

        // 输入两点距离
        while (E--)
        {
            scanf("%d %d %d", &f, &t, &cost);
            if (cost < map[f][t])
            {
                map[f][t] = map[t][f] = cost;
            }
        }


        dijkstra(1);

        printf("%d\n", minroad[V]);

        vector<int> path;
        path = get_path(V);
        // 输出路径
        for (vector<int>::size_type i = 0; i < path.size(); i++)
        {
            cout << path[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
