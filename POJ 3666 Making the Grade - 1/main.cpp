#include <iostream>
#include <cstdio>
#include <algorithm>
#include <math.h>
#include <string.h>
using namespace std;
/*
利用 dp[i][j] 表示前 i+1 个数变成单调且最后一个数是 b[j] ，此时的最小成本
dp[i][j] = min(dp[i-1][k]) + |a[i] - b[j]| (k = 0, ..., j)
表示前 i+1 个数的最小成本应该等于前 i 个数，最后一个数全部搜索一遍的最小值，并且加上第 i+1 个数替换为 b[j] 的成本

举个栗子说明dp状态方程的转移：
记原数组为A = 1 3 2，升序后的数组为B = 1 2 3，降序后的数组为C = 3 2 1
dp[1][0] = min{dp[0][0], abs(3 - 1)} = 2
dp[2][1] = min{dp[1][0], dp[1][1]} + abs(2 – 2)
——在保留dp[1][1]对应的最优解1 2的情况下，将B[1]=2添加到尾部得到 1 2 2，单调增
dp[2][2] = min{dp[1][0], dp[1][1]，dp[1][2]} + abs(2 – 3)
——在保留dp[1][2]对应的最优解1 3的情况下，将B[2]=3添加到尾部得到 1 3 3，单调增
*/
int N;
int a[2001], b[2001];
int dp[2001][2001];

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
        // dp[i-1][0 ... j] 的最小值
        int min_cost = dp[i - 1][0];
        for (int j = 0; j < N; j++)
        {
            min_cost = min(min_cost, dp[i - 1][j]);
            // 前一个最优解的基础上，加上 b[j] 凑成 i+1 长度的各个解
            dp[i][j] = min_cost + abs(a[i] - b[j]);
        }
    }
    // 用 min_element 返回位置，添加 * 后能返回相应数值
    cout << *min_element(dp[N - 1], dp[N - 1] + N) << endl;

    return 0;
}
