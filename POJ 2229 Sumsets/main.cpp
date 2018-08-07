#include <iostream>
#include <cstdio>
#include <algorithm>
#include <math.h>
#include <string.h>
using namespace std;
/*
解题思路：
1. 当 n 为奇数时， f[n] = f[n - 1] ，因为此时只需要在所有原序列前增加一个 1 即可，不会重复出现
2. 当 n 为偶数时，需要分为两种情况，当序列中带有 1 时，这是 f[n - 1] 序列增加 1 后之后的序列
当序列中没有带 1 ，即首位为 2 时，正好是 f[n / 2] 数列 * 2 之后的数列，故此时 f[n] = f[n - 1] + f[n / 2]
*/
int N;
int dp[100000];

int main()
{
    dp[1] = 1;
    while (scanf("%d", &N) != EOF)
    {
        for (int i = 2; i <= N; i++)
        {
            if (i % 2 == 1)
            {
                dp[i] = dp[i - 1];
            }

            else
            {
                dp[i] = dp[i - 1] + dp[i / 2];
            }
            dp[i] %= 1000000000; // 由于当 N 稍大时， dp[N] 的数值将很大，模 1000000000 将只输出后 9 位
        }
        printf("%d\n", dp[N]);
    }


    return 0;
}
