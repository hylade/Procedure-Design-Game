#include <iostream>
#include <cstdio>
using namespace std;
/*
深度优先搜索（DFS, Depth-First-Search）是一种搜索手段，它是从某个状态开始，不断地转移状态直到无法转移，便回退到前一步的状态
继续转移到其他状态，如此不断重复，直到找到最终解；根据其特点，采用递归函数实现较为简单

深度优先搜索是从最开始的状态出发，遍历所有可以达到的状态，由此可以对所有状态进行操作或列举所有状态
*/

// 已经从前 i 项得到了和 sum_p ，然后对于 i 项之后的进行分类
bool dfs(int i, int sum, int n, int sum_p, int a[])
{
    if (n == i) return sum_p == sum; // 如果已经对前 n 项都计算过了，则返回 sum 是否与 sum_p 相等
    if (dfs(i + 1, sum, n, sum_p, a)) return true; // 不加 a[i] 的情况
    if (dfs(i + 1, sum, n, sum_p + a[i], a)) return true; // 加上 a[i] 的情况
    return false; // 无论是否加上 a[i] 都无法得到 sum ，则返回 false
}
int main()
{
    int MAX_N = 20;
    int n, m, a[MAX_N];
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    if (dfs(0, m, 4, 0, a)) printf("YES");
    else printf("NO");


    return 0;
}
