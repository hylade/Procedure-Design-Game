#include <iostream>
#include <cstdio>
using namespace std;
/*
这个问题是被称为最长公共子序列问题的著名问题
dp[i][j] 为 s1...si 和 t1...tj 的最长公共子序列的长度

所以对于 s1...si+1 和 t1...tj+1 的最长公共子序列的长度
当 s+1 == tj+1 时，为 s1...si 和 t1...tj 的最长公共子序列的长度 + 1
或者是 s1...si+1 和 t1...tj 与 s1...si 和 t1...tj+1 两者中较大的公共子序列长度
*/

int n, m;
char s[1000], t[1000];
int dp[1001][1001]; // DP 数组

int main()
{
    scanf("%d %d", &n, &m);
    scanf("%s %s", s, t); // 输入需要计算的序列

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (s[i] == t[j]) // 相等的情况
            {
                dp[i + 1][j +1 ] = dp[i][j] + 1;
            }
            else
            {
                dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
            }
        }
    }
    printf("%d", dp[n][m]);

    return 0;
}
