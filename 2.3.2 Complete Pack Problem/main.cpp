#include <iostream>
#include <cstdio>
using namespace std;
/*
完全背包问题中，同一种类的物品可以选择任意多件
令 dp[i + 1][j] 表示 从前 i 种物品中挑选总重量不超过 j 时总价值的最大值
递推关系如下：
dp[0][j] = 0
dp[i + 1][j] 由于 dp 数组初始化为 0 ，所以应为 dp[i + 1][j] 与 dp[i][j - k * w[i]] + k * v[i] 的较大值
状态转移：前 i + 1 种物品选取总重不超过 j 的状态和 前 i 种物品选取总重不超过 j 的状态
*/

/*
第一种方法采用三重循环，穷搜所有可能性，但此时 k 的循坏最坏可能从 0 到 W ，
所以这个算法的复杂度为 O(nW^2)
*/
// 第一种方法：三重循环
/*
int n, W;
int w[100], v[100];
int dp[101][101];
int main()
{
    scanf("%d %d", &n, &W);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &w[i], &v[i]);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            for (int k = 0; k * w[i] <= j; k++)
            {
                dp[i + 1][j] = max(dp[i + 1][j], dp[i][j - k * w[i]] + k * v[i]);
            }
        }
    }
    printf("%d", dp[n][W]);

    return 0;
}
*/


/*
由于三重循环中，算法中有多余的计算
由于 dp[i + 1][j] 计算中选择 k 个情况，与在 dp[i + 1][j - w[i]] 的计算中选择 k - 1 个情况时相同的
所以， dp[i + 1][j] 的递推中 k >= 1 部分的计算已经在 dp[i + 1][j - w[i]] 中计算完成了
所以原条件可以变形为：
max{dp[i][j - k * w[i]] + k * v[i] | 0 <= k}
= max(dp[i][j], max{[i][j - k * w[i]] + k * v[i] | 1 <= k)
= max(dp[i][j], max({dp[i][(j - w[i]) - k * w[i]] + k * v[i] | 0 < = k} + v[i])
= max(dp[i][j], dp[i + 1][j - w[i]] + v[i])
此时不需要 k 的循环，复杂度仅为 O(nW)
*/
int n, W;
int w[100], v[100];
int dp[101][101];
int main()
{
    scanf("%d %d", &n, &W);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &w[i], &v[i]);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            if (j < w[i])
            {
                dp[i + 1][j] = dp[i][j];
            }
            else{
                dp[i + 1][j] = max(dp[i][j], dp[i + 1][j - w[i]] + v[i]);
            }
        }
    }
    printf("%d", dp[n][W]);

    return 0;
}

