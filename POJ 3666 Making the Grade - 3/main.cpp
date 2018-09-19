#include <iostream>
#include <cstdio>
#include <algorithm>
#include <math.h>
#include <string.h>
using namespace std;
/*
但版本 -1 和版本 -2 都没有考虑下降序列的情况（不知道什么原因-_-）
同时题目说数字可能较大，故应该使用 long long 类型
*/
int N;
long long ans1, ans2;
int a[2001], b[2001];
long long dp1[2001];
long long dp2[2001];

long long Search_Increase(const int);
long long Search_Decrease(const int);

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &a[i]);
    }
    // memcpy 用来做拷贝，第 1 个参数是目标内存， 第 2 个对象是自愿内存，第 3 个参数拷贝大小
    memcpy(b, a, sizeof(a));
    // 排序，从小到大
    sort(b, b + N);
    ans1 = Search_Increase(N);

    // 从大到小
    sort(b, b + N, greater<int>());
    ans2 = Search_Decrease(N);
    // 将两个的最小值进行对比
    cout << min(ans1, ans2) << endl;

    return 0;
}

long long Search_Increase(const int N)
{
    // 使用 dp1 和 dp2 来表示前一个长度和当前长度，并初始化
    memset(dp1, 0, sizeof(dp1));
    memset(dp2, 0, sizeof(dp2));

    long long min_tmp, *dp_tmp = NULL, *p1 = dp1, *p2 = dp2, ans;
    for (int i = 0; i < N; i++)
    {
        // 用 min_tmp 找到前一长度中最小的成本
        min_tmp = p1[0];
        for (int j = 0; j < N; j++)
        {
            min_tmp = min(min_tmp, p1[j]);
            // 加上当前改变成本
            p2[j] = abs(a[i] - b[j]) + min_tmp;
        }
        // 改变指针使其仍指向前一个长度和当前长度，类似滚动数组
        dp_tmp = p1; p1 = p2; p2 = dp_tmp;
    }
    // 寻找最小值
    ans = p1[0];
    for (int i = 1; i < N; i++)
    {
        ans = min(ans, p1[i]);
    }
    return ans;
}

long long Search_Decrease(const int N)
{
    memset(dp1, 0, sizeof(dp1));
    memset(dp2, 0, sizeof(dp2));

    long long min_tmp, *dp_tmp = NULL, *p1 = dp1, *p2 = dp2, ans;
    for (int i = 0; i < N; i++)
    {
        min_tmp = p1[0];
        for (int j = 0; j < N; j++)
        {
            min_tmp = min(min_tmp, p1[j]);
            p2[j] = abs(a[i] - b[j]) + min_tmp;
        }
        dp_tmp = p1; p1 = p2; p2 = dp_tmp;
    }
    ans = p1[0];
    for (int i = 1; i < N; i++)
    {
        ans = min(ans, p1[i]);
    }
    return ans;
}
