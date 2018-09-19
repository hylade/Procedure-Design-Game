#include <iostream>
#include <algorithm>
#include <cstdio>
#include <math.h>
#include <string.h>
using namespace std;
/*
���ر����ͷ������ٶ�Ӧ����汾 -2 ��ͬ
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
    memset(dp, -1, sizeof(dp));
    scanf("%d", &K);
    // �������ݣ���������Ӧ��Ϊԭ���������Ƹ߶�/�����߶� ���ߵĽ�Сֵ
    for (int i = 0; i < K; i++)
    {
        scanf("%d %d %d", &data[i].h, &data[i].a, &data[i].c);
        data[i].c = min(data[i].c, data[i].a / data[i].h);
    }
    // ����
    sort(data, data + K);
    dp[0] = 0;
    // ���ڲ�ͬʯ��
    for (int i = 0; i < K; i++)
    {
        // ���� 0 - ���߶��Ƿ��ܹ���ʯ����ϳ���
        for (int j = 0; j < data[i].a; j++)
        {
            // ��֮ǰ���ֹ���ʯ�飬˵���Ѿ�����ϳ�������ô������Ӧ��Ϊ��ǰʯ��������
            // ����ԭ�������ٿ���������ʯ�������
            if (dp[j] >= 0)
            {
                dp[j] = data[i].c;
            }
            // �����ǵĸ߶�С��ʯ��ĸ߶Ȼ���ʹ��ʯ����ϳ��ø߶ȣ���ô�� dp ��Ϊ -1
            else if (j < data[i].h || dp[j - data[i].h] <= 0)
            {
                dp[j] = -1;
            }
            // �����������������˵���ø߶Ȼ�δ���ֹ�����Ҫ����ϳ�������ô��Ҫʹ��һ�鵱ǰʯ��
            else{
                dp[j] = dp[j - data[i].h] - 1;
            }
        }
    }
    // �������߶�ӦΪʯ�����������ĸ߶����ƣ���ô�Ӹø߶ȿ�ʼ�ݼ��������� dp ��ֵ >= 0 �����
    // ˵����ʯ�����ͨ������ʯ������ϳ�
    for (int i = data[K - 1].a; i >= 0; i--)
    {
        if (dp[i] >= 0)
        {
            ans = i;
            break;
        }
    }

    printf("%d", ans);
    return 0;
}
