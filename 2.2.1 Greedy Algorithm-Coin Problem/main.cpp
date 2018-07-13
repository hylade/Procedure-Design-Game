#include <iostream>
#include <cstdio>
using namespace std;

/*
本题中中贪心算法的依据为--优先使用面值大硬币
搜索算法和动态规划算法是在多种策略中选取最优解，但是贪心算法不同，它遵循某种规则，不断选取当前最优策略

若题目能够使用贪心算法求解，那么通常是非常高效的
*/
const int V[6] = {1, 5, 10, 50, 100, 500};
int C[6];
int A;

int main()
{
    for (int i = 0; i < 6; i++)
    {
        scanf("%d", &C[i]); // 输入每种硬币的个数
    }

    scanf("%d", &A); // 输入需支付的金额

    int man = 0;

    for (int i = 5; i >= 0; i--)
    {
        int t = min(A / V[i], C[i]); // 使用硬币 i 的数量
        A -= t * V[i]; // 剩余需支付金额
        man += t; // 支付硬币个数
    }

    printf("%d", man);

    return 0;
}
