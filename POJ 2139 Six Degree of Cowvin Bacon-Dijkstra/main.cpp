#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;

int N, M;
int cost[301][301];
int visit[301];
int d[301];
int a[301];
int next;
#define inf 0x3f3f3f3f

void dijkstra(int s)
{
    // �ȸ����������ڵ��·��
    for (int i = 0; i < N; i++)
    {
        d[i] = cost[s][i];
    }
    // ����Ѿ����ʹ�
    visit[s] = 1;

    // �ҵ�δ���ʹ����У�����������С�ĵ�
    for (int i = 0; i < N; i++)
    {
        int min = inf;
        for (int j = 0; j < N; j++)
        {
            if (!visit[j] && d[j] < min)
            {
                next = j;
                min = d[j];
            }
        }

        // ���¸õ㵽���ڵ�ľ���
        visit[next] = 1;
        for (int j = 0; j < N; j++)
        {
            if (!visit[j] && d[j] > d[next] + cost[next][j])
            {
                d[j] = d[next] + cost[next][j];
            }
        }
    }
}
int main()
{
    scanf("%d %d", &N, &M);
    // ��ʼ��
    memset(cost, inf, sizeof(cost));
    for (int i = 0; i < N; i++)
    {
        cost[i][i] = 0;
    }

    // ����
    while (M--)
    {
        int T;
        scanf("%d", &T);
        for (int i = 0; i < T; i++)
        {
            scanf("%d", &a[i]);
            a[i]--;
        }
        for (int i = 0; i < T; i++)
        {
            for (int j = 0; j < T; j++)
            {
                if (a[i] != a[j])
                {
                    cost[a[i]][a[j]] = cost[a[j]][a[i]] = 1;
                }
            }
        }
    }

    double ans = inf;
    // ö��ÿһͷţ���Ӷ��ҵ���С��
    for (int i = 0; i < N; i++)
    {
        double sum = 0;
        dijkstra(i);
        // ��¼�����ͣ������� ans
        for (int j = 0; j < N; j++)
        {
            if (i != j) sum += d[j];
        }
        ans = min(ans, sum);
    }
    ans = ans * 100 / (N - 1);
    printf("%lf", ans);

    return 0;
}
