#include <iostream>
#include <cstdio>
#include <algorithm>
#include <math.h>
#include <string.h>
using namespace std;
/*
dp[i] 定义为长度为 i + 1 的下降序列中末尾元素的最大值

该题目需要将所有木材划分为 x 个不下降子序列（两个元素都不能下降），然后使 x 值最小
x 的最小值其实等于按 l 递增排序后按 w 查找到的最长下降子序列的长度 L
证明：
若存在其他 x < L ,那么先从排好序的木材中取出最长下降子序列 L ，取走的元素将留下一个大小相同的空穴
然后将剩余的元素和空穴分成 x 个不下降子序列。然后再将最长下降子序列 L 的 L 个元素放回到 L 个空穴中，
由于 x < L ,根据鸽笼原理（10 只鸽子放入 9 个鸽笼，必有一个鸽笼有两只鸽子），必然有两个或两个以上的
下降序列 L 中的元素被按顺序放入到同一个不下降序列中，此时该序列将存在下降序列，故产生矛盾

或者按照偏序的内容，最小数目的链的划分与最大反链的集合大小相同，那么就相当于求最大反链
故对 l 先进行从小到大排序， l 相同时则按 w 从小到大排序，那么 w 的最大下降子序列则为最大反链
*/
int T, n;
pair<int, int> stick[5001];
int dp[5001];

int main()
{
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            scanf("%d %d", &stick[i].first, &stick[i].second);
        }

        // 对木材进行从小到大排序
        sort(stick, stick + n);
        // 初始化为 -1
        memset(dp, -1, sizeof(dp));
        // 用于找到下降序列中 dp[i] 的最大值，当有新的最大值出现时，虽然会将原最大值覆盖
        // 但是 dp 数组长度仍不变，且会不断更新 dp[i] 的数值
        for (int j = 0; j < n; j++)
        {
            for (int i = 0; i < n; i++)
            {
                if (i == 0 || dp[i - 1] > stick[j].second)
                {
                    dp[i] = max(dp[i], stick[j].second);
                }
            }
        }
        // lower_bound(a, a + n, b) - a 能够用于返回最接近 b 参数的数组中数值的位置
        // 添加 greater<>() 能够使数组倒序排列
        // 由于数组初始化时为 -1 ，故找位置时只要找到最接近 -1 的位置即可
        cout << lower_bound(dp, dp + n, -1, greater<int>()) - dp << endl;
    }

    return 0;
}
