#include <iostream>
#include <cstdio>
#include <algorithm>
#include <math.h>
#include <string.h>
using namespace std;
/*
本题贪心策略是尽快赶走每分钟吃的多的牛
解题思路：由少推到多
假设有两头牛，其参数为 T_X D_X T_Y D_Y
当先送 X 时： 2*T_X*D_Y
当先送 Y 时： 2*T_Y*D_X
对两式同时除以 2*D_X*D_Y
即：最后得到的为T和D的比值
*/
int N;
struct Cow{
    int T;
    int D;
    // 定义排序方式
    bool operator< (const Cow&c) const
    {
        return T * c.D < c.T * D;
    }
};

Cow cow[100000];
int main()
{
    while (scanf("%d", &N) != EOF)
    {
        int total = 0;
        for (int i = 0; i < N; i++)
        {
            // 输入每头牛的信息
            scanf("%d %d", &cow[i].T, &cow[i].D);
            // 总的每分钟破坏量
            total += cow[i].D;
        }

        // 按照 operator 中方式排序
        sort(cow, cow + N);

        int ans  = 0;
        for (int i = 0; i < N; i++)
        {
            // 赶走一头牛，剩余牛的每分钟破坏量
            total -= cow[i].D;
            // 剩余牛在 Ti 时间内的总破坏量，并累加
            ans += total * cow[i].T * 2;
        }

        printf("%d", ans);
    }

    return 0;
}
