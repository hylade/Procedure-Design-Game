#include <iostream>
#include <cstdio>
#include <math.h>
#include <string.h>
#include <algorithm>
using namespace std;
/*
以 TS 和为状态求最大的 TF ，即 dp[TS] = TF
由于 TS 属于 [-100000, 100000] ，考虑到数组范围，需要调整为 [0, 200000]
其中 dp[zero = 100000] = 0

*/
int N;
int s[101], f[101];
const int zero = 100000;
// 以 s 的和为状态求最大的 f ，即 dp[s] = f ，s 的范围为 [-100000, 100000] ，以 zero = 100000 为零点
int dp[200000 + 2];
// 以 max_s 和 min_s 分别表示 TS 的最大值和最小值
int max_s, min_s;
#define inf 0x7f7f7f7f

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d %d", &s[i], &f[i]);
        if (s[i] >= 0)
            // 计算最大值
            max_s += s[i];
        else
        // 计算最小值
            min_s += s[i];
    }
    // 初始化，将 TS 可能出现的 dp 值都初始化为 -inf ，不能初始化为 0 ，这样能够防止不能合成数值的出现
    for (int i = min_s; i <= max_s; i++)
    {
        dp[i + zero] = -inf;
    }
    // 对于 zero 值应初始化为 0
    dp[zero] = 0;
/*
在进行 01 背包的时候， dp[v] = max(dp[v], dp[v - c[i]] + w[i]) ，需要使用 dp[v - c[i]] 跟新 dp[v] ，
所以需要从大到小遍历
但当 c[i] < 0 时，需要从小到大遍历，因为 v - c[i] > v
*/
    for (int i = 0; i < N; i++)
    {
        if (s[i] >= 0)
        {
            // 正数的时候，应该逆序，这样才能保证前面的值没有用过
            for (int j = max_s; j - s[i] >= min_s; j--)
            {
                dp[j + zero] = max(dp[j + zero], dp[j - s[i] + zero] + f[i]);
            }
        }
        else
        {
            // 负数的时候，应该正序，这样才能保证后面的值没有用过
            for (int j = min_s; j - s[i] <= max_s; j++)
            {
                dp[j + zero] = max(dp[j + zero], dp[j - s[i] + zero] + f[i]);
            }
        }
    }
    int ans = 0;
    // 找出符合 ts >= 0 和 tf >= 0 的最大值
    for (int i = 0; i <= max_s; i++)
    {
        if (dp[i + zero] >= 0)
        {
            ans = max(ans, i + dp[i + zero]);
        }
    }
    printf("%d", ans);


    return 0;
}
