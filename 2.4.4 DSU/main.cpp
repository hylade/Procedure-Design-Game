#include <iostream>
#include <cstdio>
#include <math.h>
using namespace std;
/*
并查集(DSU) 是一种用来管理元素分组情况的数据结构，只能进行合并操作而无法进行分割操作
能够查询元素 a 和元素 b 是否属于同一组；合并元素 a 和元素 b 所在的组
初始化时，用 n 个节点表示 n 个元素，最开始没有边；再需要合并，从一个组的根向另一个组的根连边，
那么两棵树就变成了一棵树，两个组也就变成一个组
查询：为查询两个节点是否属于同一组，需要查找这两个元素的根是否相同，若相同，则属于同一组

并查集也属于树，也可能发生退化，此时复杂度也将提高，但可以通过下述两种方法避免退化
1. 对于每棵树，记录这棵树的高度，合并时若两棵树的 rank 不同，则从 rank 小的向 rank 大的连边
2. 通过路径压缩，对于每个节点及在该节点查询过程中经过的节点，都改为直接连到根上

虽然路径压缩，将改变树的高度，但为了简便，此时不再修改 rank 值

并查集复杂度，对 n 个元素的并查集进行一次操作的复杂度为 O(\alpha(n))
\alpha(n) 表示阿克曼函数的反函数，这比 O(log(n)) 还要快
但这是均摊复杂度，并不是每次操作都满足这个复杂度，而是多次操作后的平均复杂度
*/

// 用数组 par 表示父亲的编号，当 par[x] = x 时， x 是所在树的根

int par[MAX_N]; // 父亲
int rank[MAX_N]; // 树的高度

// 初始化 n 个元素
void init(int n){
    for (int i = 0; i < n; i++)
    {
        par[i] = i; // 初始化的时候，父亲节点都是自身，此时高度为 0
        rank[i] = 0;
    }
}

// 查询树的根
int find(int x)
{
    if (par[x] == x) return; // 若自身便是根，便直接返回
    else return par[x] = find(par[x]); // 否则，则向上查找父节点
}

// 合并 x 和 y 所属的集合
void unite(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x == y) return; // 此时 x 和 y 就是同一集合，不需要合并

    // 若 x 的 rank 小于 y 的rank ，为了高效，将 x 添加到 y 上
    if (rank[x] < rank[y])
    {
        par[x] = y;
    }
    else
    {
        par[y] = x;
        if (rank[x] == rank[y]) rank[x]++;
    }
}

// 查询 x 和 y 是否属于同一个集合
bool same(int x, int y)
{
    return find(x) == find(y);
}
int main()
{

    return 0;
}
