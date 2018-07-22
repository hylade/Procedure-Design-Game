#include <iostream>
#include <cstdio>
using namespace std;
/*
��������Ǳ���Ϊ������������������������
dp[i][j] Ϊ s1...si �� t1...tj ������������еĳ���

���Զ��� s1...si+1 �� t1...tj+1 ������������еĳ���
�� s+1 == tj+1 ʱ��Ϊ s1...si �� t1...tj ������������еĳ��� + 1
������ s1...si+1 �� t1...tj �� s1...si �� t1...tj+1 �����нϴ�Ĺ��������г���
*/

int n, m;
char s[1000], t[1000];
int dp[1001][1001]; // DP ����

int main()
{
    scanf("%d %d", &n, &m);
    scanf("%s %s", s, t); // ������Ҫ���������

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (s[i] == t[j]) // ��ȵ����
            {
                dp[i + 1][j +1 ] = dp[i][j] + 1;
            }
            else
            {
                dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
            }
        }
    }
    printf("%d", dp[n][m]);

    return 0;
}
