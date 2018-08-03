#include <iostream>
#include <cstdio>
#include <algorithm>
#include <bitset>
#include <string.h>
using namespace std;
/*
这是一个二维的穷举，因为列数较行数多，所以可做 dfs 穷举所有行的情况
通过 bitset 保存每一行的情况，对于行的翻转，使用 bitset 自带的 flip 函数即可
对于每一行都确定时，统计各列翻转情况的较大值，从而取得最优值
*/
// 定义列、行、结果
int c, r, ans;
// 利用 bitset 保存
bitset<10000> a[10];

void dfs(int n)
{
    // 当确定各行是否翻转后，即可进行列翻转分析
    if (n == r)
    {
        // 定义行确定时，列翻转所引起的较大值
        int result = 0;
        for (int i = 0; i < c; i++)
        {
            // 定义该列中正面向上的个数
            int sum = 0;
            for (int j = 0; j < r; j++)
            {
                if (a[j][i] == 1)
                {
                    sum += 1;
                }
            }
            // 取该列是否翻转中的较大值加入到本次情况中
            result += max(sum, r - sum);
        }
        ans = max(ans, result);
        return ;
    }

    // 当该行不翻转时
    dfs(n + 1);
    // 翻转
    a[n].flip();
    // 当该行翻转时
    dfs(n + 1);
}
int main()
{
    while (scanf("%d %d", &r, &c))
    {
        if (c == 0 && r == 0)
        {
            break;
        }
        // 读入各个位置的值
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                bool tmp;
                cin >> tmp;
                a[i][j] = tmp;
            }
        }

        ans = 0;
        dfs(0);
        printf("%d", ans);
    }

    return 0;
}
