#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
/*
使用邻接矩阵来模拟，通过 bfs 遍历图
*/
bool flag = false;
// 邻接矩阵
int G[100][100];
int V, E;
// 顶点颜色初始化为 0 ，上色有两种 1 和 -1
int color[100];

bool bfs(int v)
{
    // 将顶点染色为 1
    color[v] = 1;
    queue<int> que;
    que.push(v);
    while (!que.empty())
    {
        int from = que.front();
        que.pop();
        for (int i = 1; i <= V; i++)
        {
            // 若相邻的点没有染色就上色
            if(G[from][i] && color[i] == 0)
            {
                que.push(i);
                color[i] = -color[from];
            }
            // 若相邻的点颜色相同，就返回 false
            if (G[from][i] && color[i] == color[from])
                return false;
        }
    }
    // 若相邻的点都被染过色，且相邻的颜色都不相同
    return true;
}

void solve()
{
    for (int i = 1; i <= V; i++)
    {
        // 若点没有染色，便开始 bfs 搜索
        if (color[i] == 0 && !bfs(i))
        {
            flag = true;
            break;
        }
    }
}
// 创建连接表，并按图输入节点和边
int main()
{
    scanf("%d %d", &V, &E);
    for (int i = 0; i < E; i++)
    {
        int s, t;
        scanf("%d %d", &s, &t);
        // 邻接矩阵创建
        G[s][t] = G[t][s] = 1;
    }
    solve();
    if (flag)
    {
        printf("NO\n");
    }
    else
    {
        printf("YES\n");
    }

    return 0;
}
