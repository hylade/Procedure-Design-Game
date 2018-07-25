#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string.h>
using namespace std;
/*
对于该多重部分和的问题可以使用 DP 进行求解
方法1：
定义 dp[i + 1][j] 为前 i 种数字是否能加和成 j
为了得到 dp[i + 1][j] ，所以需要用前 i - 1 种数字加和成 j， j - ai，...， j - mi * ai
由此可得递推关系式为 dp[i + 1][j] = （0 <= k <= mi 且 k * ai <= j 时存在 dp[i][j - k * ai] 为真的 k ）
这种算法的复杂度为 O(K (mi)_{累加})

方法2：
由于第 1 种方法复杂度较大，若我们不光求出能否得到目标的和数，同时把得到时 ai 这个数还剩下几个可以使用计算出来
即可减少复杂度
定义 dp[i + 1][j] 为用前 i 种数加和得到 j 时第 i 种数能够剩余多少个（不能加和得到 i 的情况下为 -1 ）
若按照这种递推关系，若前 i - 1 个数能够加和得到 j 的话，第 i 个数就可以留下 mi 个
若前 i 种数加和得到 j - ai 时第 i 种数还能剩下 k 的话，那么用这 i 种数加和得到 j 时第 i 种数就能剩下 k - 1 个
故递推式为：
dp[i + 1][j] 当 dp[i][j] >= 0 时为 mi ；当 j < ai 或 dp[i + 1][j - ai] <= 0 时，为 -1 ；
当为其他情况时，为 dp[i + 1][j - ai] - 1
此时，当 dp[n][K] >= 0 时即可证明

这种方法的复杂度为 O(nK) ，同时为了缩小空间，重复利用数组
*/
// 1
/*
int n, K;
int main()
{
    scanf("%d %d", &n, &K);
    int a[n], m[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &a[i], &m[i]);
    }
    bool dp[n + 1][K + 1];
    dp[0][0] = true;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= K; j++)
        {
            for (int k = 0; k <= m[i] && k * a[i] <=j; k++)
            {
                dp[i + 1][j] |= dp[i][j - k * a[i]];
            }
        }
    }

    if (dp[n][K])
    {
        printf("Yes");
    }
    else
    {
        printf("No");
    }

    return 0;
}
*/

// 2
int n, K;
int main()
{
    scanf("%d %d", &n, &K);
    int a[n], m[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &a[i], &m[i]);
    }

    int dp[K + 1];

    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= K; j++)
        {
            if (dp[j] >= 0)
            {
                dp[j] = m[i];
            }
            else if(j < a[i] || dp[j - a[i]] <= 0)
            {
                dp[j] = -1;
            }
            else{
                dp[j] = dp[j - a[i]] - 1;
            }
        }
    }
    if (dp[K] >= 0)
    {
        printf("Yes");
    }
    else{
        printf("No");
    }
    return 0;
}
