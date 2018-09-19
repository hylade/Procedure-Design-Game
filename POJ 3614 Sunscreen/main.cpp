#include <iostream>
#include <algorithm>
#include <cstdio>
#include <math.h>
#include <string.h>
#include <queue>
using namespace std;
/*
使用优先序列
首先需要确定使用贪心策略，在满足 minSPF 的条件下，尽量需要将 SPF 的防晒霜用在 maxSPF 较小的奶牛身上
因为 maxSPF 大的奶牛有更大的选择空间，用一个最小堆来维护 maxSPF 的最小值即可
*/
int C, L;
typedef pair <int, int> p;
p cow[2501], bot[2501];
// 优先队列，使用小元素优先出队
// 对于优先队列，可以声明三个参数，第一个是数据类型 type ，第二个是保存数据的容器 Container
// Container 可以为 vector 或者 deque 等，但不能使用 list ，默认是 vector
// 第三个参数是比较参数；若后两个参数缺省的话，表示大顶堆
priority_queue<int, vector<int>, greater<int> > q;

int main()
{
    scanf("%d %d", &C, &L);
    // 输入牛的信息， minSPF 和 maxSPF
    for (int i = 0; i < C; i++)
    {
        scanf("%d %d", &cow[i].first, &cow[i].second);
    }
    // 输入防晒霜的信息， SPF 和数量
    for (int i = 0; i < L; i++)
    {
        scanf("%d %d", &bot[i].first, &bot[i].second);
    }
    // 进行排序，从小到大，这样可以保证有效使用
    sort(cow, cow + C);
    sort(bot, bot + L);

    int j = 0, ans = 0;
    // 对于不同的防晒霜，搜索不同的牛，若防晒霜的 SPF 大于 牛的 minSPF
    // 便 push 牛的 maxSPF 到 q 队列里面，从小到大排序
    for (int i = 0; i < L; i++)
    {
        while (j < C && cow[j].first <= bot[i].first)
        {
            q.push(cow[j].second);
            j++;
        }
        // 搜索完成后，对 q 队列进行搜索，搜索完一个便 pop 掉一个
        // 若搜索到的数据大于该瓶防晒霜的 SPF ，说明可以使用，那么结果增加 1 ，并且该瓶防晒霜数量 -1
        // 搜索到 q 为空或者该防晒霜使用完毕
        while (!q.empty() && bot[i].second)
        {
            int x = q.top();
            q.pop();
            // 若 maxSPF 小于防晒霜的 SPF 说明不能使用
            if (x < bot[i].first)
            {
                continue;
            }
            ans++;
            bot[i].second--;
        }
    }
    printf("%d", ans);
    return 0;
}
