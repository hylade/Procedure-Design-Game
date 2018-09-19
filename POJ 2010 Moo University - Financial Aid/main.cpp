#include <iostream>
#include <math.h>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <string.h>
using namespace std;
/*
优先队列 + 枚举 + 分治
将奶牛按照成绩 s 从小到大排序，从 N/2 ~ C-1-N/2 枚举中位数
记录每个 i 前面 N/2 个 f 之和，及后面 N/2 个 f 之和
然后枚举满足条件最大的中位数
*/
int N, C, F;
// 创建牛信息结构体，并重载，按照 f 从大到小排序
struct node{
    int s, f;
    bool operator < (const node &a) const
    {
        return f < a.f;
    }
}cow[100001];
// 优先队列， f 大的元素优先出队列
priority_queue<node> ql, qr;
int minl[100001], minr[100001];
bool cmp(node a, node b)
{
    return a.s < b.s;
}

int main()
{
    scanf("%d %d %d", &N, &C, &F);
    // 输入各头牛的乘积和 aid 数量
    for (int i = 0; i < C; i++)
    {
        scanf("%d %d", &cow[i].s, &cow[i].f);
    }

    // 按照 cmp 规则排序，若设置 cmp 函数，由于此处在 node 结构体中有重载，故按照重载规则排序
    // 若同时不存在重载规则，那么就会报错，不能缺省或者使用 less<> 方法
    sort(cow, cow + C, cmp);
    int suml = 0, sumr = 0;

    // 查找对于每个 i 左边 N/2 个元素的最小和
    for (int i = 0; i < C; i++)
    {
        // 当小于时，说明左边不足要求的数量，便将这几个数值相加
        if (i < N / 2)
        {
            ql.push(cow[i]);
            suml += cow[i].f;
            continue;
        }
        // 当出现第一个满足左边有 N/2 个数时，便将该值赋给其 minl[i]
        // 同时，考虑最小和的变化，若新的 f 比 ql 中最大的 f 小，便进行替换
        minl[i] = suml;
        if (cow[i].f < ql.top().f)
        {
            suml -= ql.top().f;
            ql.pop();
            ql.push(cow[i]);
            suml += cow[i].f;
        }
    }

    // 同理，查找对于每个 i 右边 N/2 个元素的最小和
    for (int i = C - 1; i >= 0; i--)
    {
        if (i > C - 1 - N / 2)
        {
            qr.push(cow[i]);
            sumr += cow[i].f;
            continue;
        }
        minr[i] = sumr;
        if (cow[i].f < qr.top().f)
        {
            sumr -= qr.top().f;
            qr.pop();
            qr.push(cow[i]);
            sumr += cow[i].f;
        }
    }

    int ans = -1;
    // 从大到小枚举满足条件的 cow[i].s 这样能保证找到的 s 最大
    // 同时，范围应该是 N/2 ~ C-1-N/2
    for (int i = C - 1 - N / 2; i >= N / 2; i--)
    {
        if (cow[i].f + minl[i] + minr[i] <= F)
        {
            ans = cow[i].s;
            break;
        }
    }
    printf("%d", ans);

    return 0;
}
