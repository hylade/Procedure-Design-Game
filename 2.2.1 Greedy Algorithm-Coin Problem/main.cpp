#include <iostream>
#include <cstdio>
using namespace std;

/*
��������̰���㷨������Ϊ--����ʹ����ֵ��Ӳ��
�����㷨�Ͷ�̬�滮�㷨���ڶ��ֲ�����ѡȡ���Ž⣬����̰���㷨��ͬ������ѭĳ�ֹ��򣬲���ѡȡ��ǰ���Ų���

����Ŀ�ܹ�ʹ��̰���㷨��⣬��ôͨ���Ƿǳ���Ч��
*/
const int V[6] = {1, 5, 10, 50, 100, 500};
int C[6];
int A;

int main()
{
    for (int i = 0; i < 6; i++)
    {
        scanf("%d", &C[i]); // ����ÿ��Ӳ�ҵĸ���
    }

    scanf("%d", &A); // ������֧���Ľ��

    int man = 0;

    for (int i = 5; i >= 0; i--)
    {
        int t = min(A / V[i], C[i]); // ʹ��Ӳ�� i ������
        A -= t * V[i]; // ʣ����֧�����
        man += t; // ֧��Ӳ�Ҹ���
    }

    printf("%d", man);

    return 0;
}
