#include <iostream>
#include <cstdio>
using namespace std;
/*
有 n 个无区别的物品，将它们划分为不超过 m 组的划分方式被称为 n 的 m 划分，当 m = n 时，称为 n 的划分数
将 dp[i][j] 定义为 j 的 i 划分的总数，并且此时将具有两种情况
1：
刚好有 i 种划分情况，此时对于任何 ai 都大于 0 ，若对 i 组都取出 1 个元素（j 个元素无区别），
此时 {ai - 1} 相当于 j - i 的 i 划分，这与 j 的 i 划分是一样的，此时 dp[i][j] = dp[i][j - i]
2:
若少于 i 种划分情况，那么至少有一组中 ai = 0 ，此时相当于对 j 进行 i - 1 的划分，
此时 dp[i][j] = dp[i][j - i] + dp[i - 1][j]
该方法的复杂度为 O(nm)
*/
int n, m, M;
int dp[1001][1001];
int main()
{
    scanf("%d %d %d", &n, &m, &M);
    dp[0][0] = 1;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (j >= i)
            {
                dp[i][j] = (dp[i][j - i] + dp[i - 1][j]) % M;
            }
            else{
                dp[i][j] = dp[i - 1][j] % M;
            }
        }
    }
    printf("%d", dp[m][n]);



    return 0;
}
