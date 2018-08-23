#include <iostream>
#include <cstdio>
using namespace std;
/*
普通 Dijkstra 算法，通过邻接矩阵实现
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

int main()
{
    while (scanf("%d %d", &V, &E), V || E)
    {
        // 初始化
        for (int i = 1; i <= V; i++)
        {
            minroad[i] = inf;
            visit[i] = 0;
            for (int j = 1; j <= V; j++)
            {
                map[i][j] = inf;
            }
        }

        // 输入两点距离
        while (E--)
        {
            scanf("%d %d %d", &f, &t, &cost);
            map[f][t] = map[t][f] = cost;
        }
        // 从点 1 开始搜索
        int start = 1;
        visit[1] = 1;
        minroad[start] = 0;
        while (start != V)
        {
            int minx = inf;
            // 搜索点需要满足能与 start 点连通，并且是距离最短的
            for (int i = 1; i <= V; i++)
            {
                if (map[start][i] != inf)
                {
                    minroad[i] = min(minroad[i], minroad[start] + map[start][i]);
                }
                if (!visit[i] && minroad[i] < minx)
                {
                    next = i;
                    minx = minroad[i];
                }
            }
            // 搜索到的点作为下个点再进行下轮搜索，直到找到 V
            visit[next] = 1;
            start = next;
        }
        printf("%d\n", minroad[V]);
    }

    return 0;
}
