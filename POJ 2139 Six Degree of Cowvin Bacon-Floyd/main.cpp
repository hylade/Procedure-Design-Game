#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;
/*
������ţ�Ķ���ƽ��ֵ��С��Ҳ�����ҵ����еĶ����ܺ���С����ô�����ҵ���ͷţ������ÿͷţ����С��
Ҳ�������·��������ٳ��� n-1 �ȵ���Сƽ��ֵ������ö�ٻ����С·�����ټ�¼��Сƽ��ֵ
*/
int N, M;
int cost[301][301];
int a[301];
#define inf 0x3f3f3f3f

// �����㷨
void Floyd()
{
    for (int k = 0; k < N; k++)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
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
        // �˴���Ҫע��������ص㣬ÿ�ζ��� a[i] a[i]+1 a[i]+2 ...
        for (int i = 0; i < T; i++)
        {
            for (int j = i+1; j < T; j++)
            {
                cost[a[i]][a[j]] = cost[a[j]][a[i]] = 1;
            }
        }
    }

    Floyd();
    // �ҵ���Сֵ�����
    int ans = inf;
    for (int i = 0; i < N; i++)
    {
        int sum = 0;
        for (int j = 0; j < N; j++)
        {
            sum += cost[i][j];
        }
        ans = min(ans, sum);
    }
    ans = 100 * ans / (N-1);
    printf("%d", ans);

    return 0;
}
