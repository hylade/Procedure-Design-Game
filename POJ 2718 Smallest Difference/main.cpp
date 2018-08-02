#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string.h>
using namespace std;
/*
Ҫ��������������Сֵ������Ҫ��ԭ��ֵ�԰�֣�������ⷽ������
�����йؼ�����ʹ�� next_permutation() ����������ȫ����
*/
// �����������飬����ֻ�� 0 - 9 �Ǹ�����
int a[10];
// ����ȷ�����ָ���
int n;
// �������޴���
#define inf 0x3f3f3f3f
int solve()
{
    // ����λΪ 0 ʱ����Ҫʹ�� next_permutation ������ȫ����
    // �����ڵ�ǰ���� pn ��������һ������ pn+1 ���㣺�������������� pm ��ʹ pn < pm < pn+1
    while (a[0] == 0)
    {
        // ��ֹ��λΪ 0
        next_permutation(a, a + n);
    }
    int ans = inf;
    // ���ڽ���ֵһ��Ϊ��
    int mid = (n + 1) / 2;
    // ���� do - while ѭ�������ַ�ʽ����֤ѭ��һ���ܽ���һ��
    do
    {
        // ���м�λ����ֵΪ 0 ʱ��˵���ڶ���������λ��Ϊ 0 �������������������ʹ��ȫ����ֵ��Ҫ�󣬹ʲ����з���
        if (a[mid])
        {
            int x = a[0], y = a[mid];
            // �õ���һ����
            for (int i = 1; i < mid; i++)
            {
                x = 10 * x + a[i];
            }
            // �õ��ڶ�����
            for (int i = mid + 1; i < n; i++)
            {
                y = 10 * y + a[i];
            }
            // �жϴ�ʱ��ֵ��������Сֵ�Ĵ�С�������Ƿ��滻
            if (ans > abs(x - y))
            {
                ans = abs(x - y);
            }
        }
        // �����жϣ��Ƿ��ܼ���ִ�� next_permutation �������������У������� false �� �������򷵻� true
    }while(next_permutation(a, a + n));
    return ans;
}
int main()
{
    int N;
    // ����ִ�д���
    scanf("%d", &N);
    while (N--)
    {
        // ������ a ��ʼ��Ϊ 0 �������Ժ��������������Ӱ��
        memset(a, 0, sizeof(a));
        // ��ʼ���ָ���Ϊ 0
        n = 0;
        char c;
        // ʹ�� getchar() �Ե�ȡ N ���û��Ļس���
        getchar();
        // �������뵥�ַ�ʱ�û��س���Ҳ�ᱻ���룬���Խ����� c ����Ϊ�س�����������ֹ�˴�ѭ��
        while (scanf("%c", &c), c != '\n')
        {
            // ��Ϊ�ո�ʱ������ȡ��һ�ַ�
            if (c == ' ')
            {
                continue;
            }
            // ����ȡ���ַ����뵽������
            a[n++] = c - '0';
        }
        // ��������Ԫ��ֻ��һ��ʱ��ֱ�����
        if (n == 1)
        {
            printf("%d\n", a[0]);
        }
        // ��������Ԫ��������ʱ��������߲�ֵ�����ڴ�С�������룬�����Ǻ��߼�ȥǰ��
        else if (n == 2)
        {
            printf("%d\n", a[1] - a[0]);
        }
        // ���ж������ʱ����ִ�� solve ����
        else
        {
            printf("%d\n", solve());
        }
    }


    return 0;
}
