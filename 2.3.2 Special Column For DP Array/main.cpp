#include <iostream>
#include <cstdio>
using namespace std;
/*
根据 01 背包问题和完全背包问题中不断重复利用一个数组实现的方法
也可以通过将两个数组滚动使用来实现重复利用
如完全背包中的变形式： dp[i + 1][j] = max(dp[i][j], dp[i + 1][j - w[i]] + v[i])
可见对于以此计算，只需要考虑 dp[i] 和 dp[i + 1] 两个数值即可
所以可以结合奇偶性（在生成 dp 数组时即有 dp[0][j] 为 0），故得出如下代码
*/
int n, W;
int w[100], v[100];
int dp[2][101];
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
                dp[(i + 1) & 1][j] = dp[i & 1][j];
            }
            else
            {
                dp[(i + 1) & 1][j] = max(dp[i & 1][j], dp[(i + 1) & 1][j - w[i]] + v[i]);
            }
        }
    }
    printf("%d", dp[(n & 1)][W]);


    return 0;
}
