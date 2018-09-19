#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define inf 0x7f7f7f7f
int V, E;
struct Edge
{
    int u, v;
    int cost;
};
Edge edge[100];
int d[100];

bool Bellman_Ford(int s)
{
    // ��ʼ��
    for (int i = 1; i <= V; i++)
    {
        d[i] = inf;
    }
    d[s] = 0;
    // ���ÿ����������ӵı�
    for (int i = 0; i <= V-1; i++)
    {
        for (int j = 1; j <= E; j++)
        {
            if (d[edge[j].v] > d[edge[j].u] + edge[j].cost)
            {
                d[edge[j].v] = d[edge[j].u] + edge[j].cost;
            }
        }
    }
    // �������
    bool flag = 1;
    for (int i = 1; i <= E; i++)
    {
        if (d[edge[i].v] > d[edge[i].u] + edge[i].cost)
        {
            flag = 0;
            break;
        }
    }
    return flag;
}


int main()
{
    scanf("%d %d", &V, &E);
    // ���������
    for (int i = 1; i <= E; i++)
    {
        scanf("%d %d %d", &edge[i].u, &edge[i].v, &edge[i].cost);
    }
    if (Bellman_Ford(1))
    {
        for (int i = 1; i <= V; i++)
        {
            printf("%d\n", d[i]);
        }
    }
    else
    {
        printf("Negative circle\n");
    }


    return 0;
}
