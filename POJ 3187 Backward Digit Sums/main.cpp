#include <iostream>
#include <cstdio>
#include <string.h>
#include <algorithm>
using namespace std;

/*
ȷ������ķ�Χ�ͳ��ȣ�����ö�����У�������������������ǵĵ��Ƽ���
permutation �ӵ����������п�ʼö�٣�ֱ���ҵ����� Sum ��ֵ�˳�����
*/
// �������ָ�����ִ�д�������
int N, M, Sum;
// �����м�����ʾ��ʽ
int a[10][10];
int main()
{
    // ����
    scanf("%d %d %d", &M, &N, &Sum);
    while (M--)
    {
        // ����ȡֵ
        int c[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        do
        {
            // ���� c ���������и�ֵ�� a ����
            for (int i = 0; i < N; i++)
            {
                a[0][i] = c[i];
            }

            // ������һ�еĺͣ��Ӷ��õ����һ���Ӻ͵õ�����ֵ
            for (int i = 1; i < N; i++)
            {
                for (int j = 0; j < N - i; j++)
                {
                    a[i][j] = a[i - 1][j] + a[i - 1][j + 1];
                }
            }
            // ��������������ֵ�� Sum ��ͬ�� break
            if (a[N - 1][0] == Sum)
            {
                break;
            }
            // ��Ȼ����Ҫ next_permutation ������һ������
        }while (next_permutation(c, c + N));

        // �õ��������е�����£���������з�ʽ
        for (int i = 0; i < N; i++)
        {
            printf("%d", c[i]);
            printf(" ");
        }

        printf("\n");

    }

    return 0;
}
