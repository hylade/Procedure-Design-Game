#include <iostream>
#include <cstdio>
#include <algorithm>
#include <math.h>
#include <string.h>
using namespace std;
/*
����˼·��
1. �� n Ϊ����ʱ�� f[n] = f[n - 1] ����Ϊ��ʱֻ��Ҫ������ԭ����ǰ����һ�� 1 ���ɣ������ظ�����
2. �� n Ϊż��ʱ����Ҫ��Ϊ����������������д��� 1 ʱ������ f[n - 1] �������� 1 ��֮�������
��������û�д� 1 ������λΪ 2 ʱ�������� f[n / 2] ���� * 2 ֮������У��ʴ�ʱ f[n] = f[n - 1] + f[n / 2]
*/
int N;
int dp[100000];

int main()
{
    dp[1] = 1;
    while (scanf("%d", &N) != EOF)
    {
        for (int i = 2; i <= N; i++)
        {
            if (i % 2 == 1)
            {
                dp[i] = dp[i - 1];
            }

            else
            {
                dp[i] = dp[i - 1] + dp[i / 2];
            }
            dp[i] %= 1000000000; // ���ڵ� N �Դ�ʱ�� dp[N] ����ֵ���ܴ�ģ 1000000000 ��ֻ����� 9 λ
        }
        printf("%d\n", dp[N]);
    }


    return 0;
}
