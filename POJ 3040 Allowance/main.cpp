#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string.h>
using namespace std;
/*
贪心策略是使多发的面额最小，此时为最优解
1. 首先面额不小于 C 的硬币属于没办法节约的类型，直接发掉
2. 对于硬币面额从大到小尽量凑得接近 C ，允许等于或不足 C ，但是不能超过 C
3. 接着按硬币面额从小到大凑满 C （凑满的意思是允许超过一个最小面值，最小面值是指
剩余硬币中数量不为 0 的硬币中的最小面值），凑满之后得出最优解，发掉这一类，然后重新进入 2

为什么要先发大面额，再发小面额？
因为大的是小的倍数，所以大的放进去不超额一定要放进去，因为小的不管怎么取，在超过 C 之前一定会凑到这个大的面额，
那么用大的替代一定更优。第一步完成后，一定要放进去一个硬币，选择最小的并且能使和大于 C 的一定也是最优的
*/
// 定义硬币类 面值和数量
typedef pair<int, int> Coin;
Coin coin[20];
// 每种硬币或某几类硬币配合达到 C 时各个种类的数量
int need[20];
int N, C;
int main()
{
    // 输入硬币种类和工资 C
    while (scanf("%d %d", &N, &C) != EOF)
    {
        // 输入各个硬币的面值和数量
        for (int i = 0; i < N; i++)
        {
            scanf("%d %d", &coin[i].first, &coin[i].second);
        }

        // 初始化周期
        int week = 0;

        // 对于面值大于 C 的硬币，直接将其数量加到 week 上，并且将其数量置为 0
        for (int i = 0; i < N; i++)
        {
            if (coin[i].first > C)
            {
                week += coin[i].second;
                coin[i].second = 0;
            }
        }

        // 利用 sort 进行硬币数组的排序，从大到小排列
        // C++ 中提供了比较函数
        // less<Type>() 从小到大排列
        // greater<Type>() 从大到小排列
        // less_equal<Type>() <= 排列
        // greater_equal<Type>() >= 排列
        sort(coin, coin + N, greater<Coin>());

        while (1)
        {
            // 等待凑整的 sum
            int sum = C;
            // 首先将 need 数组初始化为 0
            memset(need, 0, sizeof(need));

            // 从大面值开始考虑
            for (int i = 0; i < N; i++)
            {
                // 当剩余凑整的 sum > 0 并且该面值的数量有多余时
                if (sum > 0 && coin[i].second >0)
                {
                    // 取剩余数量及使总和不超过 sum 的硬币数量的较小值
                    int can = min(coin[i].second, sum / coin[i].first);

                    if (can > 0)
                    {
                        // 更新需要凑整的 sum
                        sum -= coin[i].first * can;
                        // 更新硬币的需要数量
                        need[i] = can;
                    }
                }
            }

            // 从小面值开始考虑
            for (int i = N - 1; i >= 0; i--)
            {
                if (sum > 0 && coin[i].second > 0)
                {
                    // coin[i].second - need[i] 是需要考虑对于同种硬币在上一轮循环中使用了一部分
                    // (coin[i].first + sum - 1) / coin[i].first) 允许多出一个不超过面值的金额
                    int can = min(coin[i].second - need[i], (coin[i].first + sum - 1) / coin[i].first);

                    if (can > 0)
                    {
                        sum -= coin[i].first * can;
                        need[i] += can;
                    }
                }
            }

            // 当 sum 在循环完毕仍大于 0 ，说明某个礼拜的硬币不能达到 C 的要求
            if (sum > 0)
            {
                break;
            }

            int mina = 2e9;

            // 根据硬币数量和硬币需要数量求得使用该种情况下的 week 值
            for (int i = 0; i < N; i++)
            {
                if (need[i] != 0)
                {
                    mina = min(mina, coin[i].second / need[i]);
                }
                else{
                    continue;
                }
            }

            // 更新硬币情况
            for (int i = 0; i < N; i++)
            {
                if (need[i] == 0)
                {
                    continue;
                }
                else{
                    coin[i].second -= mina * need[i];
                }
            }

            week += mina;
        }
        printf("%d", week);
    }

    return 0;
}
