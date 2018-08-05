#include <iostream>
#include <cstdio>
#include <queue>
#include <math.h>
#include <algorithm>
using namespace std;
/*
����ţ���ݿ�ʼʱ������󣬴ӵ�һͷ��ţ���п��ǣ���ţ������ȶ����з��ؽ���ʱ����̵�ţ����
��ǰ��ţ�Ƿ���Է����ţ���С�����ܣ��͸��¸�ţ��Ľ���ʱ�䣬����Ϊ����ţ�Ľ���ʱ�䣻������ܣ�
�;ʹ���һ���µ�ţ�������ţ�����ţ���У��ظ�������ֱ��������ţ���������
*/
int N;
int tag;
struct Interval{
    int left; // ��ʼʱ��
    int right; // ����ʱ��
    int no; // ţ����
    int ss; // ������
    // �ṹ���ڲ�������ʹ��ԭ�в���������Ҫ�Խṹ���������������
    // bool Ϊ�������ͣ�operator< Ϊ��������������Ϊ����
    friend bool operator< (Interval n1, Interval n2)
    {
        // ��С��������
        // ������ֵ <=-1 ��˵��ǰ�������ں���ǰ
        // ������ֵ�� -1 �� 1 ֮�䣬˵����������˳����ͬ
        // ������ֵ >= 1 ��˵��ǰ�������ں��ߺ���
        return n1.right > n2.right;
    }
};
Interval time[50005];

// ����̰������
bool sor1(Interval a, Interval b)
{
    if (a.left == b.left)
    {
        return a.right < b.right;
    }
    else{
        return a.left < b.left;
    }
}
// �����������
bool sor2(Interval a, Interval b)
{
    return a.ss < b.ss;
}

int main()
{
    while (~scanf("%d", &N) != EOF)
    {
        // co Ϊţ�����
        int co = 0;
        // tag ���ڱ�ǵ�ǰ��С�Ľ���ʱ��
        tag = 0;
        // �������ʱ�䲢�Ը�����б�ǣ��Ա㰴��˳�����
        for (int i = 0; i < N; i++)
        {
            scanf("%d %d", &time[i].left, &time[i].right);
            time[i].ss = i;
        }

        // ���տ�ʼʱ��Ӵ�С����
        sort(time, time + N, sor1);
        // �� tag �ĳ�ʼֵ��Ϊ ��һͷţ�Ŀ�ʼʱ�䣬��ʱΪ���翪ʼʱ�䣬��ô��һͷ�ض�����Ҫţ��
        tag = time[0].left;

        // ������������
        priority_queue <Interval> que;

        for (int i = 0; i < N; i++)
        {
            // ����ǰţ������С�Ľ���ʱ�䶼������ͷţ�Ŀ�ʼʱ�䣬˵������ʱ����ص�
            // ��Ҫʹ�ò�ͬ��ţ��
            if (tag >= time[i].left)
            {
                // ʹ���µ�ţ����� +1
                co++;
                // ��ţ��ţ���Ÿ�ֵ
                time[i].no = co;
                // �� push �� que �У������ţ���жԱ�
                que.push(time[i]);
                // �����ұ߽磬���ȶ��и��ݽṹ�� Interval �еĺ�������ͷ���ұ߽���С��ֵ
                // ��Ϊλ������ţ���ţ��ʱ�����ض����ұ߽���С��ţ��ʱ����������һ�����غ�
                // ����Ҫ������ţ��Ƚϣ��뵱ǰ��С���ұ߽�Ƚ�һ�������ŵ�
                tag = que.top().right;
            }
            else{
                // ����С�Ľ���ʱ��С����ͷţ�Ŀ�ʼʱ��ʱ��˵�����߿���ʹ��ͬһ��ţ�����ţ���Ÿ�����ͷţ
                time[i].no = que.top().no;
                // ���ڴ�ʱ���ȶ��������з�ʽ�����ұ߽��С�������У����� pop ��ȥ�ı�����С����ʱ���ţ
                que.pop();
                // ��ʱ���Խ���ͷţ push �����������ʼ�´�����
                que.push(time[i]);
                // ���ڽ������µ�ţ����Ҫ���¿�����С�ұ߽�
                tag = que.top().right;
            }
        }

        printf("%d", co);
        // ���ʱ��Ҫ��������ı�ţ����԰��� sor2 �ķ�ʽ���½�������
        sort(time, time + N, sor2);
        for (int i = 0; i < N; i++)
        {
            printf("%d", time[i].no);
        }

    }


    return 0;
}
