#include <iostream>
#include <cstdio>
#include <math.h>
#include <string.h>
#include <algorithm>
using namespace std;
/*
�� TS ��Ϊ״̬������ TF ���� dp[TS] = TF
���� TS ���� [-100000, 100000] �����ǵ����鷶Χ����Ҫ����Ϊ [0, 200000]
���� dp[zero = 100000] = 0

*/
int N;
int s[101], f[101];
const int zero = 100000;
// �� s �ĺ�Ϊ״̬������ f ���� dp[s] = f ��s �ķ�ΧΪ [-100000, 100000] ���� zero = 100000 Ϊ���
int dp[200000 + 2];
// �� max_s �� min_s �ֱ��ʾ TS �����ֵ����Сֵ
int max_s, min_s;
#define inf 0x7f7f7f7f

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d %d", &s[i], &f[i]);
        if (s[i] >= 0)
            // �������ֵ
            max_s += s[i];
        else
        // ������Сֵ
            min_s += s[i];
    }
    // ��ʼ������ TS ���ܳ��ֵ� dp ֵ����ʼ��Ϊ -inf �����ܳ�ʼ��Ϊ 0 �������ܹ���ֹ���ܺϳ���ֵ�ĳ���
    for (int i = min_s; i <= max_s; i++)
    {
        dp[i + zero] = -inf;
    }
    // ���� zero ֵӦ��ʼ��Ϊ 0
    dp[zero] = 0;
/*
�ڽ��� 01 ������ʱ�� dp[v] = max(dp[v], dp[v - c[i]] + w[i]) ����Ҫʹ�� dp[v - c[i]] ���� dp[v] ��
������Ҫ�Ӵ�С����
���� c[i] < 0 ʱ����Ҫ��С�����������Ϊ v - c[i] > v
*/
    for (int i = 0; i < N; i++)
    {
        if (s[i] >= 0)
        {
            // ������ʱ��Ӧ�������������ܱ�֤ǰ���ֵû���ù�
            for (int j = max_s; j - s[i] >= min_s; j--)
            {
                dp[j + zero] = max(dp[j + zero], dp[j - s[i] + zero] + f[i]);
            }
        }
        else
        {
            // ������ʱ��Ӧ�������������ܱ�֤�����ֵû���ù�
            for (int j = min_s; j - s[i] <= max_s; j++)
            {
                dp[j + zero] = max(dp[j + zero], dp[j - s[i] + zero] + f[i]);
            }
        }
    }
    int ans = 0;
    // �ҳ����� ts >= 0 �� tf >= 0 �����ֵ
    for (int i = 0; i <= max_s; i++)
    {
        if (dp[i + zero] >= 0)
        {
            ans = max(ans, i + dp[i + zero]);
        }
    }
    printf("%d", ans);


    return 0;
}
