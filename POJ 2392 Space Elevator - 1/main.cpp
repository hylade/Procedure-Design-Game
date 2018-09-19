#include <iostream>
#include <algorithm>
#include <cstdio>
#include <math.h>
#include <string.h>
using namespace std;
/*
多重背包，需要注意对石块能到达的最大高度 a 进行排序，防止石塔到达一定高度后，剩下的一些石块所能到达的高度小于该高度
那么剩下的石块就不能往上放了，应该先放置最大高度小的石块
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
    memset(dp, 0, sizeof(dp));
    scanf("%d", &K);
    // 输入数据，对于数量应该为原数量、限制高度/单个高度 两者的较小值
    for (int i = 0; i < K; i++)
    {
        scanf("%d %d %d", &data[i].h, &data[i].a, &data[i].c);
        data[i].c = min(data[i].c, data[i].a / data[i].h);
    }
    // 排序
    sort(data, data + K);
    // 多次 01 背包
    for (int i = 0; i < K; i++)
    {
        for (int j = 0; j < data[i].c; j++)
        {
            for (int k = data[i].a; k >= data[i].h; k--) // 01 背包逆序求解，要保证前一个阶段的结果没有发生改变
            {
                dp[k] = max(dp[k], dp[k - data[i].h] + data[i].h);
                // 找到高度最大值
                if (ans < dp[k])
                {
                    ans = dp[k];
                }
            }
        }
    }

    printf("%d", ans);
    return 0;
}
