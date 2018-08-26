#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;
/*
���������࣬����ʹ�� Floyd �㷨
*/
int N;
int from, to, dis;
#define inf 0x3f3f3f3f // ������Ҫ������ˣ�������������Ҳ������������ָ������
int cost[11][11]; // ��ʾ�� i-j ��Ȩֵ���� i=j ʱ�� ȨֵΪ 0
int V;

int main()
{
    while (scanf("%d", &N) && N)
    {
        V = 0;
        memset(cost, inf, sizeof(cost));
        for (int i = 0; i < N; i++)
        {
            cost[i][i] = 0;
        }
        // ����
        for (int i = 0; i < N; i++)
        {
            scanf("%d %d %d", &from, &to, &dis);
            cost[from][to] = dis;
            cost[to][from] = dis;
            V = max(V, max(from, to));
        }

        // Floyd �㷨
        for (int k = 0; k <= V; k++)
        {
            for (int i = 0; i <= V; i++)
            {
                for (int j = 0; j <= V; j++)
                {
                    cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
                }
            }
        }

        // �ҵ�һ�����������������̵ĵ�
        int ans = inf, loc;
        for (int i = 0; i <= V; i++)
        {
            int t = 0;
            for (int j = 0; j <= V; j++)
            {
                if (i == j) continue;
                t += cost[i][j];
            }
            if (t < ans) ans = t, loc = i;
        }

        printf("%d %d", ans, loc);
    }
    return 0;
}
