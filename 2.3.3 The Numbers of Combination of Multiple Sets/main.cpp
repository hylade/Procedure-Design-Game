#include <iostream>
#include <cstdio>
using namespace std;
/*
多重集组合数，在计数过程中，为了保证不重复计数，同一种类的物品最好一次性处理好
定义dp[i + 1][j] 为前 i 种物品中取出 j 个的组合总数
1:
为了从前 i 中物品中取出 j 个，那么可以从前 i - 1 种物品中取出 j - k 个，然后再从
第 i 种物品中取出 k 个添加进来，得出递推关系 dp[i + 1][j] = dp[i][j - k] | k_{k=0}^{min(j, a[i])}
若对上式直接进行递推，则复杂度为 O(nm^2)
右式可以分情况讨论，当 j <= a[i] 时，所以此时 j - 1 < a[i]
min(j ,a[i]) = j ，所以右式化为 dp[i][j - 1 -k] | k_{k=0}^{min(j-1, a[i])} + dp[i][j]
当 j > a[i] 时，此时右式化为  dp[i][j - 1 -k] | k_{k=0}^{min(j-1, a[i])}
（对于 j > a[i] 时，由于已经考虑过 j = a[i] 的情况，所以此处不能取到 dp[i][j - 1 - a[i]] ,需要减掉）
所以右式的结果为两种情况之和，化为 dp[i][j - 1 - k] | k_{k=0}^{min(j-1, a[i])} + dp[i][j] - dp[i][j - 1 - a[i]]
由于右式化简后的累加公式表示的情况为 dp[i + 1][j - 1]
故上式为： dp[i + 1][j] = dp[i + 1][j - 1] + dp[i][j] - dp[i][j - 1 - a[i]]

2:
方法 1 理解略有难度，对于方法 2 ，首先考虑第 i 种物品拿了或者没拿
对于没拿的情况： dp[i + 1][j] = dp[i][j]
对于拿了的情况： dp[i + 1][j] = dp[i][j - 1]
但是对于 dp[i][j - 1] 情况包含了拿第 i 种物品 a[i] + 1 个可能，所以需要减掉 dp[i][j - 1 - a[i]]
故上式为： dp[i + 1][j] = dp[i + 1][j - 1] + dp[i][j] - dp[i][j - 1 - a[i]]

此时的复杂度为 O(nm)
*/
int n, m, M;
int a[1000];
int dp[1001][1001];
int main()
{
    scanf("%d %d %d", &n, &m, &M);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    // 一个都不取的方法总是只有 1 种
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 1;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (j - 1 - a[i] >= 0)
            {
                // 防止减法运算出现负数，变加 M
                dp[i + 1][j] = (dp[i + 1][j - 1] + dp[i][j] - dp[i][j - 1 - a[i]] + M) % M;
            }
            else{
                dp[i + 1][j] = (dp[i + 1][j - 1] + dp[i][j] + M) % M;
            }
        }
    }

    printf("%d", dp[n][m]);



    return 0;
}
