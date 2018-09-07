#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;
/*
���� floyd ��������ˮ·����½·ʱ������֮������·
��d[i][j] ��ʾ�����˶��� i ��ʱ����ͣ�� j �����·
�������м�״̬�� d[i-1][k] ���� j == k ʱ��˵��ûʹ�ô�����ʱֱ�Ӽ�����֮���½·���·
�� j != k ʱ��˵��ʹ�ô���˵���ȴ� i-1 ��½·���м�״̬ m ���� m ��ˮ·�� j ���ٴ� j ��½·�� i
��ʱ����ͣ���� j
*/
int N, M, R;
int s[201][201];
int l[201][201]; // s �� l ����ֱ��ʾˮ·��½·�ıߵ�Ȩֵ����������ʱΪ inf ����ͬһ��ʱΪ 0
int b[1000];
int d[2000][201]; // d[i][j] ��ʾȥ�� i ��λ�ã������� j λ�õ���̾���
#define inf 0x3f3f3f3f

// ʹ�� floyd �㷨����ˮ·��½·����֮������·
void floyd(int n)
{
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                s[i][j] = min(s[i][j], s[i][k] + s[k][j]);
                l[i][j] = min(l[i][j], l[i][k] + l[k][j]);
            }
        }
    }
}

int main()
{
    while (scanf("%d %d", &N, &M))
    {
        // ��ʼ������
        memset(s, inf, sizeof(s));
        memset(l, inf, sizeof(l));
        memset(d, inf, sizeof(d));
        //memset(b, 0, sizeof(b));

        if (N == 0 && M == 0) break;
        while (M--)
        {
            int f, t, c;
            char x[2];
            // ����
            scanf("%d %d %d %s", &f, &t, &c, x);
            if (x[0] == 'L')
            {
                l[f][t] = min(l[f][t], c);
                l[t][f] = min(l[t][f], c);
            }
            else
            {
                s[f][t] = min(s[f][t], c);
                s[t][f] = min(s[t][f], c);
            }
        }

        // ͬһ��ıߵ�ȨֵΪ 0
        for (int i = 1; i <= N ;i++)
        {
            s[i][i] = 0;
            l[i][i] = 0;
        }
        // ������Ҫ�������˳��
        scanf("%d", &R);
        for (int i = 1; i <= R; i++)
        {
            scanf("%d", &b[i]);
        }

        floyd(N);
        // ���˴��� 1 �ţ������� i ��λ��ʱ��˵����Ҫ������ i ��������·�ص� 1
        for (int i = 1; i <= N; i++)
        {
            d[1][i] = min(d[1][i], s[b[1]][i] + l[i][b[1]]);
        }

        // ���ڲ�ͬĿ���յ� i ����λ�� j ��ǰһ״̬λ�� k ʱ
        for (int i = 1; i <= R; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                for (int k = 1; k <= N; k++)
                {
                    // ������λ�ò���ʱ��˵��ֻ��Ҫ��·���У�����ǰһ״̬�����ϼ�����֮���½·��̾�
                    if (j == k)
                    {
                        if (l[b[i-1]][b[i]] < inf)
                        {
                            d[i][j] = min(d[i][j], d[i-1][k] + l[b[i-1]][b[i]]);
                        }
                    }
                    // ����ͣ��λ�ñ仯��˵����Ҫ���Ǵ� i-1 ״̬��·�� k ���� k ������ j ���ڴ� j ��·�� i
                    else
                    {
                        if (l[b[i-1]][k] < inf && s[k][j] < inf && l[j][b[i]] < inf)
                        {
                            d[i][j] = min(d[i][j], d[i-1][k] + l[b[i-1]][k] + s[k][j] + l[j][b[i]]);
                        }
                    }
                }
            }
        }
        // ����ͬһ�յ� R ����ͬ�Ĵ�ͣ��λ�ã��������˶�����
        int ans = inf;
        for (int j = 1; j <= N; j++)
        {
            ans = min(ans, d[R][j]);
        }
        printf("%d", ans);
    }
    return 0;
}
