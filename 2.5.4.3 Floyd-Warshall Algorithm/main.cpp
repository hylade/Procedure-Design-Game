#include <iostream>
#include <cstdio>
using namespace std;
/*
根据以往经验，任意两点之间的最短距离，需要引入第三个顶点，或者更多的顶点
比如只能经过 1 号顶点时，判断 e[i][j] 是否比 e[i][1] + e[1][j] 大
e[i][j] 表示从 i 号顶点到 j 号顶点之间的路程， e[i][1] + e[1][j] 表示
i 号顶点先到 1 号顶点，再从 1 号顶点到 j 号顶点的路程之和

所以，基本思想就是，最开始只允许经过 1 号顶点进行中转，接下来只允许经过 1 和 2
顶点进行中转...允许经过 1-n 所有顶点中转，求任意两点之间的最短路程

一句话概括就是，从 i 号顶点到 j 号顶点只经过前 k 号顶点的最短路程

该算法实现简单，但是时间复杂度较大
*/
int map[100][100];
int V, E; // 顶点和边的数量
#define inf 99999999 // 如何表示正无穷，一般定义为 99999999 ，因为这样即使两个正无穷相加，
                     // 扔不超过 int 类型
int from, to, cost;

int main()
{
    scanf("%d %d", &V, &E);
    for (int i = 1; i <= V; i++)
    {
        // 初始化
        for (int j = 1; j <= V; j++)
        {
            if (i == j)
            {
                map[i][j] = 0;
            }
            else
                map[i][j] = inf;
        }
    }

    // 输入信息
    for (int i = 1; i <= E; i++)
    {
        scanf("%d %d %d", &from, &to, &cost);
        map[from][to] = cost;
        map[to][from] = cost;
    }
    // 三重循环搜索最短路径
    for (int k = 1; k <= V; k++)
    {
        for (int i = 1; i <= V; i++)
        {
            for (int j = 1; j <= V; j++)
            {
                if (map[i][j] > map[i][k] + map[k][j])
                {
                    map[i][j] = map[i][k] + map[k][j];
                }
            }
        }
    }

    // 输出
    for(int i = 1; i <= V; i++)
    {
        for (int j = 1; j <= V; j++)
        {
            printf("%d ", map[i][j]);
        }
        cout << endl;
    }

    return 0;
}
