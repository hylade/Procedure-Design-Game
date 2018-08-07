#include <iostream>
#include <cstdio>
#include <algorithm>
#include <math.h>
#include <string.h>
using namespace std;
/*
基础 dp ，用 dp[i][j] 表示第 i 行 第 j 个点出能得到的最高分，由顶往下推导更新 dp 即可
*/
int N;
// 定义 dp 数组
int dp[350][350];
// 定义各个位置的分数
int score[350][350];

int main()
{
    while (scanf("%d", &N)!= EOF)
    {
        // 输入分数，注意三角形样式的数据输入方式！！！
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                scanf("%d", &score[i][j]);
            }
        }

        // dp[0][0] 时即为初始得分
        dp[0][0] = score[0][0];

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                // 转移
                dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + score[i + 1][j + 1]);
                dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + score[i + 1][j]);
            }
        }

        int ans = 0;
        for (int i = 0; i < N; i++)
        {
            // 对最后一行进行 max 即可
            ans = max(ans, dp[N][i]);
        }
        printf("%d", ans);
    }

    return 0;
}
