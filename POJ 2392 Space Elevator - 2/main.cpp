#include <iostream>
#include <algorithm>
#include <cstdio>
#include <math.h>
#include <string.h>
using namespace std;
/*
版本 -1 中采用三重循环时间复杂度较大，可以进行优化，直接标记能够到达的最高点
*/
int K;
// 按照每组数据中的 a 进行从小到大排序
struct node{
    int h, a, c;
    bool operator< (const node b) const{
        return a < b.a;
    }
}data[401];
// dp[i] 表示当前能达到的最大高度为 i
// cn[i] 表示当前数据组使用的数量，需要小于 node.c
bool dp[40001];
int cn[40001];

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
    // 0 的时候肯定是可以达到的，故初始化为 1
    dp[0] = 1;

    for (int i = 0; i < K; i++)
    {
        // 对于不同的数据组，都要初始化使用数量数组 cn
        memset(cn, 0, sizeof(cn));
        for (int j = data[i].h; j <= data[i].a; j++)
        {
            // 当该高度没有出现过并且前一个高度出现过，并且数量还没有用完时
            if (!dp[j] && dp[j - data[i].h && cn[j - data[i].h] + 1 < data[i].c)
            {
                dp[j] = true;
                cn[j] = cn[j - data[i].h] + 1;
                if (ans < j)
                {
                    ans = j;
                }
            }
        }
    }
    }

    printf("%d", ans);
    return 0;
}
