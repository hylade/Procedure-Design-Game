#include <iostream>
#include <cstdio>
using namespace std;
/*
�����صķ��������ÿ����Ʒ�Ƿ���뱳����������

�������ַ������������ n ����ÿһ�����������Ҫ���η�֧�����Ҫ O(2^n) ��ʱ�䣬�� n �ϴ�ʱ����û�а취���
*/
int n ,m;
int w[100], v[100];

int rec(int i, int j)
{
    int res;
    if (i == n)
    {
        res  = 0; // ��ʱ�Ѿ�û��ʣ����Ʒ��Ҫ���
    }
    else if (j < w[i])
    {
        res = rec(i + 1, j); // ����ʱ���������޷��������Ʒ
    }
    else
    {
        res = max(rec(i + 1, j), rec(i + 1, j - w[i]) + v[i]); // ����ѡ����ѡ�����г���
    }
    return res;
}
int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &w[i], &v[i]);
    }

    printf("%d", rec(0, m));

    return 0;
}
