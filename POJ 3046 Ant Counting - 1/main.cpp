#include <iostream>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <cstdio>
using namespace std;
/*
�� dp[i][j] ��ʾǰ i �����幹�ɳ��� j �������ж�����
��ô dp[i][j] = \sum(dp[i-1][j-k]) ���� k �ķ�Χ�� 0 - N[i]
��ǰ i - 1 ��������� j - k �ļ��ϣ�ÿ�����϶�������� i �� k ֻ����
�ۼӵõ�ǰ i ��������� j ֻ�ļ�����Ŀ
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

    // �ռ��ĸ���Ϊ 1
    dp[0][0] = 1;
    // ��ʼ����������
    int totel = family[0];
    for (int i = 1; i <= T; i++)
    {
        // ǰ i �����干�ж���ֻ���ϣ����Ǵ�ʱ������г���
        totel += family[i];
        // ȷ����ǰ�ܹ�����ӵ�������
        for (int j = 0; j <= family[i]; j++)
        {
            for (int k = j; k <= totel; k++)
            {
                // ǰ i - 1 �������дﵽ k - j ֻ���ϵļ����У�ÿ�����Ϸ��� j ֻ����
                dp[i][k] = (dp[i][k] + dp[i - 1][k - j]) % MOD;
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
