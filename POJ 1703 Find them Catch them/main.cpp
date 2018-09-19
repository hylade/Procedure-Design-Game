#include <iostream>
#include <cstdio>
using namespace std;
/*
将并查集中的 i-x 定义为 i 属于 x 帮派
同一个并查集中的元素同时成立

所以需要元素个数为 2*N ，如果 i 表示属于帮派 A ，那么 i+N 表示属于帮派 B
每次输入两个家伙不在同一帮派，那么就合并 x-A y-B 和 x-B y-A
*/
int p[100001];
int r[100001];
int T, N, M;
int x, y;
char operation; // 操作命令

void init(int N)
{
    for (int i = 0; i < N; i++)
    {
        p[i] = i;
        r[i] = 0;
    }
}

int find(int x)
{
    if (p[x] == x) return x;
    else{
        return p[x] = find(p[x]);
    }
}

void unite(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x == y)
    {
        return;
    }
    else if (r[x] < r[y])
        p[x] = y;
    else
    {
        p[y] = x;
        if (r[x] == r[y])
        {
            r[x]++;
        }
    }
}

bool same(int x, int y)
{
    return find(x) == find(y);
}

int main()
{
    // 试验次数
    scanf("%d", &T);
    while (T--)
    {
        // 输入个数和条数
        scanf("%d %d", &N, &M);
        // 初始化
        init(2 * N);
        for (int i = 0; i < M; i++)
        {
            scanf("%s", &operation);
            scanf("%d %d", &x, &y);
            if (operation == 'A')
            {
                // 若已在同一帮派中，即 x-A y-A 或 x-B y-B
                if (same(x, y))
                    printf("In the same gang.");
                    // 若不在同一帮派，即 x-A y-B 或 x-B y-A
                else if (same(x, y + N))
                    printf("In different gangs.");
                    // 否则说明还没有关系
                else
                    printf("Not sure yet.");
            }
            // 若为 D ，则合并 x-A y-B 或 x-B y-A
            else
            {
                unite(x, y + N);
                unite(x + N , y);
            }
        }
    }

    return 0;
}
