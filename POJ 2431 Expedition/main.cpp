#include <iostream>
#include <cstdio>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <queue>
using namespace std;
/*
题目要求：在卡车开往终点的途中，只有在加油站才可以加油。但若变化思考方式，认为在达到加油站 i 时
就可以在此之后任意地点位置，都可以使用 Bi 汽油的权利，若之后需要使用汽油，便认为是在经过加油站时加油便可

因为希望最终使用加油次数最小，那么当燃料为 0 再使用加油次数是最合理的，同时应该使用 Bi 中最大的加油站，那么
可以减少加油次数，故可以通过优先队列完成该过程

总的来说：
在经过加油站时，往优先队列力加入 Bi
当燃料箱空了之后：
1. 若优先队列中也是空的，则无法达到终点
2. 否则取出优先队列中的最大值，并用来给卡车加油
*/
int N, L, P;
int A[101], B[101];
priority_queue<int> que;

int main()
{
    scanf("%d %d %d", &N, &L, &P);
    for (int i = 0; i < N; i++)
    {
        // 输入加油站位置
        scanf("%d", &A[i]);
    }

    for (int i = 0; i < N; i++)
    {
        // 输入加油站提供的油量
        scanf("%d", &B[i]);
    }

    // 为了便利，将终点也作为一个不提供油量的加油站，位置为 L ，此时加油站数量 +1
    A[N] = L;
    B[N] = 0;
    N = N + 1;
    // 初始数据 ans 为加油次数， pos 为现在所处位置， tank 为邮箱中汽油存量
    int ans = 0, pos = 0, tank = P;
    for (int i = 0; i < N; i++)
    {
        // 到下个加油站需要运动的距离
        int d = A[i] - pos;
        // 不断加油直到在油量足够行驶到下个加油站，若不足以到终点时， que 将为空，此时输出 -1
        while (tank - d < 0)
        {
            if (que.empty())
            {
                printf("-1");
                return 0;
            }

            // 不足时，使用运动过程中能提供最多油量的加油站，油量使用后，需要 pop 掉，并且 ans + 1
            tank += que.top();
            que.pop();
            ans++;
        }
        // 运动到下一个加油站后，油量需要 -d ，位置更新，并且可以将该加油站的油量 push 到 que 中，备用
        tank -= d;
        pos = A[i];
        que.push(B[i]);
    }
    printf("%d", ans);
    return 0;
}
