#include <iostream>
#include <cstdio>
#include <algorithm>
#include <math.h>
#include <string.h>
using namespace std;
/*
���� dp ���� dp[i][j] ��ʾ�� i �� �� j ������ܵõ�����߷֣��ɶ������Ƶ����� dp ����
*/
int N;
// ���� dp ����
int dp[350][350];
// �������λ�õķ���
int score[350][350];

int main()
{
    while (scanf("%d", &N)!= EOF)
    {
        // ���������ע����������ʽ���������뷽ʽ������
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                scanf("%d", &score[i][j]);
            }
        }

        // dp[0][0] ʱ��Ϊ��ʼ�÷�
        dp[0][0] = score[0][0];

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                // ת��
                dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + score[i + 1][j + 1]);
                dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + score[i + 1][j]);
            }
        }

        int ans = 0;
        for (int i = 0; i < N; i++)
        {
            // �����һ�н��� max ����
            ans = max(ans, dp[N][i]);
        }
        printf("%d", ans);
    }

    return 0;
}
