#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
/*
最短路问题：是给定两个顶点，在以这两个点为起点和终点的路径中，边的权值和最小的路径
单源最短路问题是固定一个起点，求它到其他所有点的最短路问题
终点固定的问题叫做两点之间的最短路问题，但两者复杂度相同，故一般单作单源最短路问题求解

记从起点 s 出发到顶点 i 的最短距离为 d[i]
故 d[i] = min(d[j] + 从 j 到 i 的边的权值)

若不存在负圈，那么更新操作是有限的，那么结束之后的 d 就是所求的最短距离

若图中不存在从 s 得到的负圈，那么最短路不会经过同一点两次，那么循环最多 V-1 条边
复杂度应为 O(VE)
但若存在从 s 可达的负圈，那么第 V 次循环也会更新 d 的值，故可按此检查负圈
或按照本题的做法，重新做循环，若又能松弛，说明存在负圈

// 利用次数检查负圈
for (int i = 0; i < V; i++)
{
    for (int j = 0; j < E; j++)
    {
        edge e = es[i];
        if (d[e.to] > d[e.from] + e.cost)
        {
            d[e.to] = d[e.from] + e.cost;
            if (i == V-1) return true;
        }
    }
}
return false;
*/

struct edge {
    int from, to;
    int cost;
    // 构造函数，用于变量赋值简便
    edge(int _from, int _to, int _cost)
    {
        from = _from; to = _to; cost = _cost;
    }
};
vector<edge> pedge; // 边集数组
int d[100];
int V, E;
#define inf 0x7f7f7f7f

void shortest_path(int s)
{
    // 记录是否存在负环
    // 负环是指由负权组成的环，这样就不存在最短路，每次循环路径值都会减小
    bool bNativeLoop = false;
    // 初始化
    for (int i = 1; i <= V; i++)
    {
        d[i] = inf;
    }
    // 始点初始化
    d[s] = 0;

    // 循环每个点
    for (int i = 1; i <= V; i++)
    {
        // 循环每条边
        // unsigned integer 和 signed integer
        for (vector<edge>::size_type j = 0; j < pedge.size(); j++)
        {
            int s = pedge[j].from, e = pedge[j].to, v=pedge[j].cost;
            // 若起始点可以到达 s 点，则进行松弛
            if (d[s] != inf)
            {
                d[e] = min(d[e], d[s] + v);
            }
        }
    }

    // 检查负环
    for (vector<edge>::size_type i = 0; i < pedge.size(); i++)
    {
        int s = pedge[i].from, e = pedge[i].to, v=pedge[i].cost;
        // 若按之前循环完毕后，仍能松弛，说明存在负环
        if (d[e] > d[s] + v)
        {
            bNativeLoop = true;
            break;
        }
    }
    if (bNativeLoop == true) {cout << " Exit Native Loop" << endl;}
    else{
            // 输出各点最短路
        for (int i = 1; i <= V; i++)
        {
            cout << d[i] << " ";
        }
        cout << endl;
    }
}
int main()
{
    scanf("%d %d", &V, &E);
    for (int i = 1; i <= E; i++)
    {
        int f, t, c;
        scanf("%d %d %d", &f, &t, &c);
        pedge.push_back(edge(f, t, c));
        pedge.push_back(edge(t, f, c)); // 创建无向图
    }
    shortest_path(1);
    return 0;
}
