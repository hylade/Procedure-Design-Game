#include <iostream>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <cstdio>
using namespace std;
/*
���������ַ������ǲ�������ѭ���ķ������� dp[i][j] = \sum_{k=0}^{min(j, num[i])} ����Ϊ
dp[i][j] = dp[i][j-1] + dp[i-1][j] + dp[i-1][j-1-num[i]]
�� num[i] > j - 1 ʱ���һ�����
���ַ����� P69 �����ἰ
*/

// family ����ȷ����ͬ��������ϸ��ж���ֻ
int family[1000];
// dp ����
int dp[1000][100000];
int T, A, S, B;
#define MOD 1000000

int main()
{
    // �����ʼ����
    scanf("%d %d %d %d", &T, &A, &S, &B);
    for (int i = 0; i < A; i++)
    {
        // ���벻ͬ���������
        int x;
        scanf("%d", &x);
        // �ۼ�
        family[x]++;
    }

    // һ������ȡ�ķ�������һ��
    for (int i = 0; i <= T; i++)
    {
        dp[i][0] = 1;
    }

    for (int i = 1; i <= T; i++)
    {
        for (int j = 1; j <= A; j++)
        {
            if ((j - 1 - family[i]) >= 0)
            {
                // ȡ����Ϊ�˱����������Ľ�����ָ���
                dp[i][j] = (dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1 - family[i]]) % MOD;
            }
            else{
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
            }
        }
    }
    int result = 0;
    // Ѱ�ҳ����� S - B ֮��ļ�������
    for (int i = S; i <= B; i++)
    {
        result = (result + dp[T][i]) % MOD;
    }

    printf("%d", result);

    return 0;
}
