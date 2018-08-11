#include <iostream>
#include <cstdio>
#include <algorithm>
#include <math.h>
#include <string.h>
using namespace std;
/*
基本思路：
将证书 N 划分为一系列正整数之和，最大不超过 K ，称为整数 N 的 K 划分
dp[i][j] 定义为 整数 i 的 j 划分 的方法数

当 j > i 时，此时 dp[i][j] = dp[i][i]
当 i == j 时，此时 dp[i][j] = dp[i][j - 1] + 1
当其他情况，需要考虑是否出现 j ，故 dp[i][j] = dp[i - j][j] + dp[i][j - 1]

但由于本方法中没有考虑到大数的情况，当输入的 N 和 K 较大时，将输出负数，不满足要求
故请参考 -2 版本
*/
int N, K;
int dp[1001][101];

int main()
{
    while (scanf("%d %d", &N, &K))
    {
        if (N == 0 && K == 0)
        {
            break;
        }

        // 对于 0 的任何整数划分应该都为 1
        for (int i = 0; i <= K; i++)
        {
            dp[0][i] = 1;
        }

        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= K; j++)
            {
                if (i < j) dp[i][j] = dp[i][i];
                else if (i == j) dp[i][j] = dp[i][j - 1] + 1;
                else dp[i][j] = dp[i][j - 1] + dp[i - j][j];
            }
        }

        printf("%d", dp[N][K]);
    }

    return 0;
}
