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

        // 当最早的开始试件和最晚的结束时间不满足要求时，直接返回 -1 ，并可以进行下次输入
        if (time[0].start > 1 || time[N].over < T)
        {
            printf("-1\n");
            continue;
        }

        // 定义初始牛的数量为 0
        int used_cows = 0;
        // 定义初始结束时间为 0
        int end = 0;
        // 定义初始索引为 0
        int index = 0;

        while (end < T)
        {
            // 下一头牛的开始时间最迟为前一头的结束时间 + 1
            int begin = end + 1;
            // 寻找一头能够从 begin 开始，并且结束时间最长的牛
            for (int i = index; i < N; i++)
            {
                // 判断能够覆盖起点，若不能，说明两头牛的工作时间之间存在间隔
                if (time[i].start <= begin)
                {
                    // 判断该牛的工作时间段能否覆盖它的开始时间点
                    if (time[i].over > begin)
                    {
                        // 将结束时间延长到最长
                        end = max(end, time[i].over);
                    }
                }
                // 若不能覆盖起点，说明上一头牛已经是最合适的了，需要考虑下一头牛
                else{
                    index = i;
                    break;
                }
            }

            // 若没有找到符合条件的牛，则返回 -1
            if (begin > end)
            {
                return -1;
            }
            // 找到符合条件的牛，需要的牛的数量 + 1
            else{
                used_cows++;
            }
        }
        printf("%d\n", used_cows);
    }

    return 0;
}
