#include <iostream>
#include <cstdio>
using namespace std;
int path[100][100];
int map[100][100];
int V, E; // 顶点和边的数量
#define inf 99999999 // 如何表示正无穷，一般定义为 99999999 ，因为这样即使两个正无穷相加，
                     // 扔不超过 int 类型
int from, to, cost;

void floyd(int V)
{
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
                    // path[i][j] = k 表示最短路径 i-j 的直接前驱为 k ，即 i-k-j
                    path[i][j] = k;
                }
            }
        }
    }
}

 void getPath(int i ,int j){
    if(i == j) return;
    if(path[i][j] == 0) printf("%d ", j);
    else{
        getPath(i, path[i][j]);
        getPath(path[i][j], j);
    }
}


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
    floyd(V);

    // 输出
    for(int i = 1; i <= V; i++)
    {
        for (int j = 1; j <= V; j++)
        {
            printf("%d ", map[i][j]);
        }
        cout << endl;
    }

    getPath(1, V);

    return 0;
}
