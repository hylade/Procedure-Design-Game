#include <iostream>
#include <cstdio>
using namespace std;
/*
��������������е����⣬����ͨ�� DP ��Ч���
���� dp[i] Ϊ�� ai ��β������������еĳ���
���ڸ�����������������������ֻ���� ai ��������
���������� j < i �� aj < ai ���� aj ��β����������׷�� ai ��õ���������
�ʵ���ʽΪ��
dp[i] = max{1, dp[j] + 1| j < i �� aj < ai}
*/

// ���Ӷ�Ϊ O(n^2)
/*
int n;
int dp[1000];
int a[1000];
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    int res = 0; // ���ڱ�������������г���
    for (int i = 0; i < n; i++)
    {
        dp[i] = 1; // �� i λ�ÿ�ʼ���㳤��
        for (int j = 0; j < i; j++)
        {
            if (a[j] < a[i])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        res = max(res, dp[i]);
    }


    printf("%d", res);
    return 0;
}
*/

int n;
int a[1000], dp[1000];
#define inf 1000001
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    fill(dp, dp + n, inf);
    for (int i = 0; i < n; i++)
    {
        *lower_bound(dp, dp + n, a[i]) = a[i];
    }
    printf("%d", lower_bound(dp, dp + n, inf) - dp);
    /*
    lower_bound(a, a + n, key) ���ڷ��ؼ�ֵ >= key �ĵ�һ��λ��
    ��� "*" �õ����Ӧ��Ԫ��
    ���� lower_bound() ���� first �� last ��ǰ�պ������ڽ���
    ���ֲ��ң����ص�һ�����ڻ���� val �ĵ�һ��Ԫ��λ�ã�������Ԫ��
    ��С�� val ���򷵻� last ��λ�ã��� last ��Խ���

    int *t = lower_bound(a, a + n, key); //������ a �в��� key
    int post = t - a; // t - a ���� key �����±�
    ͬʱ���� upper_bound(a, a + n, k) ���ڷ���ָ�� ai > k ����Сָ��
    ����ʹ�����߻�ó���Ϊ n ���������� a �� k �ĸ���
    k �ĸ��� = upper_bound(a, a + n, k) - lower_bound(a, a + n, k)
    */
    return 0;
}
