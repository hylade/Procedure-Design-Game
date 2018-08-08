#include <iostream>
#include <cstdio>
#include <math.h>
#include <algorithm>
#include <string.h>
using namespace std;
/*
解题思路：
设 dp[i][j] 表示第 i 分钟，转换 j 次时最多可以拿到的苹果数目
那么就有 dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i][j]) + 当前时间点苹果是否可以接到
dp[i][j + 1] 表示不转换，dp[i][j] 表示转换

对于当前苹果是否可以接到，可以通过转换次数的奇偶性进行考虑
由于只有两颗苹果树，输入编号为 1 和 2 ，将其都 - 1 ，方便后续进行取反运算
由于初始位置在 1 号树，若转换次数 j 为奇数时，说明此时在 2 号树，加上 tree[i] ，
若 i 时间点为 1 号树落苹果，则接不到， tree[i] = 0 ，若 tree[i] = 1 ，说明 2 号树
落苹果，可以接到，便增加 1
同理，若转换次数为偶数时，说明在 1号树，由于 1 号树的标记为 0 ，便取反，加上 !tree[i]
*/
int N, W;
int tree[1001];
int dp[1001][31];

int main()
{
    scanf("%d%d", &N, &W);
    for (int i = 1; i <= N; i++)
    {
        // 输入的表示 tree 数组中索引为 i 的值，等同于 tree[i]
        scanf("%d", tree + i);
        // - 1 为了方便取反和判断
        tree[i] -= 1;
    }

    // 由于开始点应该为 dp[0][0] 故从 i = -1 和 j = -1 开始取值
    for (int i = -1; i <= N; i++)
    {
        for (int j = -1; j <= W; j++)
        {
            // 分类讨论，当转换次数为偶数和奇数
            if (j % 2)
            {
                dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i][j]) + tree[i];
            }
            else
            {
                dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i][j]) + !tree[i];
            }
        }
    }

    printf("%d", dp[N][W]);

    return 0;
}
