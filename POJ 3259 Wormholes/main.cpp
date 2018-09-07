#include <iostream>
#include <cstdio>
#include <vector>
#include <string.h>
using namespace std;
/*
要回到过去就是需要回到起点的时间为负数，若回到起点的时间是负数
说明我们可以通过这些路径，使到起点的时间越来越早
一般路径为双向，虫洞路径为单向，并为负值

即本题的基本思路就是求是否存在负环，通过 bellman-ford 即可
*/
int T;
int N, M, W;
// 定义起点，终点和权值
struct Edge{
    int s, e, w;
    Edge(int ss, int ee, int ww): s(ss), e(ee), w(ww){};
};
vector<Edge> edges; // 边集
int dist[501]; // 距离数组
#define inf 0x3f3f3f3f

bool bellman(int s)
{
    // 初始化
    memset(dist, inf, sizeof(dist));
    dist[s] = 0;
    bool flag; // 标识
    for (int i = 1; i < N; i++)
    {
        flag = false;
        // 根据边更新距离
        for (vector<Edge>::size_type j = 0; j < edges.size(); j++)
        {
            if (dist[edges[j].e] > dist[edges[j].s] + edges[j].w)
            {
                dist[edges[j].e] = dist[edges[j].s] + edges[j].w;
                flag = true;
            }
        }
        if (!flag)
        {
            break;
        }
    }
    // 查看是否形成负圈
    for (vector<Edge>::size_type j = 0; j < edges.size(); j++)
    {
        if (dist[edges[j].e] > dist[edges[j].s] + edges[j].w)
        {
            return true;
        }
    }
    return false;
}
int main()
{
    scanf("%d", &T); // 尝试农田数
    while (T--)
    {
        scanf("%d %d %d", &N, &M, &W);
        // 输入路径
        for (int i = 0; i < M; i++)
        {
            int s, e, t;
            scanf("%d %d %d", &s, &e, &t);
            edges.push_back(Edge(s, e, t));
            edges.push_back(Edge(e, s, t));
        }
        // 输入虫洞
        for (int i = 0; i < W; i++)
        {
            int s, e, t;
            scanf("%d %d %d", &s, &e, &t);
            edges.push_back(Edge(s, e, -t));
        }
        if (bellman(1))
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
    return 0;
}
