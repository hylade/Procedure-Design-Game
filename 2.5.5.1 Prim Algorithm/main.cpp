#include <iostream>
using namespace std;
int cost[MAX_N][MAX_N];
int mincost[MAX_N];
bool used[MAX_N];
int V;
#define INF 0x3f3f3f3f
/*
给定一个无向图，如果它的某个子图中任意两个顶点都互相连通并且是一棵树，那么这棵树就是生成树（Spanning Tree）
如果边上有权值，并且使得权值和最小的生成树叫做最小生成树（MST, Minimum Spanning Tree）

Prim 算法
先选取一个顶点 T ，然后贪心地选取 T 与其他顶点之间相连的最小权值的边，并且将其添加到 T 中
不断进行这个操作，生成的就是最小生成树

证明：
反证法：假设 prim 生成的不是最小生成树
1).设 prim 生成的树为 G0
2).假设存在 Gmin 使得 cost(Gmin) < cost(G0) 则在 Gmin 中存在 <u,v> 不属于G0
3).将 <u,v> 加入 G0 中可得一个环，且 <u,v> 不是该环的最长边(这是因为 <u,v> ∈ Gmin)
4).这与 prim 每次生成最短边矛盾
5).故假设不成立，命题得证.

如何求得最小权值的边
将 X 和 顶点 V 连接的边的最小权值记为 mincost[v]
在想 X 里添加顶点 u 时，只需要查看和 u 相连的边就可以了，对于每条边，更新
mincost[v] = min(mincost[v], 边(u, v) 的权值) 即可

如果每次遍历未包含在 X 中的点求 mincost[v] ，需要 O(V^2) 时间复杂度
但是若用堆来维护，需要 O(ElogV) 时间复杂度即可
*/
int prim()
{
    // 初始化
    for (int i = 0; i < V; i++)
    {
        mincost[i] = INF;
        used[i] = false;
    }

    mincost[0];
    int res = 0;

    while (true)
    {
        int v = -1;
        // 找到最小边
        for (int u = 0; u < V; u++)
        {
            if (!used[u] && (v == -1 || mincost[u] < mincost[v]))
                v = u;
        }
        // 不存在没有访问过的顶点则退出
        if (v == -1) break;
        used[v] = true;
        // 结果增加
        res += mincost[v];

        // 更新能访问的边
        for (int u = 0; u < V; u++)
        {
            mincost[u] = min(mincost[u], cost[v][u]);
        }
    }
    return res;
}
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
