#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

vector<int> G[100];
int V, E;
// 顶点颜色初始化为 0 ，上色有两种 1 和 -1
int color[100];

bool dfs(int v, int s)
{
    // 将顶点染色为 s
    color[v] = s;
    // G[i][j] 就是 i 所有相邻点
    // 按照一般使用方法 for (int i = 0 ...) 将会出 warning
    // 警告目的是防止一个负的符号型的数据转化为无符号型时，会产生一个不是我们想要的很大的数据
    // 同时 signed 和 unsigned 数据范围也不同
    // 解决方法便是如下，将 i 变为 vector 类类型定义的类型
    for (vector<int>::size_type i = 0; i < G[v].size(); i++)
    {
        // 如果当前点的相邻点同色就返回 false
        if (color[G[v][i]] == s) return false;
        // 若当前点的邻点没有染色就染为 -s ，并对该点进行同样的搜索
        if (color[G[v][i]] == 0 && !dfs(G[v][i], -s)) return false;
    }
    // 若当前点的邻点都染过色，且都为 -s ，则返回 true
    return true;
}

void solve()
{
    for (int i = 0; i < V; i++)
    {
        // 对于各个节点若没有染色，便开始 dfs 搜索
        if (color[i] == 0)
        {
            if (!dfs(i, 1))
            {
                printf("NO\n");
                return ;
            }
        }
    }
    printf("YES\n");
}
// 创建连接表，并按图输入节点和边
int main()
{
    scanf("%d %d", &V, &E);
    for (int i = 0; i < E; i++)
    {
        int s, t;
        scanf("%d %d", &s, &t);
        G[s].push_back(t);
        G[t].push_back(s);
    }
    solve();

    return 0;
}
