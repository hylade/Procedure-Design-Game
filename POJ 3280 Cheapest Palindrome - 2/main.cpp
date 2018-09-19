#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
 /*
 但实际上首端增加某个字母和尾端添加某个字母效果是相同的，取其花费最小值即可
 因为如果首尾增删字母 x 都可以使一个字符串 s 变成回文的话，那么应当选取话费较小的
 */
int n,m,i,j,x,y;
int dp[2005][2005],cost[28];
char str[2005],c[2];

int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        // 将 dp 数组初始化为 0
        memset(dp, 0, sizeof(dp));
        // 输入字符串
        scanf("%s", str);
        for(i = 0; i < n; i++)
        {
            // 输入各个字符及其话费
            scanf("%s%d%d",c,&x,&y);
            // 将较低的话费存入 cost 数组中，并一一对应
            cost[c[0] - 'a'] = min(x, y);
        }
        for(j = 1; j < m; j++)
        {
            for(i = j - 1; i >= 0; i--)//求出每个区间的价值，保存最小的价值
            {
                dp[i][j] = min(dp[i + 1][j] + cost[str[i]-'a'], dp[i][j - 1] + cost[str[j] - 'a']);
                if(str[i] == str[j])
                    dp[i][j] = min(dp[i][j], dp[i+1][j-1]);
            }
        }
        printf("%d\n", dp[0][m - 1]);
    }

    return 0;
}
