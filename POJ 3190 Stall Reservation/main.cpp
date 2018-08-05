#include <iostream>
#include <cstdio>
#include <queue>
#include <math.h>
#include <algorithm>
using namespace std;
/*
将奶牛根据开始时间排序后，从第一头奶牛进行考虑，从牛棚的优先队列中返回结束时间最短的牛棚，检查
当前奶牛是否可以放入该牛棚中。如果能，就更新该牛棚的结束时间，更新为该奶牛的结束时间；如果不能，
就就创建一个新的牛棚，并将奶牛放入该牛棚中，重复操作，直到所有奶牛被放置完成
*/
int N;
int tag;
struct Interval{
    int left; // 开始时间
    int right; // 结束时间
    int no; // 牛棚编号
    int ss; // 输入编号
    // 结构体内不能随意使用原有操作符，需要对结构体运算符进行重载
    // bool 为函数类型，operator< 为函数名，括号中为参数
    friend bool operator< (Interval n1, Interval n2)
    {
        // 从小到大排列
        // 若返回值 <=-1 ，说明前者排列在后者前
        // 若返回值在 -1 至 1 之间，说明两者排列顺序相同
        // 若返回值 >= 1 ，说明前者排列在后者后面
        return n1.right > n2.right;
    }
};
Interval time[50005];

// 用于贪心排序
bool sor1(Interval a, Interval b)
{
    if (a.left == b.left)
    {
        return a.right < b.right;
    }
    else{
        return a.left < b.left;
    }
}
// 用于输出排序
bool sor2(Interval a, Interval b)
{
    return a.ss < b.ss;
}

int main()
{
    while (~scanf("%d", &N) != EOF)
    {
        // co 为牛棚个数
        int co = 0;
        // tag 用于标记当前最小的结束时间
        tag = 0;
        // 输入各组时间并对各组进行标记，以便按照顺序输出
        for (int i = 0; i < N; i++)
        {
            scanf("%d %d", &time[i].left, &time[i].right);
            time[i].ss = i;
        }

        // 按照开始时间从大到小排序
        sort(time, time + N, sor1);
        // 将 tag 的初始值设为 第一头牛的开始时间，此时为最早开始时间，那么第一头必定会需要牛棚
        tag = time[0].left;

        // 定义优先序列
        priority_queue <Interval> que;

        for (int i = 0; i < N; i++)
        {
            // 当当前牛棚中最小的结束时间都大于这头牛的开始时间，说明两者时间段重叠
            // 需要使用不同的牛棚
            if (tag >= time[i].left)
            {
                // 使用新的牛棚，数量 +1
                co++;
                // 给牛的牛棚编号赋值
                time[i].no = co;
                // 并 push 到 que 中，与后续牛进行对比
                que.push(time[i]);
                // 更新右边界，优先队列根据结构体 Interval 中的函数，队头是右边界最小的值
                // 因为位于其他牛棚的牛的时间间隔必定与右边界最小的牛的时间间隔至少有一部分重合
                // 则不需要与其他牛棚比较，与当前最小的右边界比较一定是最优的
                tag = que.top().right;
            }
            else{
                // 当最小的结束时间小于这头牛的开始时间时，说明两者可以使用同一个牛棚，将该牛棚编号赋给这头牛
                time[i].no = que.top().no;
                // 由于此时优先队列中排列方式是以右边界从小到大排列，所以 pop 出去的便是最小结束时间的牛
                que.pop();
                // 此时可以将这头牛 push 到队列里，并开始下次搜索
                que.push(time[i]);
                // 由于进来了新的牛，需要重新考虑最小右边界
                tag = que.top().right;
            }
        }

        printf("%d", co);
        // 输出时需要按照输入的编号，所以按照 sor2 的方式重新进行排列
        sort(time, time + N, sor2);
        for (int i = 0; i < N; i++)
        {
            printf("%d", time[i].no);
        }

    }


    return 0;
}
