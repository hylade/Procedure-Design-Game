#include <iostream>
#include <cstdio>
#include <algorithm>
#include <math.h>
#include <string.h>
using namespace std;
/*
������ʵ�ʿ������ ��ȫ�����ʹ�������
���� dp[i][j] ��ʾ���� i �м۸������� j �ķ�����
��ô dp[i][0] = 1 ��ʹ���κμ۸������� 0 �ķ����������� 1
��������У� dp[i][j] = dp[i - 1][j] + dp[i - 1][j - i] + dp[i - 1][j - 2*i] + ... + dp[i - 1][0]
*/
int N, K;
unsigned long long a[105][1005],b[105][1005],inf=1;

int main()
{
    while (scanf("%d %d", &N, &K))
    {
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        if (N == 0 && K == 0)
        {
            break;
        }
        inf = 1;
        for (int i = 1; i < 18; i++)
        {
            inf *= 10;
        }

        // ʹ���κμ۸�������Ϊ 0 �ķ��������� 1
        for (int i = 0; i <= K; i++)
        {
            a[i][0] = 1;
        }

        for (int i = 1; i <= K; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                // �� i > j ʱ˵�������С�ڼ۸���������Ҫ��ô��ļ۸�Ӧ����С�۸��������
                if (i > j)
                {
                    a[i][j] = a[i - 1][j];
                    b[i][j] = b[i - 1][j];
                }
                else{
                        // �������ǰ��Ĳ��֣������� int64 ʱ���Ϳ�ʼ���� b ���飬��Ϊ int64 �� 10^18 �η�����֤������ a ���ʱ���ᳬ�� int64
                        // ����ֻ�� a[i][0] ��ʼ��������ֻ�е� a �����ֵ���� inf ʱ�� b �����вŻ�����ֵ����
                    b[i][j] = (b[i - 1][j] + b[i][j - i]) + (a[i - 1][j] + a[i][j - i]) / inf;
                    a[i][j] = (a[i - 1][j] + a[i][j - i]) % inf;
                }
            }
        }
        if(b[K][N])
            cout << b[K][N];
        cout << a[K][N];
    }
    return 0;
}

