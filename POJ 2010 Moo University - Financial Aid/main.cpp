#include <iostream>
#include <math.h>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <string.h>
using namespace std;
/*
���ȶ��� + ö�� + ����
����ţ���ճɼ� s ��С�������򣬴� N/2 ~ C-1-N/2 ö����λ��
��¼ÿ�� i ǰ�� N/2 �� f ֮�ͣ������� N/2 �� f ֮��
Ȼ��ö����������������λ��
*/
int N, C, F;
// ����ţ��Ϣ�ṹ�壬�����أ����� f �Ӵ�С����
struct node{
    int s, f;
    bool operator < (const node &a) const
    {
        return f < a.f;
    }
}cow[100001];
// ���ȶ��У� f ���Ԫ�����ȳ�����
priority_queue<node> ql, qr;
int minl[100001], minr[100001];
bool cmp(node a, node b)
{
    return a.s < b.s;
}

int main()
{
    scanf("%d %d %d", &N, &C, &F);
    // �����ͷţ�ĳ˻��� aid ����
    for (int i = 0; i < C; i++)
    {
        scanf("%d %d", &cow[i].s, &cow[i].f);
    }

    // ���� cmp �������������� cmp ���������ڴ˴��� node �ṹ���������أ��ʰ������ع�������
    // ��ͬʱ���������ع�����ô�ͻᱨ������ȱʡ����ʹ�� less<> ����
    sort(cow, cow + C, cmp);
    int suml = 0, sumr = 0;

    // ���Ҷ���ÿ�� i ��� N/2 ��Ԫ�ص���С��
    for (int i = 0; i < C; i++)
    {
        // ��С��ʱ��˵����߲���Ҫ����������㽫�⼸����ֵ���
        if (i < N / 2)
        {
            ql.push(cow[i]);
            suml += cow[i].f;
            continue;
        }
        // �����ֵ�һ����������� N/2 ����ʱ���㽫��ֵ������ minl[i]
        // ͬʱ��������С�͵ı仯�����µ� f �� ql ������ f С��������滻
        minl[i] = suml;
        if (cow[i].f < ql.top().f)
        {
            suml -= ql.top().f;
            ql.pop();
            ql.push(cow[i]);
            suml += cow[i].f;
        }
    }

    // ͬ�����Ҷ���ÿ�� i �ұ� N/2 ��Ԫ�ص���С��
    for (int i = C - 1; i >= 0; i--)
    {
        if (i > C - 1 - N / 2)
        {
            qr.push(cow[i]);
            sumr += cow[i].f;
            continue;
        }
        minr[i] = sumr;
        if (cow[i].f < qr.top().f)
        {
            sumr -= qr.top().f;
            qr.pop();
            qr.push(cow[i]);
            sumr += cow[i].f;
        }
    }

    int ans = -1;
    // �Ӵ�Сö������������ cow[i].s �����ܱ�֤�ҵ��� s ���
    // ͬʱ����ΧӦ���� N/2 ~ C-1-N/2
    for (int i = C - 1 - N / 2; i >= N / 2; i--)
    {
        if (cow[i].f + minl[i] + minr[i] <= F)
        {
            ans = cow[i].s;
            break;
        }
    }
    printf("%d", ans);

    return 0;
}
