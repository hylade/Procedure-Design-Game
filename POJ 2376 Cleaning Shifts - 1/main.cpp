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

        // ������Ŀ�ʼ�Լ�������Ľ���ʱ�䲻����Ҫ��ʱ��ֱ�ӷ��� -1 �������Խ����´�����
        if (time[0].start > 1 || time[N].over < T)
        {
            printf("-1\n");
            continue;
        }

        // �����ʼţ������Ϊ 0
        int used_cows = 0;
        // �����ʼ����ʱ��Ϊ 0
        int end = 0;
        // �����ʼ����Ϊ 0
        int index = 0;

        while (end < T)
        {
            // ��һͷţ�Ŀ�ʼʱ�����Ϊǰһͷ�Ľ���ʱ�� + 1
            int begin = end + 1;
            // Ѱ��һͷ�ܹ��� begin ��ʼ�����ҽ���ʱ�����ţ
            for (int i = index; i < N; i++)
            {
                // �ж��ܹ�������㣬�����ܣ�˵����ͷţ�Ĺ���ʱ��֮����ڼ��
                if (time[i].start <= begin)
                {
                    // �жϸ�ţ�Ĺ���ʱ����ܷ񸲸����Ŀ�ʼʱ���
                    if (time[i].over > begin)
                    {
                        // ������ʱ���ӳ����
                        end = max(end, time[i].over);
                    }
                }
                // �����ܸ�����㣬˵����һͷţ�Ѿ�������ʵ��ˣ���Ҫ������һͷţ
                else{
                    index = i;
                    break;
                }
            }

            // ��û���ҵ�����������ţ���򷵻� -1
            if (begin > end)
            {
                return -1;
            }
            // �ҵ�����������ţ����Ҫ��ţ������ + 1
            else{
                used_cows++;
            }
        }
        printf("%d\n", used_cows);
    }

    return 0;
}
