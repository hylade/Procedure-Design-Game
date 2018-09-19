#include <iostream>
#include <cstdio>
using namespace std;
/*
基本思路：
用并查集来保存电脑互相的连通情况
每次修好点好后，将它可以通信的电脑（距离满足且已经修好）与它连通
*/
int p[1010];
int r[1010];
int N, d;
char operation; // 操作 O 还是 S
int x, y;
bool status[1010]; // 是否修好
pair<int, int> computer[1010];
int square(int x)
{
    return x * x; // 距离平方
}

void init(int n)
{
    for (int i = 0; i < n; i++)
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

    if (r[x] < r[y])
    {
        p[x] = y;
    }
    else{
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
    scanf("%d %d", &N, &d);
    for(int i = 0; i < N; i++)
    {
        scanf("%d %d", &computer[i].first, &computer[i].second);
    }

    init(N);
    while (scanf("%s", &operation))
    {
        if (operation == 'O')
        {
            scanf("%d", &x);
            x -= 1; // 防止超限 -1
            status[x] = true;
            for (int i = 0; i < N; i++)
            {
                if (x == i) // 若为同一点，则搜索下一点
                {
                    continue;
                }
                else{
                        // 若修好且距离满足要求则添加入并查集
                    if (status[i] && square(computer[x].first-computer[i].first) + square(computer[x].second - computer[i].second) <= square(d))
                    {
                        unite(x, i);
                    }
                }
            }
        }
        else
        {
            // 若为 S
            scanf("%d %d", &x, &y);
            x -= 1;
            y -= 1;
            // 是否连通，即是否在同一棵树中
            if (same(x, y))
            {
                printf("SUCCESS");
            }
            else
            {
                printf("FAIL");
            }
        }
    }

    return 0;
}
