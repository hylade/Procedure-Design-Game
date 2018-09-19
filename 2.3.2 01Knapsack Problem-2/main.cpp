#include <iostream>
#include <cstdio>
#include <math.h>
#include <algorithm>
using namespace std;
/*
本题与最初的 01 背包问题相比，修改了限制条件的大小，则原复杂度 O(nW) 在此将过大
但此处相比重量而言，价值的范围较小，可以通过修改 DP 的对象，用 DP 针对不同的价值计算最小的重量

第一步仍需要对 dp[i + 1][j] 数组进行初始化：
dp[i + 1][j] 表示前 i 个物品中挑选价值总和为 j 时总重量的最小值（不存在时将显示一个充分大的数值 INF ）
由于前 0 个物品什么都挑选不了，故初始值
dp[0][0] = 0
dp[0][j] = INF

与原 01 问题相同，前 i 个物品中挑选出价值总和为 j 时将通过
1：前 i - 1 个物品中挑选价值总和为 j 的部分
2：前 i - 1 个物品中挑选价值总和为 j - v[i] 的部分，然后再选中第 i 个物品

故得出递推式： dp[i + 1][j] = min(dp[i][j], dp[i - 1][j - v[i]] + w[i])
最终得出的答案即为 dp[n][j] <= W 的最大的j
此时，复杂度将变为 O(n(ni)_{累加})
*/

int n, W;
int w[100], v[100];

#define inf 1000000001 // 由于要用于 W 的判别，故设为此数值
int main()
{
    scanf("%d %d", &n, &W);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &w[i], &v[i]);
    }
    int V = *max_element(v, v + n);
    // max_element 能够返回最大元素的位置，但若需要相应的数值，则需要通过指针指向该地址
    // 即 *max_element(a, a + n);
    int dp[100][n * V + 1]; // DP 数组
    fill(dp[0], dp[0] + n * V + 1, inf); // 在使用 inf 前需要先对 inf 定义
    dp[0][0] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= n * V; j++)
        {
            if (j < v[i])
            {
                dp[i + 1][j] = dp[i][j];
            }
            else{
                dp[i + 1][j] = min(dp[i][j], dp[i][j - v[i]] + w[i]);
            }
        }
    }
    int res = 0;
    for (int i = 0; i <= n * V; i++)
    {
        if (dp[n][i] <= W) // 对各个重量进行判断，只考虑小于 W 的情况，由于 i 是递增的
                           // 不必担心较小的 i 值成为最后的解
        {
            res = i;
        }
    }
    printf("%d", res);


    return 0;
}
