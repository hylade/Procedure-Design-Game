#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
// ���� inf
#define inf 0x7f7f7f7f
// ����������ʱ��
int N, T;
// ����ÿֻţ�Ŀ�ʼʱ��ͽ���ʱ��Ľṹ��
struct Interval{
    int start, over;
};
Interval time[25001];

// ��������ʽ
bool sor(Interval a, Interval b)
{
    // ����ʼʱ����ͬʱ������ʱ���������ǰ��
    if (a.start == b.start)
    {
        return a.over < b.over;
    }
    // ����ʼʱ�䲻��ͬʱ����ʼʱ���������ǰ��
    else
    {
        return a.start < b.start;
    }
}


int main()
{
    // �������
    while (~scanf("%d %d", &N, &T) != EOF)
    {
        // ��ʼ������
        for (int i = 0; i < N; i++)
        {
            time[i].start = inf;
            time[i].over = inf;
        }
        // ���鸳ֵ
        for (int i = 0; i < N; i++)
        {
            scanf("%d %d", &time[i].start, &time[i].over);
        }

        // ʹ�� sort �������� sor ���� time ����
        sort(time, time + N, sor);

        // ������Ŀ�ʼʱ�䲻����Ҫ��ʱ��ֱ�ӷ��� -1 �������Խ����´�����
        if (time[0].start > 1)
        {
            printf("-1\n");
            continue;
        }

        // ����ţ�������� 1 ��ʼ�����Ҵ�ʱ�������� id Ϊ 0
        int ans = 1, id = 0;

        // ��������
        for (int i = 0; i < N; )
        {
            // cnt ����ȷ����ǰ����Ҫ�󣨿�ʼʱ�����һͷţ����ʱ�� + 1 С�����ҽ���ʱ�����һͷţ����ʱ�� + 1 �󣩵�ţ������ֵ
            // ��ʼ��Ϊ 0
            int cnt = 0;
            // j ���Դ� i + 1 ��ʼ����
            for (int j = i + 1; j < N; j++)
            {
                // ����ʼʱ�������һͷţ�Ľ���ʱ�� + 1 ʱ��˵������֮�����ʱ������������Ҫ��
                // ��ʱ�������� for ѭ�������� cnt ���жϣ��� cnt = 0 �� ˵���˴�ѭ����֮ǰ����ֵ��û�з���Ҫ���
                // ��ʱ����ѭ������һ��ֵ�ٽ�������
                // �� cnt ��Ϊ 0 ��˵��֮ǰ�ҵ�������Ҫ��Ľ⣬���Ǹ�ͷ��������ֵ�� id �� i ������ cnt ����ͷţ��Ϊ�µ�
                // ������������ͬʱţ������ + 1
                if (time[j].start > time[id].over + 1)
                {
                    break;
                }
                // �ж��Ƿ��ţ��ʱ�����򸲸�ǰһͷţ����ʱ�� + 1 �������㣬�����Ҫ��
                if (time[j].start >= time[id].start && time[j].over > time[id].over + 1)
                {
                    // �ж����ҵ�����Ҫ���ţ�Ƿ��֮ǰ�ҵ���ţ�Ľ���ʱ�������������� cnt ֵ
                    if (time[j].over > time[cnt].over)
                    {
                        cnt = j;
                    }
                }
            }

            if (cnt == 0)
            {
                i++;
            }

            else{
                id = cnt;
                ans++;
                i = id;
            }
        }

        // �����ѭ����ɺ����һͷţ�Ľ���ʱ����Ϊ T ����˵���ҵ���������������� -1
        if (time[id].over == T)
        {
            printf("%d\n", ans);
        }
        else{
            printf("-1\n");
        }
    }

    return 0;
}
