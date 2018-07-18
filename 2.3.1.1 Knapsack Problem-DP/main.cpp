#include <iostream>
#include <cstdio>
using namespace std;
/*
通过对 2.3.1.1 Knapsack Problem 中规律的总结，可以得出 dp[i][j] 的递推式
此时不需要使用递归函数，使用二重循环也能解决问题

这个算法的复杂度与 2.3.1.1 Knapsack Problem-Memory Search 的复杂度相同，都是 O(nm)
这种一步步按顺序求出问题的解的方法被称为动态规划法，也就是常说的 DP

解决该类问题既可以按照上述方法从记忆化搜索中推导出递推式，也可以熟练后直接得出递推式
*/
int n ,m;
int w[100], v[100];
int dp[101][101];

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &w[i], &v[i]);
    }

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j <= m; j++)
        {
            if (j < w[i])
            {
                dp[i][j] = dp[i + 1][j];
            }
            else{
                dp[i][j] = max(dp[i + 1][j], dp[i + 1][j - w[i]] + v[i]);
            }
        }
    }
    printf("%d", dp[0][m]);
    return 0;
}

/*
// 上述 DP 中关于 i 的循环是逆向进行的，反之，若按照如下方式定义递推关系的话，关于 i 的循环就能正向进行
dp[i + 1][j] : 从 0 到 i 这 i + 1 个物品中选出总重量不超过 j 的物品时总价值的最大值
dp[0][j] = 0
对于 dp[i + 1][j] 当 j < w[i] 时， 为 dp[i][j] ； 当为其他情况时，为 max(dp[i][j], dp[i][j - w[i]] + v[i])
循环体如下：
for (int i = 0; i < n; i++)
{
    for (int j = 0; j < m; j++)
    {
        if (j < w[i])
        {
            dp[i + 1][j] = dp[i][j];
        }
        else{
            dp[i + 1][j] = max(dp[i][j], dp[i][j - w[i]] + v[i]);
        }
    }
}
*/

/*
同时，除运用递推方式逐项求解之外，还可以把状态转移想象成从"前 i 个物品中选取总重不超过 j 时的状态"向"前 i + 1 个物品中选取总重不超过 j "
和" 前 i + 1 个物品中选取总重不超过 j + w[i] 时的状态"转移
代码如下：
for (int i = 0; i < n; i++)
{
    for (int j = 0; j < m; j++)
    {
        dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
        if (j + w[i] <= m)
        {
            dp[i + 1][j + w[i] = max(dp[i + 1][j + w[i]], dp[i][j] + v[i]);
        }
    }
}
printf("%d", dp[n][m]);
*/

/*
千万不要忘记初始化！！！
因为全局数组的内容会被初始化为 0 ，所以前面的源代码中并没有显式地将初项 = 0 进行赋值
但当一次运行要处理多组输入数据时，必须要进行初始化，同时局部数组若不初始化，则其值为随机值
*/
