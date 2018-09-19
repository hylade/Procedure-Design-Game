#include <iostream>
#include <cstdio>
#include <math.h>
#include <algorithm>
using namespace std;
/*
���� N �����֣����Կ��������Ⱥϲ������ֱ������ŵĴ�����࣬����Խ�������Ӧ��Խ�Ⱥϲ�
���������򣬴Ӵ�Сһ�����ϲ�
*/
double a[100];
int N;

int main()
{
    while (scanf("%d", &N) != EOF)
    {
        for (int i = 0; i < N; i++)
        {
            scanf("%lf", &a[i]);
        }

        // ����
        sort(a, a + N, greater<double>());

        // ���� double ���͵ı������� printf ��˵��������ʹ�� %f ���� %lf
        // �� scanf �е�˵����ֻ��ʹ�� %lf
        double ans = a[0];

        // ѭ���ϲ�
        for (int i = 1; i < N; i++)
        {
            ans = 2 * sqrt(ans * a[i]);
        }

        // ���
        printf("%.3lf", ans);
    }

    return 0;
}
