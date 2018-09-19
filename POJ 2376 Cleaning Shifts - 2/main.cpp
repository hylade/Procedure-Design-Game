#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
// 定义 inf
#define inf 0x7f7f7f7f
// 定义组数和时间
int N, T;
// 定义每只牛的开始时间和结束时间的结构体
struct Interval{
    int start, over;
};
Interval time[25001];

// 定义排序方式
bool sor(Interval a, Interval b)
{
    // 当开始时间相同时，结束时间早的排在前面
    if (a.start == b.start)
    {
        return a.over < b.over;
    }
    // 当开始时间不相同时，开始时间早的排在前面
    else
    {
        return a.start < b.start;
    }
}


int main()
{
    // 多次输入
    while (~scanf("%d %d", &N, &T) != EOF)
    {
        // 初始化数组
        for (int i = 0; i < N; i++)
        {
            time[i].start = inf;
            time[i].over = inf;
        }
        // 数组赋值
        for (int i = 0; i < N; i++)
        {
            scanf("%d %d", &time[i].start, &time[i].over);
        }

        // 使用 sort 方法按照 sor 排列 time 数组
        sort(time, time + N, sor);

        // 当最早的开始时间不满足要求时，直接返回 -1 ，并可以进行下次输入
        if (time[0].start > 1)
        {
            printf("-1\n");
            continue;
        }

        // 定义牛的数量从 1 开始，并且此时它的索引 id 为 0
        int ans = 1, id = 0;

        // 进行搜索
        for (int i = 0; i < N; )
        {
            // cnt 用于确定当前满足要求（开始时间比上一头牛结束时间 + 1 小，并且结束时间比上一头牛结束时间 + 1 大）的牛的索引值
            // 初始化为 0
            int cnt = 0;
            // j 可以从 i + 1 开始搜索
            for (int j = i + 1; j < N; j++)
            {
                // 当开始时间大于上一头牛的结束时间 + 1 时，说明两者之间存在时间间隔，不符合要求
                // 此时可以跳出 for 循环，进行 cnt 的判断，若 cnt = 0 ， 说明此次循环中之前的数值都没有符合要求的
                // 此时可以循环至下一个值再进行搜索
                // 若 cnt 不为 0 ，说明之前找到过满足要求的解，将那个头的索引赋值给 id 和 i ，即将 cnt 的这头牛作为新的
                // 起点进行搜索，同时牛的数量 + 1
                if (time[j].start > time[id].over + 1)
                {
                    break;
                }
                // 判断是否该牛的时间区域覆盖前一头牛结束时间 + 1 ，若满足，则符合要求
                if (time[j].start >= time[id].start && time[j].over > time[id].over + 1)
                {
                    // 判断新找到符合要求的牛是否比之前找到的牛的结束时间更大，若大，则更新 cnt 值
                    if (time[j].over > time[cnt].over)
                    {
                        cnt = j;
                    }
                }
            }

            if (cnt == 0)
            {
                i++;
            }

            else{
                id = cnt;
                ans++;
                i = id;
            }
        }

        // 当最后循环完成后最后一头牛的结束时间若为 T ，则说明找到方案，否则则输出 -1
        if (time[id].over == T)
        {
            printf("%d\n", ans);
        }
        else{
            printf("-1\n");
        }
    }

    return 0;
}
