#include <iostream>
#include <cstdio>
using namespace std;
/*
������Ҫ n-1 ��������ʾ��ǰ�� i �����ĸ��ڵ㣬���������ʱ��ֱ�ӽ����ʼ��Ϊ���ڵ�
�����ǲ��鼯�����Ľں��������ʱ�򣬾Ϳ��Ը��ݸ��ڵ�Ĺ�ϵ�������鼯�� 1 �ĸ����� 1
���� mark ֮�󣬱㽫��������Ϊ���ڵ�
*/
int p[100010];
char s[5];
int x;
int N, Q;

int find(int x)
{
    if (p[x] == x) return x;
    else
    {
        printf("1 %d\n", p[x]);
        return p[x] = find(p[x]);
    }
}
int main()
{
    while (scanf("%d %d", &N, &Q))
    {
        if (N == 0 && Q == 0)
        {
            break;
        }
        for (int i = 2; i <= N; i++)
        {
            scanf("%d", &p[i]);
        }
        p[1] = 1;
        long long sum = 0;
        for (int i = 0; i < Q; i++)
        {
            scanf("%s %d", s, &x);
            // �������ڵ�
            if (s[0] == 'Q')
            {
                sum += find(x);
            }
            //  ���� x �ڵ㣨�� x ��Ϊ���ڵ㣩
            else if (s[0] == 'M')
            {
                p[x] = x;
            }
        }
        cout << sum << endl;
    }


    return 0;
}
