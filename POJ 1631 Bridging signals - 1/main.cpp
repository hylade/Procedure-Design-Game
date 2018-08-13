#include <iostream>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <cstdio>
using namespace std;
/*
基本思路：
直线 L1 若与 L2 不相交，那么 L1 的左右端点要么都小于 L2 ，要么都大于 L2
因为所给数组已经保证了左端点递增，所以我们只需要求输入数组的最长上升子序列即可(LIS)
dp[i] 定义为以 a[i] 结尾的 LIS 的长度
状态转移： dp[i] = max(dp[i], dp[j] + 1) ，但需要满足( 0 <= j < i, a[j] < a[i])
边界处理： dp[i] = 1 (0 <= i < n)
时间复杂度为 O(n^2)
*/
int T, N;
int a[40001];
int dp[40001];

int main()
{
    // 运行次数
    scanf("%d", &T);
    while (T--)
    {
        // 本次运行数组长度
        scanf("%d", &N);
        for (int i = 0; i < N; i++)
        {
            scanf("%d", &a[i]);
            // 初始化为 1 ，长度最短即为本身
            dp[i] = 1;
        }

        int ans=1;
        for(int i = 1; i < N; i++)
        {
            for(int j = 0; j < i; j++)
            {
                // 对小于 i 的序号都进行搜索，若序号与数值都小于 i 的序号和数值，说明找到一个上升序列，那么 dp[i] 应该进行状态庄毅
                if(a[i] > a[j])
                {
                    dp[i] = max(dp[i], dp[j] + 1);  // 状态转移
                }
            }
            ans = max(ans, dp[i]);  // 比较每一个dp[i],最大值为答案
        }
        cout<<ans<<endl;
    }

    return 0;
}
