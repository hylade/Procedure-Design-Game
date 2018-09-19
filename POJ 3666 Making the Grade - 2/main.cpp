#include <iostream>
#include <cstdio>
#include <algorithm>
#include <math.h>
#include <string.h>
using namespace std;
/*
但由于每次都是使用 dp[i] 和 dp[i-1] ，故可以利用滚动数组优化
*/
int N;
int a[2001], b[2001];
int dp[2][2001];

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &a[i]);
    }
    // memcpy 用来做拷贝，第 1 个参数是目标内存， 第 2 个对象是自愿内存，第 3 个参数拷贝大小
    memcpy(b, a, sizeof(a));
    // 排序
    sort(b, b + N);
    // 对于 1 个数的改变成本即为第 1 个数字与其他数字的差
    for (int j = 0; j < N; j++)
    {
        dp[0][j] = abs(a[0] - b[j]);
    }

    for (int i = 1; i < N; i++)
    {
        int cur = 1 & i;
        int pre = 1 & (i - 1);
        // dp[i-1][0 ... j] 的最小值
        int min_cost = dp[pre][0];
        for (int j = 0; j < N; j++)
        {
            min_cost = min(min_cost, dp[pre][j]);
            // 前一个最优解的基础上，加上 b[j] 凑成 i+1 长度的各个解
            dp[cur][j] = min_cost + abs(a[i] - b[j]);
        }
    }
    // 用 min_element 返回位置，添加 * 后能返回相应数值
    int cur = (N - 1) & 1;
    cout << *min_element(dp[cur], dp[cur] + N) << endl;

    return 0;
}
