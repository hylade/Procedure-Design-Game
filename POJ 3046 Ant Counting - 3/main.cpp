#include <iostream>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <cstdio>
using namespace std;
/*
但上述两种方法都是采用三重循环的方法，将 dp[i][j] = \sum_{k=0}^{min(j, num[i])} 化简为
dp[i][j] = dp[i][j-1] + dp[i-1][j] + dp[i-1][j-1-num[i]]
若 num[i] > j - 1 时最后一项不存在
这种方法在 P69 早有提及
*/

// family 用于确定不同家族的蚂蚁各有多少只
int family[1000];
// dp 数组
int dp[1000][100000];
int T, A, S, B;
#define MOD 1000000

int main()
{
    // 输入初始条件
    scanf("%d %d %d %d", &T, &A, &S, &B);
    for (int i = 0; i < A; i++)
    {
        // 输入不同家族的蚂蚁
        int x;
        scanf("%d", &x);
        // 累加
        family[x]++;
    }

    // 一个都不取的方法总是一种
    for (int i = 0; i <= T; i++)
    {
        dp[i][0] = 1;
    }

    for (int i = 1; i <= T; i++)
    {
        for (int j = 1; j <= A; j++)
        {
            if ((j - 1 - family[i]) >= 0)
            {
                // 取余是为了避免减法运算的结果出现负数
                dp[i][j] = (dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1 - family[i]]) % MOD;
            }
            else{
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
            }
        }
    }
    int result = 0;
    // 寻找长度在 S - B 之间的集合数量
    for (int i = S; i <= B; i++)
    {
        result = (result + dp[T][i]) % MOD;
    }

    printf("%d", result);

    return 0;
}
