#include <iostream>
#include <cstdio>
#include <algorithm>
#include <math.h>
#include <string.h>
using namespace std;
/*
本题中实际考察的是 完全背包和大数划分
仍用 dp[i][j] 表示：用 i 中价格配出金额 j 的方案数
那么 dp[i][0] = 1 ，使用任何价格配出金额 0 的方案个数都是 1
其他情况中： dp[i][j] = dp[i - 1][j] + dp[i - 1][j - i] + dp[i - 1][j - 2*i] + ... + dp[i - 1][0]
*/
int N, K;
unsigned long long a[105][1005],b[105][1005],inf=1;

int main()
{
    while (scanf("%d %d", &N, &K))
    {
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        if (N == 0 && K == 0)
        {
            break;
        }
        inf = 1;
        for (int i = 1; i < 18; i++)
        {
            inf *= 10;
        }

        // 使用任何价格配出金额为 0 的方案数都是 1
        for (int i = 0; i <= K; i++)
        {
            a[i][0] = 1;
        }

        for (int i = 1; i <= K; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                // 当 i > j 时说明金额数小于价格数，不需要这么大的价格，应该缩小价格继续考虑
                if (i > j)
                {
                    a[i][j] = a[i - 1][j];
                    b[i][j] = b[i - 1][j];
                }
                else{
                        // 处理大数前面的部分，当超过 int64 时，就开始存入 b 数组，因为 int64 是 10^18 次方，保证当两个 a 相加时不会超过 int64
                        // 由于只将 a[i][0] 初始化，所以只有当 a 数组的值大于 inf 时， b 数组中才会有数值传入
                    b[i][j] = (b[i - 1][j] + b[i][j - i]) + (a[i - 1][j] + a[i][j - i]) / inf;
                    a[i][j] = (a[i - 1][j] + a[i][j - i]) % inf;
                }
            }
        }
        if(b[K][N])
            cout << b[K][N];
        cout << a[K][N];
    }
    return 0;
}

