#include <iostream>
#include <cstdio>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;
/*
����˼·��
���� dp[i] Ϊ�� i ��ʱ����ܹ��õ������ֵ������֮������ǰ�� i - 1 ��ʱ�������ȡ 0 �� i - 1 ��ʱ��μ��̣�
Ȼ��������ʱ��� i �ļ�����֮��
dp[i]= dp[i - 1] + �� i �μ�����
*/
int N, W, R;
int dp[1001];
// ����ţ����Ϣ�ṹ��
struct Interval{
    int start;
    int end;
    int efficiency;
    // ���������
    const operator< (const Interval&c) const
    {
        // ��С�������
        // ��ͬ�� if (start < c.start)
                    // return true
                // return false
        return start < c.start;
    }
};
// �������س�Ա����Ҳ��ͨ���ǳ�Ա����ʵ��
/*
bool operator< (const Interval &a, const Interval &b)
{
    if (a.start < b.start)
        return true;
    return false;
}
*/

// ����ͨ���Զ���ȽϺ���ʵ�֣�����Ҫ�� sort ��������Ӳ���
/*
bool non(const Interval &a, const Interval &b)
{
    if (a.start < b.start)
        return true;
    return false;
}
*/
// ��Ҫע�����ȶ�����ͬ
Interval interval[1001];


int main()
{
    scanf("%d %d %d", &N, &W, &R);
    for (int i = 0; i < W; i++)
    {
        // ������Ϣ
        scanf("%d %d %d", &interval[i].start, &interval[i].end, &interval[i].efficiency);
        // ʵ�ʵĽ���ʱ�仹Ҫ������Ϣʱ��
        interval[i].end += R;
    }

    sort(interval, interval + W);

    for (int i = 0; i < W; i++)
    {
        // �� i �μ���������ڸôεļ�����
        dp[i] = interval[i].efficiency;
        for (int j = 0; j < i; j++)
        {
            // ������ʱ��Ҫ��ʱ
            if (interval[j].end <= interval[i].start)
            {
                dp[i] = max(dp[i], dp[j] + interval[i].efficiency);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < W; i++)
    {
        ans = max(ans, dp[i]);
    }

    printf("%d", ans);
    // ����ͨ�� *max_element ��ɲ������ֵ
    //printf("%d\n", *max_element(dp, dp + W));
    return 0;
}
