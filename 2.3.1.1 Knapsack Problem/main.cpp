#include <iostream>
#include <cstdio>
using namespace std;
/*
最朴素的方法，针对每个物品是否放入背包进行搜索

但是这种方法搜索深度是 n ，且每一层的搜索都需要两次分支，最坏需要 O(2^n) 的时间，若 n 较大时，就没有办法解决
*/
int n ,m;
int w[100], v[100];

int rec(int i, int j)
{
    int res;
    if (i == n)
    {
        res  = 0; // 此时已经没有剩余物品需要检查
    }
    else if (j < w[i])
    {
        res = rec(i + 1, j); // 若此时背包容量无法放入该物品
    }
    else
    {
        res = max(rec(i + 1, j), rec(i + 1, j - w[i]) + v[i]); // 对挑选或不挑选都进行尝试
    }
    return res;
}
int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &w[i], &v[i]);
    }

    printf("%d", rec(0, m));

    return 0;
}
