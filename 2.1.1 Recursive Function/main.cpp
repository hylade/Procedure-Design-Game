#include <iostream>
#include <cstdio>
using namespace std;

// �ݹ麯������һ���������ٴε��ú����������Ϊ�ĺ���

// �׳�
/*
int fact(int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return fact(n - 1) * n;
    }
}
*/

// 쳲���������
/*
int fib(int n)
{
    if (n <= 1)
    {
        return n;
    }
    return fib(n - 1) + fib(n - 2);
}
*/

// 쳲��������� 2.0
/*
����쳲��������ж���ͬһ�� n ֵ������ý����ͬ����ˣ�������һ�ι��󣬽������������������Ż�����
*/
int fib(int n, int MAX_N)
{
    int memo[MAX_N];
    for (int i = 0; i < MAX_N; i++)
    {
        memo[i] = 0; // ��ʼ������Ԫ��
    }

    if (n <= 1)
    {
        return n;
    }
    else if (memo[n] != 0)
    {
        return memo[n]; // �����ѱ�������
    }
    return memo[n] = fib(n - 1, MAX_N) + fib(n - 2, MAX_N);
}
int main()
{
    int n = 3;
    int MAX_N = 100;
    int a = fib(n, MAX_N);
    printf("%d", a);

    return 0;
}
