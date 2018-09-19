#include <iostream>
#include <algorithm>
#include <cstdio>
#include <math.h>
#include <string.h>
using namespace std;
/*
多重背包和方法，速度应该与版本 -2 相同
*/
int K;
// 按照每组数据中的 a 进行从小到大排序
struct node{
    int h, a, c;
    bool operator< (const node b) const{
        return a < b.a;
    }
}data[401];
// dp[i] 表示各组不同 a 条件下所能达到的最大高度
int dp[40001];

int main()
{
    int ans = 0;
    memset(dp, -1, sizeof(dp));
    scanf("%d", &K);
    // 输入数据，对于数量应该为原数量、限制高度/单个高度 两者的较小值
    for (int i = 0; i < K; i++)
    {
        scanf("%d %d %d", &data[i].h, &data[i].a, &data[i].c);
        data[i].c = min(data[i].c, data[i].a / data[i].h);
    }
    // 排序
    sort(data, data + K);
    dp[0] = 0;
    // 对于不同石块
    for (int i = 0; i < K; i++)
    {
        // 考察 0 - 最大高度是否能够被石块组合出来
        for (int j = 0; j < data[i].a; j++)
        {
            // 若之前出现过该石块，说明已经被组合出来，那么其数量应该为当前石块数量，
            // 即在原基础上再考虑新种类石块的增加
            if (dp[j] >= 0)
            {
                dp[j] = data[i].c;
            }
            // 若考虑的高度小于石块的高度或不能使用石块组合出该高度，那么将 dp 设为 -1
            else if (j < data[i].h || dp[j - data[i].h] <= 0)
            {
                dp[j] = -1;
            }
            // 若非上述两种情况，说明该高度还未出现过，需要新组合出来，那么需要使用一块当前石块
            else{
                dp[j] = dp[j - data[i].h] - 1;
            }
        }
    }
    // 由于最大高度应为石块种类中最大的高度限制，那么从该高度开始递减，若出现 dp 数值 >= 0 的情况
    // 说明该石块可以通过各种石块种类合成
    for (int i = data[K - 1].a; i >= 0; i--)
    {
        if (dp[i] >= 0)
        {
            ans = i;
            break;
        }
    }

    printf("%d", ans);
    return 0;
}
