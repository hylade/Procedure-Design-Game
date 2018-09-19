#include <iostream>
#include <cstdio>
using namespace std;
/*
�� n �����������Ʒ�������ǻ���Ϊ������ m ��Ļ��ַ�ʽ����Ϊ n �� m ���֣��� m = n ʱ����Ϊ n �Ļ�����
�� dp[i][j] ����Ϊ j �� i ���ֵ����������Ҵ�ʱ�������������
1��
�պ��� i �ֻ����������ʱ�����κ� ai ������ 0 ������ i �鶼ȡ�� 1 ��Ԫ�أ�j ��Ԫ�������𣩣�
��ʱ {ai - 1} �൱�� j - i �� i ���֣����� j �� i ������һ���ģ���ʱ dp[i][j] = dp[i][j - i]
2:
������ i �ֻ����������ô������һ���� ai = 0 ����ʱ�൱�ڶ� j ���� i - 1 �Ļ��֣�
��ʱ dp[i][j] = dp[i][j - i] + dp[i - 1][j]
�÷����ĸ��Ӷ�Ϊ O(nm)
*/
int n, m, M;
int dp[1001][1001];
int main()
{
    scanf("%d %d %d", &n, &m, &M);
    dp[0][0] = 1;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (j >= i)
            {
                dp[i][j] = (dp[i][j - i] + dp[i - 1][j]) % M;
            }
            else{
                dp[i][j] = dp[i - 1][j] % M;
            }
        }
    }
    printf("%d", dp[m][n]);



    return 0;
}
