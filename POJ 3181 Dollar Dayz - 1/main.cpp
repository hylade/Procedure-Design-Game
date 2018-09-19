#include <iostream>
#include <cstdio>
#include <algorithm>
#include <math.h>
#include <string.h>
using namespace std;
/*
����˼·��
��֤�� N ����Ϊһϵ��������֮�ͣ���󲻳��� K ����Ϊ���� N �� K ����
dp[i][j] ����Ϊ ���� i �� j ���� �ķ�����

�� j > i ʱ����ʱ dp[i][j] = dp[i][i]
�� i == j ʱ����ʱ dp[i][j] = dp[i][j - 1] + 1
�������������Ҫ�����Ƿ���� j ���� dp[i][j] = dp[i - j][j] + dp[i][j - 1]

�����ڱ�������û�п��ǵ������������������� N �� K �ϴ�ʱ�������������������Ҫ��
����ο� -2 �汾
*/
int N, K;
int dp[1001][101];

int main()
{
    while (scanf("%d %d", &N, &K))
    {
        if (N == 0 && K == 0)
        {
            break;
        }

        // ���� 0 ���κ���������Ӧ�ö�Ϊ 1
        for (int i = 0; i <= K; i++)
        {
            dp[0][i] = 1;
        }

        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= K; j++)
            {
                if (i < j) dp[i][j] = dp[i][i];
                else if (i == j) dp[i][j] = dp[i][j - 1] + 1;
                else dp[i][j] = dp[i][j - 1] + dp[i - j][j];
            }
        }

        printf("%d", dp[N][K]);
    }

    return 0;
}
