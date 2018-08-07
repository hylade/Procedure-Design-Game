#include <iostream>
#include <cstdio>
#include <algorithm>
#include <math.h>
#include <string.h>
using namespace std;
/*
����̰�Ĳ����Ǿ������ÿ���ӳԵĶ��ţ
����˼·�������Ƶ���
��������ͷţ�������Ϊ T_X D_X T_Y D_Y
������ X ʱ�� 2*T_X*D_Y
������ Y ʱ�� 2*T_Y*D_X
����ʽͬʱ���� 2*D_X*D_Y
�������õ���ΪT��D�ı�ֵ
*/
int N;
struct Cow{
    int T;
    int D;
    // ��������ʽ
    bool operator< (const Cow&c) const
    {
        return T * c.D < c.T * D;
    }
};

Cow cow[100000];
int main()
{
    while (scanf("%d", &N) != EOF)
    {
        int total = 0;
        for (int i = 0; i < N; i++)
        {
            // ����ÿͷţ����Ϣ
            scanf("%d %d", &cow[i].T, &cow[i].D);
            // �ܵ�ÿ�����ƻ���
            total += cow[i].D;
        }

        // ���� operator �з�ʽ����
        sort(cow, cow + N);

        int ans  = 0;
        for (int i = 0; i < N; i++)
        {
            // ����һͷţ��ʣ��ţ��ÿ�����ƻ���
            total -= cow[i].D;
            // ʣ��ţ�� Ti ʱ���ڵ����ƻ��������ۼ�
            ans += total * cow[i].T * 2;
        }

        printf("%d", ans);
    }

    return 0;
}
