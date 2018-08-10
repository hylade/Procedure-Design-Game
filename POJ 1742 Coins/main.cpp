#include <iostream>
#include <cstdio>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;
/*
通过 f[i] 表示总价为 i 的价值是否已经出现，若没有，那便一个个硬币取尝试，若成功，则总方法数增加 1
传统多重背包可行性问题采用三重循环，会超时，因为只考虑了是否可行，并没有考虑剩余面额数量的因素

此处膜楼教主的方法，复杂度 O(N * M)
*/
int N, M;
int A[100]; // 硬币价值
int C[100]; // 硬币数量
bool f[100000]; // 表示当前价格 i 是否出现过
int sum[100000]; // 当价格到达 i 时，出现这一种硬币的次数

int main()
{
    while (scanf("%d %d", &N, &M))
    {
        int ans = 0;
        if (N == 0 && M == 0)
        {
            break;
        }

        for (int i = 0; i < N; i++)
        {
            scanf("%d", &A[i]);
        }
        for (int i = 0; i < N; i++)
        {
            scanf("%d", &C[i]);
        }

        f[0] = 1; // 0 肯定出现过，所以为 1
        for (int i = 1; i <= M; i++)
        {
            f[i] = 0; // 将大于 0 的所有价格是否出现过都初始化为 0
        }

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j <= M; j++)
            {
                sum[j] = 0; // 关键在于用 sum 限制了次数
            }
            for (int j = A[i]; j <= M; j++)
            {
                if (!f[j] && f[j - A[i]] && sum[j - A[i]] < C[i])
                {
                    // 若价格 j 没有出现过，且 j - A[i] 出现过，并且使用 i 的数量没有超限
                    f[j] = 1;
                    ans++;
                    sum[j] = sum[j - A[i]] + 1; // 使用次数增加 1
                }
            }
        }
        printf("%d\n", ans);

    }

    return 0;
}
