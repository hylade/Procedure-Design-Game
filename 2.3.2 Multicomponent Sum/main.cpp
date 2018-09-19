#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string.h>
using namespace std;
/*
���ڸö��ز��ֺ͵��������ʹ�� DP �������
����1��
���� dp[i + 1][j] Ϊǰ i �������Ƿ��ܼӺͳ� j
Ϊ�˵õ� dp[i + 1][j] ��������Ҫ��ǰ i - 1 �����ּӺͳ� j�� j - ai��...�� j - mi * ai
�ɴ˿ɵõ��ƹ�ϵʽΪ dp[i + 1][j] = ��0 <= k <= mi �� k * ai <= j ʱ���� dp[i][j - k * ai] Ϊ��� k ��
�����㷨�ĸ��Ӷ�Ϊ O(K (mi)_{�ۼ�})

����2��
���ڵ� 1 �ַ������ӶȽϴ������ǲ�������ܷ�õ�Ŀ��ĺ�����ͬʱ�ѵõ�ʱ ai �������ʣ�¼�������ʹ�ü������
���ɼ��ٸ��Ӷ�
���� dp[i + 1][j] Ϊ��ǰ i �����Ӻ͵õ� j ʱ�� i �����ܹ�ʣ����ٸ������ܼӺ͵õ� i �������Ϊ -1 ��
���������ֵ��ƹ�ϵ����ǰ i - 1 �����ܹ��Ӻ͵õ� j �Ļ����� i �����Ϳ������� mi ��
��ǰ i �����Ӻ͵õ� j - ai ʱ�� i ��������ʣ�� k �Ļ�����ô���� i �����Ӻ͵õ� j ʱ�� i ��������ʣ�� k - 1 ��
�ʵ���ʽΪ��
dp[i + 1][j] �� dp[i][j] >= 0 ʱΪ mi ���� j < ai �� dp[i + 1][j - ai] <= 0 ʱ��Ϊ -1 ��
��Ϊ�������ʱ��Ϊ dp[i + 1][j - ai] - 1
��ʱ���� dp[n][K] >= 0 ʱ����֤��

���ַ����ĸ��Ӷ�Ϊ O(nK) ��ͬʱΪ����С�ռ䣬�ظ���������
*/
// 1
/*
int n, K;
int main()
{
    scanf("%d %d", &n, &K);
    int a[n], m[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &a[i], &m[i]);
    }
    bool dp[n + 1][K + 1];
    dp[0][0] = true;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= K; j++)
        {
            for (int k = 0; k <= m[i] && k * a[i] <=j; k++)
            {
                dp[i + 1][j] |= dp[i][j - k * a[i]];
            }
        }
    }

    if (dp[n][K])
    {
        printf("Yes");
    }
    else
    {
        printf("No");
    }

    return 0;
}
*/

// 2
int n, K;
int main()
{
    scanf("%d %d", &n, &K);
    int a[n], m[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &a[i], &m[i]);
    }

    int dp[K + 1];

    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= K; j++)
        {
            if (dp[j] >= 0)
            {
                dp[j] = m[i];
            }
            else if(j < a[i] || dp[j - a[i]] <= 0)
            {
                dp[j] = -1;
            }
            else{
                dp[j] = dp[j - a[i]] - 1;
            }
        }
    }
    if (dp[K] >= 0)
    {
        printf("Yes");
    }
    else{
        printf("No");
    }
    return 0;
}
