#include <iostream>
#include <cstdio>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;
/*
ͨ�� f[i] ��ʾ�ܼ�Ϊ i �ļ�ֵ�Ƿ��Ѿ����֣���û�У��Ǳ�һ����Ӳ��ȡ���ԣ����ɹ������ܷ��������� 1
��ͳ���ر��������������������ѭ�����ᳬʱ����Ϊֻ�������Ƿ���У���û�п���ʣ���������������

�˴�Ĥ¥�����ķ��������Ӷ� O(N * M)
*/
int N, M;
int A[100]; // Ӳ�Ҽ�ֵ
int C[100]; // Ӳ������
bool f[100000]; // ��ʾ��ǰ�۸� i �Ƿ���ֹ�
int sum[100000]; // ���۸񵽴� i ʱ��������һ��Ӳ�ҵĴ���

int main()
{
    while (scanf("%d %d", &N, &M))
    {
        int ans = 0;
        if (N == 0 && M == 0)
        {
            break;
        }

        for (int i = 0; i < N; i++)
        {
            scanf("%d", &A[i]);
        }
        for (int i = 0; i < N; i++)
        {
            scanf("%d", &C[i]);
        }

        f[0] = 1; // 0 �϶����ֹ�������Ϊ 1
        for (int i = 1; i <= M; i++)
        {
            f[i] = 0; // ������ 0 �����м۸��Ƿ���ֹ�����ʼ��Ϊ 0
        }

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j <= M; j++)
            {
                sum[j] = 0; // �ؼ������� sum �����˴���
            }
            for (int j = A[i]; j <= M; j++)
            {
                if (!f[j] && f[j - A[i]] && sum[j - A[i]] < C[i])
                {
                    // ���۸� j û�г��ֹ����� j - A[i] ���ֹ�������ʹ�� i ������û�г���
                    f[j] = 1;
                    ans++;
                    sum[j] = sum[j - A[i]] + 1; // ʹ�ô������� 1
                }
            }
        }
        printf("%d\n", ans);

    }

    return 0;
}
