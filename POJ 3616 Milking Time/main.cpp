#include <iostream>
#include <cstdio>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;
/*
解题思路：
定义 dp[i] 为第 i 个时间段能够得到的最大值，换言之，就是前面 i - 1 个时间段内任取 0 至 i - 1 个时间段挤奶；
然后加上这个时间段 i 的挤奶量之和
dp[i]= dp[i - 1] + 第 i 次挤奶量
*/
int N, W, R;
int dp[1001];
// 定义牛的信息结构体
struct Interval{
    int start;
    int end;
    int efficiency;
    // 运算符重载
    const operator< (const Interval&c) const
    {
        // 从小到大输出
        // 等同于 if (start < c.start)
                    // return true
                // return false
        return start < c.start;
    }
};
// 上述重载成员函数也能通过非成员函数实现
/*
bool operator< (const Interval &a, const Interval &b)
{
    if (a.start < b.start)
        return true;
    return false;
}
*/

// 还能通过自定义比较函数实现，但需要在 sort 函数中添加参数
/*
bool non(const Interval &a, const Interval &b)
{
    if (a.start < b.start)
        return true;
    return false;
}
*/
// 需要注意优先队列则不同
Interval interval[1001];


int main()
{
    scanf("%d %d %d", &N, &W, &R);
    for (int i = 0; i < W; i++)
    {
        // 输入信息
        scanf("%d %d %d", &interval[i].start, &interval[i].end, &interval[i].efficiency);
        // 实际的结束时间还要加上休息时间
        interval[i].end += R;
    }

    sort(interval, interval + W);

    for (int i = 0; i < W; i++)
    {
        // 第 i 次挤奶起码大于该次的挤奶量
        dp[i] = interval[i].efficiency;
        for (int j = 0; j < i; j++)
        {
            // 当满足时间要求时
            if (interval[j].end <= interval[i].start)
            {
                dp[i] = max(dp[i], dp[j] + interval[i].efficiency);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < W; i++)
    {
        ans = max(ans, dp[i]);
    }

    printf("%d", ans);
    // 或者通过 *max_element 完成查找最大值
    //printf("%d\n", *max_element(dp, dp + W));
    return 0;
}
