#include <iostream>
#include <cstdio>
using namespace std;
/*
2.4.1 树和二叉树
每个节点在保存了格子的信息之外，还拥有子节点，拥有同一父节点的节点互为兄弟节点，没有子节点的节点称为叶子节点
二叉树是树种所有节点的子节点个数都不超过 2 的树

2.4.2.2 堆的结构
堆最重要的性质就是子节点的数值一定不小于父节点的值，同时，树的节点是从上到小，从左到右的顺序紧凑排列的
在堆中插入数值：首先在堆的末尾插入该数值，然后不断上提直到没有大小颠倒为止
在堆中取出最小值：首先将堆的最后一个节点的数值负值到根节点，然后删除最后一个节点，再使根节点不断向下交换直到没有大小颠倒为止
*/
// 二叉堆实现 push ， pop
int sz = 0, heap[MAX_N];

void push(int x)
{
    int i = sz++; // 自己节点的编号
    while (i > 0)
    {
        int p = (p - 1) / 2; // 父亲节点的编号
        if (heap[p] <= x)
        {
            break; // 若满足父节点小于子节点，则完成
        }
        heap[i] = heap[p]; // 把父亲节点的数值放下来，将自己提上去
        i = p;
    }
    heap[i] = x;

}

int pop()
{
    int ret = heap[0]; // 最小值
    int x = heap[--sz]; // 要提高根的数值

    int i = 0;
    while(i * 2 + 1 < sz)
    {
        int a = i * 2 + 1, b = i * 2 + 2;
        if (b < sz && heap[b] < heap[a])
        {
            a = b;
        }
        if (heap[a] >= x)
        {
            break; // 若没有大小颠倒则退出
        }
        heap[i] = heap[a]; // 将子节点的数值提上来
        i = a;
    }
    heap[i] = x;
    return ret;
}
int main()
{

    return 0;
}
