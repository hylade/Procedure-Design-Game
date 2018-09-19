#include <iostream>
#include <cstdio>
using namespace std;
/*
���� 01 �����������ȫ���������в����ظ�����һ������ʵ�ֵķ���
Ҳ����ͨ���������������ʹ����ʵ���ظ�����
����ȫ�����еı���ʽ�� dp[i + 1][j] = max(dp[i][j], dp[i + 1][j - w[i]] + v[i])
�ɼ������Դ˼��㣬ֻ��Ҫ���� dp[i] �� dp[i + 1] ������ֵ����
���Կ��Խ����ż�ԣ������� dp ����ʱ���� dp[0][j] Ϊ 0�����ʵó����´���
*/
int n, W;
int w[100], v[100];
int dp[2][101];
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
                dp[(i + 1) & 1][j] = dp[i & 1][j];
            }
            else
            {
                dp[(i + 1) & 1][j] = max(dp[i & 1][j], dp[(i + 1) & 1][j - w[i]] + v[i]);
            }
        }
    }
    printf("%d", dp[(n & 1)][W]);


    return 0;
}
