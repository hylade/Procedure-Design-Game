#include <iostream>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <cstdio>
using namespace std;
/*
用 dp[i][j] 表示前 i 个家族构成长度 j 的序列有多少种
那么 dp[i][j] = \sum(dp[i-1][j-k]) 其中 k 的范围是 0 - N[i]
即前 i - 1 个家族配成 j - k 的集合，每个集合都加入家族 i 的 k 只蚂蚁
累加得到前 i 个家族配成 j 只的集合数目
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

    // 空集的个数为 1
    dp[0][0] = 1;
    // 初始化总蚂蚁数
    int totel = family[0];
    for (int i = 1; i <= T; i++)
    {
        // 前 i 个家族共有多少只蚂蚁，这是此时最长的排列长度
        totel += family[i];
        // 确定当前能够被添加的蚂蚁数
        for (int j = 0; j <= family[i]; j++)
        {
            for (int k = j; k <= totel; k++)
            {
                // 前 i - 1 个家族中达到 k - j 只蚂蚁的集合中，每个集合放入 j 只蚂蚁
                dp[i][k] = (dp[i][k] + dp[i - 1][k - j]) % MOD;
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
