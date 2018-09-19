#include <iostream>
#include <cstdio>
using namespace std;
/*
对于最长上升子序列的问题，可以通过 DP 高效求解
定义 dp[i] 为以 ai 结尾的最长上升子序列的长度
对于该最长上升子序列有两种情况，只包含 ai 的子序列
或者是满足 j < i 且 aj < ai 的以 aj 结尾的子序列再追加 ai 后得到的子序列
故递推式为：
dp[i] = max{1, dp[j] + 1| j < i 且 aj < ai}
*/

// 复杂度为 O(n^2)
/*
int n;
int dp[1000];
int a[1000];
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    int res = 0; // 用于保存最长上升子序列长度
    for (int i = 0; i < n; i++)
    {
        dp[i] = 1; // 从 i 位置开始推算长度
        for (int j = 0; j < i; j++)
        {
            if (a[j] < a[i])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        res = max(res, dp[i]);
    }


    printf("%d", res);
    return 0;
}
*/

int n;
int a[1000], dp[1000];
#define inf 1000001
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    fill(dp, dp + n, inf);
    for (int i = 0; i < n; i++)
    {
        *lower_bound(dp, dp + n, a[i]) = a[i];
    }
    printf("%d", lower_bound(dp, dp + n, inf) - dp);
    /*
    lower_bound(a, a + n, key) 用于返回键值 >= key 的第一个位置
    添加 "*" 得到相对应的元素
    对于 lower_bound() 是在 first 和 last 的前闭后开区间内进行
    二分查找，返回第一个大于或等于 val 的第一个元素位置，若所有元素
    都小于 val ，则返回 last 的位置，且 last 是越界的

    int *t = lower_bound(a, a + n, key); //在数组 a 中查找 key
    int post = t - a; // t - a 代表 key 所在下标
    同时还有 upper_bound(a, a + n, k) 用于返回指向 ai > k 的最小指针
    可以使用两者获得长度为 n 的有序数组 a 中 k 的个数
    k 的个数 = upper_bound(a, a + n, k) - lower_bound(a, a + n, k)
    */
    return 0;
}
