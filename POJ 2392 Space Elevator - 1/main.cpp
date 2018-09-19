#include <iostream>
#include <algorithm>
#include <cstdio>
#include <math.h>
#include <string.h>
using namespace std;
/*
���ر�������Ҫע���ʯ���ܵ�������߶� a �������򣬷�ֹʯ������һ���߶Ⱥ�ʣ�µ�һЩʯ�����ܵ���ĸ߶�С�ڸø߶�
��ôʣ�µ�ʯ��Ͳ������Ϸ��ˣ�Ӧ���ȷ������߶�С��ʯ��
*/
int K;
// ����ÿ�������е� a ���д�С��������
struct node{
    int h, a, c;
    bool operator< (const node b) const{
        return a < b.a;
    }
}data[401];
// dp[i] ��ʾ���鲻ͬ a ���������ܴﵽ�����߶�
int dp[40001];

int main()
{
    int ans = 0;
    memset(dp, 0, sizeof(dp));
    scanf("%d", &K);
    // �������ݣ���������Ӧ��Ϊԭ���������Ƹ߶�/�����߶� ���ߵĽ�Сֵ
    for (int i = 0; i < K; i++)
    {
        scanf("%d %d %d", &data[i].h, &data[i].a, &data[i].c);
        data[i].c = min(data[i].c, data[i].a / data[i].h);
    }
    // ����
    sort(data, data + K);
    // ��� 01 ����
    for (int i = 0; i < K; i++)
    {
        for (int j = 0; j < data[i].c; j++)
        {
            for (int k = data[i].a; k >= data[i].h; k--) // 01 ����������⣬Ҫ��֤ǰһ���׶εĽ��û�з����ı�
            {
                dp[k] = max(dp[k], dp[k - data[i].h] + data[i].h);
                // �ҵ��߶����ֵ
                if (ans < dp[k])
                {
                    ans = dp[k];
                }
            }
        }
    }

    printf("%d", ans);
    return 0;
}
