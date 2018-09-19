#include <iostream>
#include <cstdio>
using namespace std;

// 递归函数是在一个函数中再次调用函数自身的行为的函数

// 阶乘
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

// 斐波那契数列
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

// 斐波那契数列 2.0
/*
由于斐波那契数列对于同一个 n 值，其调用结果相同，因此，若计算一次过后，将结果保存起来，便可优化计算
*/
int fib(int n, int MAX_N)
{
    int memo[MAX_N];
    for (int i = 0; i < MAX_N; i++)
    {
        memo[i] = 0; // 初始化数组元素
    }

    if (n <= 1)
    {
        return n;
    }
    else if (memo[n] != 0)
    {
        return memo[n]; // 调用已保存数据
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
