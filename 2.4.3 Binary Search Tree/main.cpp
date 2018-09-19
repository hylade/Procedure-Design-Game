#include <iostream>
#include <cstdio>
#include <math.h>
#include <string.h>
#include <queue>
#include <algorithm>
using namespace std;
/*
二叉搜索树能够高效完成
1. 插入一个数值
2. 查询是否包含某个数值
3. 删除某个数值

在二叉搜索树种所有节点，都满足左子树上的所有节点都比自己小，而右子树上的所有节点都比自己大

查找数值：根据自身数值比较，确定搜索左子树还是右子树，然后循环

插入数值：按照查找数值的方法，就可以知道对应节点所处位置，然后在那个位置插入新的节点即可

删除数值，需要分为三种情况：
1. 需要删除的节点没有左儿子，那么就把右儿子提上去
2. 需要删除的节点的左儿子没有右儿子，那么就把左儿子提上去
3. 以上两种情况都不满足的话，就把左儿子子孙中最大的节点提到需要删除的节点上

二叉搜索树的复杂度与树的高度成正比，平均每次操作为 O(log)
*/

// 简单实现代码

// 表示节点的结构体
struct node{
    int val;
    node *lch, *rch;
};

// 插入数值 x
node *insert(node *p, int x){
    if (p == NULL) // 当节点不存在时，便创建新节点，左右子节点均为 NULL
    {
        node *q = new node;
        q ->val = x;
        q ->lch = q ->rch = NULL;
        return q;
    }
    else{
        if (x < p ->val) p->lch = insert(p ->lch, x); // 若数值小于 p 数值，便在左子树循环
        else p ->rch = insert(p ->rch, x); // 否在在右子树循环
        return p;
    }
}

// 查找数值 x
bool find(node *p, int x)
{
    if (p == NULL) return false; // 若开始寻找的节点为空，便返回 0 (找不到)
    else if (x == p ->val) return true; // 当数值相等时，说明找到数值，返回 true
    else if (x < p ->val) return find(p ->lch, x); // 若数值小于 p 数值，就在左子树循环寻找
    else return find(p ->rch, x); // 否则在右子树循环搜索
}

// 删除数值 x
node *remove(node *p, int x)
{
    if (p == NULL) return NULL; // 若节点不存在，返回空
    else if (x < p ->val) p ->lch = remove(p ->lch, x); // 数值不相等时，便在左右子树找该数值
    else if (x > p ->rch) p ->rch = remove(p ->rch, x);
    else if (p ->lch == NULL) // 若找到该数值节点，同时其左节点为空，对应第一种情况，那么将其右节点提上去，删除 p 节点
    {
        node *q = p ->rch;
        delete p;
        return q;
    }
    else if (p ->lch->rch == NULL) // 当左节点的右子树为空时，对应第二种情况，将左子树上提，并将原右子树作为新节点的右子树
    {
        node *q = p ->lch;
        q ->rch = p ->rch;
        delete p;
        return q;
    }
    else{ // 否则对应第三种情况
        node *q;
        for (q = p ->lch; q ->rch->rch != NULL; q = q ->rch); // 找到左子树中数值最大的点，即一直向右搜索
        node *r = q ->rch;
        q ->rch = r ->lch; // 将 q 的右子树用 r 的左子树代替
        r ->lch = p ->lch; // r 继承 p 的左右子树
        r ->rch = p ->rch;
        delete p;
        return r;
    }
}
int main()
{

    return 0;
}
