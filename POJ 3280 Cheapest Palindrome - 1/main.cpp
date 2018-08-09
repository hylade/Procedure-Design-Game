#include <iostream>
#include <cstdio>
#include <math.h>
#include <algorithm>
#include <string.h>
#include <map>
using namespace std;
/*
用 dp[i][j] 表示区间 (i, j) 变到回文字符串需要的费用
若 s[i] = s[j]
则 dp[i][j] = dp[i + 1][j - 1]
否则就在四种决策中消除 i j 两个位置的冲突
1. 在左侧添加 s[j] 字符
2. 删除 s[j]
3. 在右侧添加 s[i] 字符
4. 删除 s[i]
综合得到：
1. 把 dp[i+1][j] 变为回文串，则所需花费对应为 min(dp[i+1][j]+add[str[i]], dp[i+1][j]+del[str[i]])
2. 把 dp[i][j-1]变为回文串，则所需花费对应为 min(dp[i][j-1]+add[str[j]], dp[i][j-1]+del[str[j]])
// 取上述四种情况的最小值即可
3. 若 str[i]==str[j] ，把 dp[i+1][j-1] 变为回文串，则所需花费对应为 dp[i+1][j-1]
*/
int N, M;
// 定义每个字符的信息
struct Cow{
    int add;
    int del;
};
// dp 数组
int dp[2000][2000];
// 由于 map 能将唯一的 char 对应到 Cow 上
map <char, Cow> cow;
string s;
#define inf 0x7f7f7f7f;

int main()
{
    while (scanf("%d %d", &N, &M) != EOF)
    {
        // 输入字符串
        cin >> s;

        for (int i = 0; i < N; i++)
        {
            char c;
            int add, del;
            // 输入各个字符添加和删除的费用
            cin >> c >> add >> del;
            // 赋值到各个字符上
            cow[c].add = add;
            cow[c].del = del;
        }

        for (int i = 0; i < M; i++)
        {
            for (int j = i + 1; j < M; j++)
            {
                // 当头尾字符相同时，相当于将两者都删除，对剩余部分分析
                if (s[i] == s[j])
                    dp[i][j] = dp[i + 1][j - 1];
                int mincost = inf;
                // 取首端或尾端删除字符的最小值
                mincost = min(mincost, dp[i][j - 1] + cow[s[j]].del);
                mincost = min(mincost, dp[i + 1][j] + cow[s[i]].del);
                // 取首端添加 j 位置字符或尾端添加 i 位置字符的较小值
                int temp = min(dp[i][j - 1] + cow[s[j]].add, dp[i + 1][j] + cow[s[i]].add);
                // 取两种方法的较小值
                dp[i][j] = min(mincost, temp);
            }
        }

        printf("%d", dp[0][M - 1]);
    }

    return 0;
}
