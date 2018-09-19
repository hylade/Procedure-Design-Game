#include <iostream>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <cstdio>
using namespace std;
/*
����˼·��
ֱ�� L1 ���� L2 ���ཻ����ô L1 �����Ҷ˵�Ҫô��С�� L2 ��Ҫô������ L2
��Ϊ���������Ѿ���֤����˵��������������ֻ��Ҫ���������������������м���(LIS)
dp[i] ����Ϊ�� a[i] ��β�� LIS �ĳ���
״̬ת�ƣ� dp[i] = max(dp[i], dp[j] + 1) ������Ҫ����( 0 <= j < i, a[j] < a[i])
�߽紦�� dp[i] = 1 (0 <= i < n)
ʱ�临�Ӷ�Ϊ O(n^2)
*/
int T, N;
int a[40001];
int dp[40001];

int main()
{
    // ���д���
    scanf("%d", &T);
    while (T--)
    {
        // �����������鳤��
        scanf("%d", &N);
        for (int i = 0; i < N; i++)
        {
            scanf("%d", &a[i]);
            // ��ʼ��Ϊ 1 ��������̼�Ϊ����
            dp[i] = 1;
        }

        int ans=1;
        for(int i = 1; i < N; i++)
        {
            for(int j = 0; j < i; j++)
            {
                // ��С�� i ����Ŷ��������������������ֵ��С�� i ����ź���ֵ��˵���ҵ�һ���������У���ô dp[i] Ӧ�ý���״̬ׯ��
                if(a[i] > a[j])
                {
                    dp[i] = max(dp[i], dp[j] + 1);  // ״̬ת��
                }
            }
            ans = max(ans, dp[i]);  // �Ƚ�ÿһ��dp[i],���ֵΪ��
        }
        cout<<ans<<endl;
    }

    return 0;
}
