#include <iostream>
#include <algorithm>
#include <cstdio>
#include <math.h>
#include <string.h>
using namespace std;
/*
�汾 -1 �в�������ѭ��ʱ�临�ӶȽϴ󣬿��Խ����Ż���ֱ�ӱ���ܹ��������ߵ�
*/
int K;
// ����ÿ�������е� a ���д�С��������
struct node{
    int h, a, c;
    bool operator< (const node b) const{
        return a < b.a;
    }
}data[401];
// dp[i] ��ʾ��ǰ�ܴﵽ�����߶�Ϊ i
// cn[i] ��ʾ��ǰ������ʹ�õ���������ҪС�� node.c
bool dp[40001];
int cn[40001];

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
    // 0 ��ʱ��϶��ǿ��Դﵽ�ģ��ʳ�ʼ��Ϊ 1
    dp[0] = 1;

    for (int i = 0; i < K; i++)
    {
        // ���ڲ�ͬ�������飬��Ҫ��ʼ��ʹ���������� cn
        memset(cn, 0, sizeof(cn));
        for (int j = data[i].h; j <= data[i].a; j++)
        {
            // ���ø߶�û�г��ֹ�����ǰһ���߶ȳ��ֹ�������������û������ʱ
            if (!dp[j] && dp[j - data[i].h && cn[j - data[i].h] + 1 < data[i].c)
            {
                dp[j] = true;
                cn[j] = cn[j - data[i].h] + 1;
                if (ans < j)
                {
                    ans = j;
                }
            }
        }
    }
    }

    printf("%d", ans);
    return 0;
}
