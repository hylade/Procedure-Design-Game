#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;
/*
对于 2.3.1.1 Knapsack Problem ，其实运行时某些参数调用了多次，此时返回的结果应该相同
但是，第二次调用的时候却白白浪费了计算时间，此时，通过将第一次调用时的结果记录下来
从而省略第二次以后的重复计算，从而缩短时间

此时，对于同样的参数，只会在第一次被调用时执行递归部分，第二次之后会直接返回
参数的组合不过 nm 种，而函数内只需要调用 2 次递归，所以只需要 O(nm) 的复杂度就能解决问题
*/

int n ,m;
int w[100], v[100];
int dp[101][101]; // 创建存储数组

int rec(int i, int j)
{
    if (dp[i][j] > 0)
    {
        return dp[i][j]; // 当 dp 数值 > 0 ，表明该参数已经计算过，可以直接调用
    }
    int res;
    if (i == n)
    {
        res  = 0; // 此时已经没有剩余物品需要检查
    }
    else if (j < w[i])
    {
        res = rec(i + 1, j); // 若此时背包容量无法放入该物品
    }
    else
    {
        res = max(rec(i + 1, j), rec(i + 1, j - w[i]) + v[i]); // 对挑选或不挑选都进行尝试
    }
    return dp[i][j] = res; // 将结果都记录在数组中，同时返回
}
int main()
{
    memset(dp, -1, sizeof(dp)); // 用 -1 表示尚未计算过，初始化整个数组；对于 memset 函数，需要调用 string.h 头文件
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &w[i], &v[i]);
    }

    printf("%d", rec(0, m));

    return 0;
}


/*
memset 是按照 1 字节为单位对内存进行填充， -1 的每一位二进制位都是 1
（对于负数的二进制位，先对负数的绝对值求二进制位，然后在最后加 1）
所以 -1 可以像 0 一样使用 memset 进行初始化，通过 memset 可以快速对
高维数组进行初始化，但是需要注意无法初始化为 1 之类的数值

原因在于， memset 是一个字节一个字节设置的，由于 1 个 int 是 4 个字节
当初始化为 1 时，每个字节都将变为 00000001 ，此时整个 int 将为 16843009
*/
