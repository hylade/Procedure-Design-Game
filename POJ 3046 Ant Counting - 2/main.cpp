#include <iostream>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <cstdio>
using namespace std;
/*
ͨ�� -1 �汾�еķ��������� dp ������ÿ�ζ���ʹ�� i �� i-1
�ʿ���ͨ����������ʹ��
*/

// family ����ȷ����ͬ��������ϸ��ж���ֻ
int family[1000];
// dp ����
int dp[2][100000];
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
    int totel = 0;
    for (int i = 1; i <= T; i++)
    {
        // ǰ i �����干�ж���ֻ���ϣ����Ǵ�ʱ������г���
        totel += family[i];
        // & �ǰ�λ����ţ������� 1 ��λ������Ϊ 1 ��ż���� 1 ��λ������Ϊ 0
        // �Ӷ��� i �� i - 1 ����
        int cur = i & 1;
        int pre = (i - 1) & 1;
        // �����ڷ����������ʼ��Ϊ 0
        memset(dp[cur], 0, sizeof(dp[cur]));
        // ȷ����ǰ�ܹ�����ӵ�������
        for (int j = 0; j <= family[i]; j++)
        {
            for (int k = j; k <= totel; k++)
            {
                // ǰ pre �������дﵽ k - j ֻ���ϵļ����У�ÿ�����Ϸ��� j ֻ����
                dp[cur][k] = (dp[cur][k] + dp[pre][k - j]) % MOD;
            }
        }
    }
    int result = 0;
    int t = T & 1;
    // Ѱ�ҳ����� S - B ֮��ļ�������
    for (int i = S; i <= B; i++)
    {
        result = (result + dp[t][i]) % MOD;
    }

    printf("%d", result);

    return 0;
}
