#include <iostream>
#include <cstdio>
using namespace std;
/*
由于对于每只动物，只有可能属于 A B C 中的一类，那么对于每只动物，都创建 i-A i-B i-C 3 个元素
使用这 3 * N 个元素建立并查集，并用并查集维护如下信息
1. i-x 表示 i 属于 x 种类
2. 并查集里每一个组表示组内所有元素代表的情况都同时发生或不发生

按照如下操作即可：
1.x 和 y 同类———合并 x-A 和 y-A ， x-B 和 y-B， x-C 和 y-C
2.x 吃 y ————— 合并 x-A 和 y-B ， x-B 和 y-C ， x-C 和 y-A
*/
int p[50001];
int rank[50001];
int N, K;
int T[50001], X[50001], Y[50001];

void init(int n) // 初始化 n 个元素
{
    for (int i = 0; i < n; i++)
    {
        p[i] = i;
        rank[i] = 0;
    }
}
// 查找树的根
int find(int x)
{
    if (p[x] == x) return x;
    return p[x] = find(p[x]);
}
// 合并 x 和 y 所属集合
void unite(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x == y)
        return;
    else if (rank[x] < rank[y])
        p[x] = y;
    else
    {
        p[y] = x;
        if (rank[x] == rank[y])
            rank[x]++;
    }
}
// 判断 x 和 y 是否属于同一集合
bool same(int x, int y)
{
    return find(x) == find(y);
}

int main()
{
    scanf("%d %d", &N, &K);
    for (int i = 0; i < K; i++)
    {
        scanf("%d %d %d", &T[i], &X[i], &Y[i]);
    }
    // 用 x x+N x+2N 分别表示 x-A x-B x-C
    init(3 * N);
    int ans = 0;
    for (int i = 0; i < K; i++)
    {
        int t = T[i];
        // 防止超限，将输入的值 -1
        int x = X[i] - 1, y = Y[i] - 1;
        // 对于不正确的编号，直接 ans++
        if (x < 0 || x >= N || y < 0 || y >= N)
        {
            ans++;
            continue;
        }
        // 对于 x 和 y 属于同一类的信息
        if (t == 1)
        {
            // 若已存在，并且 x 和 y 按照 x-A y-B 或者 x-A y-C 的方式存贮时，报错
            if (same(x, y + N) || same(x, y + 2 * N))
            {
                ans++;
                continue;
            }
            // 否则按 x-A y-A 及 x-B y-B 及 x-C y-C 的方式存贮
            else
            {
                unite(x, y);
                unite(x + N, y + N);
                unite(x + 2 * N, y + 2 * N);
            }
        }
        // 对于 x 吃 y 的信息
        else
        {
            // 若存贮信息为 x-A y-A 或者 x-A y-C ，就报错
            if (same(x, y) || same(x, y + 2 * N))
            {
                ans++;
                continue;
            }
            // 若不存在，就按照 x-A y-B 及 x-B y-C 及 x-C y-A 进行存贮
            else
            {
                unite(x, y + N);
                unite(x + N, y + 2 * N);
                unite(x + 2 * N, y);
            }
        }
    }
    printf("%d", ans);

    return 0;
}
