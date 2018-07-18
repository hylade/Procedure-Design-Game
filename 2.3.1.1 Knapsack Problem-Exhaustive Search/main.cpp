#include <iostream>
#include <cstdio>
using namespace std;
/*
当对于记忆化搜索或初始朴素方法难以理解，不能理解其中价值大小比对过程时，可以将搜索函数修改为如下

当程序中会出现剪枝情况时，可能会将各种函数都写在函数上，但是这种情况难以实现记忆搜索（原因在于无法存储维数过大的数组）
（剪枝：深度优先搜索时，有时早已明确当前状态无论如何都不会存在解，此时直接跳过而不再搜索）
*/
int n ,m;
int w[100], v[100];
// 当前选择的的物品价值总和是 sum ，从第 i 个物品之后的物品中挑选重量总和小于 j 的物品
int rec(int i, int j, int sum)
{
    int res;
    if (i == n)
    {
        res  = sum; // 此时已经没有剩余物品需要检查
    }
    else if (j < w[i])
    {
        res = rec(i + 1, j, sum); // 若此时背包容量无法放入该物品
    }
    else
    {
        res = max(rec(i + 1, j, sum), rec(i + 1, j - w[i], sum + v[i])); // 对挑选或不挑选都进行尝试
    }
    return res;
}
int main()
{
    scanf("%d %d", &n, &m);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &w[i], &v[i]);
    }

    printf("%d", rec(0, m, sum));

    return 0;
}
