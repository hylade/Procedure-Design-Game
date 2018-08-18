#include <iostream>
#include <cstdio>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <queue>
using namespace std;
/*
本题与 2.2 节中的 Fence Repair 题目相同，但 2.2 节中使用的二重循环，复杂度需要 O(n^2)
但若使用优先队列，每次从队列中取出最短的两块，并且将长度为两块板长度之和的板加入到队列中即可
因此时间复杂度只需 O(nlogn)
*/
int N, ans, L[20001];
// 声明一个从小到大排序的优先队列 que
priority_queue<int, vector<int>, greater<int> > que;

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &L[i]);
    }
    for (int i = 0; i < N; i++)
    {
        que.push(L[i]);
    }

    // 循环到只有一块木板为止，这块木板是最终合成的木板
    while (que.size() > 1)
    {
        // 取出最长的木板和最短的木板
        int first = que.top();
        que.pop();
        int second = que.top();
        que.pop();
        // 相加，并 push 到 que 里面，并在 ans 上累加
        int t = first + second;
        ans += t;
        que.push(t);
    }
    printf("%d", ans);
    return 0;
}
