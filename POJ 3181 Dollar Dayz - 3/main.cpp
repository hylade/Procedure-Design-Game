#include <iostream>
#include <cstdio>
#include <algorithm>
#include <math.h>
#include <string.h>
using namespace std;
/*
���� �汾 -2 �е����飬��ʵ���Լ�Ϊһά����
*/
int N, K;
unsigned long long a[1005],b[1005],inf=1;

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
            a[0] = 1;
        }

        for (int i = 1; i <= K; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                if (j >= i)
                {
                    // �������ǰ��Ĳ��֣������� int64 ʱ���Ϳ�ʼ���� b ���飬��Ϊ int64 �� 10^18 �η�����֤������ a ���ʱ���ᳬ�� int64
                    // ����ֻ�� a[0] ��ʼ��������ֻ�е� a �����ֵ���� inf ʱ�� b �����вŻ�����ֵ����
                    b[j] = (b[j] + b[j - i]) + (a[j] + a[j - i]) / inf;
                    a[j] = (a[j] + a[j - i]) % inf;
                }
            }
        }
        if(b[N])
            cout << b[N];
        cout << a[N] << endl;
    }
    return 0;
}

