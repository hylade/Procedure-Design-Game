#include <iostream>
#include <cstdio>
using namespace std;
/*
��ͨ Dijkstra �㷨��ͨ���ڽӾ���ʵ��
*/
// �ڽӾ���
int map[100][100];
int V, E;
// �Ƿ���ʹ�
int visit[100];
// ���·��
int minroad[100];
#define inf 0x7f7f7f7f
int f, t, cost;
int next;

int main()
{
    while (scanf("%d %d", &V, &E), V || E)
    {
        // ��ʼ��
        for (int i = 1; i <= V; i++)
        {
            minroad[i] = inf;
            visit[i] = 0;
            for (int j = 1; j <= V; j++)
            {
                map[i][j] = inf;
            }
        }

        // �����������
        while (E--)
        {
            scanf("%d %d %d", &f, &t, &cost);
            map[f][t] = map[t][f] = cost;
        }
        // �ӵ� 1 ��ʼ����
        int start = 1;
        visit[1] = 1;
        minroad[start] = 0;
        while (start != V)
        {
            int minx = inf;
            // ��������Ҫ�������� start ����ͨ�������Ǿ�����̵�
            for (int i = 1; i <= V; i++)
            {
                if (map[start][i] != inf)
                {
                    minroad[i] = min(minroad[i], minroad[start] + map[start][i]);
                }
                if (!visit[i] && minroad[i] < minx)
                {
                    next = i;
                    minx = minroad[i];
                }
            }
            // �������ĵ���Ϊ�¸����ٽ�������������ֱ���ҵ� V
            visit[next] = 1;
            start = next;
        }
        printf("%d\n", minroad[V]);
    }

    return 0;
}
