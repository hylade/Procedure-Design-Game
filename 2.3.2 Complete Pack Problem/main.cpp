#include <iostream>
#include <cstdio>
using namespace std;
/*
��ȫ���������У�ͬһ�������Ʒ����ѡ��������
�� dp[i + 1][j] ��ʾ ��ǰ i ����Ʒ����ѡ������������ j ʱ�ܼ�ֵ�����ֵ
���ƹ�ϵ���£�
dp[0][j] = 0
dp[i + 1][j] ���� dp �����ʼ��Ϊ 0 ������ӦΪ dp[i + 1][j] �� dp[i][j - k * w[i]] + k * v[i] �Ľϴ�ֵ
״̬ת�ƣ�ǰ i + 1 ����Ʒѡȡ���ز����� j ��״̬�� ǰ i ����Ʒѡȡ���ز����� j ��״̬
*/

/*
��һ�ַ�����������ѭ�����������п����ԣ�����ʱ k ��ѭ������ܴ� 0 �� W ��
��������㷨�ĸ��Ӷ�Ϊ O(nW^2)
*/
// ��һ�ַ���������ѭ��
/*
int n, W;
int w[100], v[100];
int dp[101][101];
int main()
{
    scanf("%d %d", &n, &W);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &w[i], &v[i]);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            for (int k = 0; k * w[i] <= j; k++)
            {
                dp[i + 1][j] = max(dp[i + 1][j], dp[i][j - k * w[i]] + k * v[i]);
            }
        }
    }
    printf("%d", dp[n][W]);

    return 0;
}
*/


/*
��������ѭ���У��㷨���ж���ļ���
���� dp[i + 1][j] ������ѡ�� k ����������� dp[i + 1][j - w[i]] �ļ�����ѡ�� k - 1 �����ʱ��ͬ��
���ԣ� dp[i + 1][j] �ĵ����� k >= 1 ���ֵļ����Ѿ��� dp[i + 1][j - w[i]] �м��������
����ԭ�������Ա���Ϊ��
max{dp[i][j - k * w[i]] + k * v[i] | 0 <= k}
= max(dp[i][j], max{[i][j - k * w[i]] + k * v[i] | 1 <= k)
= max(dp[i][j], max({dp[i][(j - w[i]) - k * w[i]] + k * v[i] | 0 < = k} + v[i])
= max(dp[i][j], dp[i + 1][j - w[i]] + v[i])
��ʱ����Ҫ k ��ѭ�������ӶȽ�Ϊ O(nW)
*/
int n, W;
int w[100], v[100];
int dp[101][101];
int main()
{
    scanf("%d %d", &n, &W);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &w[i], &v[i]);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            if (j < w[i])
            {
                dp[i + 1][j] = dp[i][j];
            }
            else{
                dp[i + 1][j] = max(dp[i][j], dp[i + 1][j - w[i]] + v[i]);
            }
        }
    }
    printf("%d", dp[n][W]);

    return 0;
}

