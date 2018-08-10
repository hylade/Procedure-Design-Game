#include <iostream>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <cstdio>
using namespace std;
/*
通过 -1 版本中的方法，发现 dp 数组中每次都是使用 i 和 i-1
故可以通过滚动反复使用
*/

// family 用于确定不同家族的蚂蚁各有多少只
int family[1000];
// dp 数组
int dp[2][100000];
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
    int totel = 0;
    for (int i = 1; i <= T; i++)
    {
        // 前 i 个家族共有多少只蚂蚁，这是此时最长的排列长度
        totel += family[i];
        // & 是按位与符号，奇数与 1 按位与运算为 1 ，偶数与 1 按位与运算为 0
        // 从而将 i 和 i - 1 分类
        int cur = i & 1;
        int pre = (i - 1) & 1;
        // 将现在分析的数组初始化为 0
        memset(dp[cur], 0, sizeof(dp[cur]));
        // 确定当前能够被添加的蚂蚁数
        for (int j = 0; j <= family[i]; j++)
        {
            for (int k = j; k <= totel; k++)
            {
                // 前 pre 个家族中达到 k - j 只蚂蚁的集合中，每个集合放入 j 只蚂蚁
                dp[cur][k] = (dp[cur][k] + dp[pre][k - j]) % MOD;
            }
        }
    }
    int result = 0;
    int t = T & 1;
    // 寻找长度在 S - B 之间的集合数量
    for (int i = S; i <= B; i++)
    {
        result = (result + dp[t][i]) % MOD;
    }

    printf("%d", result);

    return 0;
}
