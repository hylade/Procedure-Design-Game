#include <iostream>
#include <cstdio>
#include <map>
#include <string.h>
#include <queue>
using namespace std;
/*
由于所有排列方式最后的状态都是 '01234567' ，那么可以反过来想，只要求出最终状态达到所有结果时的最小步数并记录，那么可以
通过查表得到输入排列方式对应的步数

0 表示空位置，对空位置周围的格子采用广度优先方式移动到 0 ，并记录下最小步数的结果即可

通过 map 来进行对应 string 的最小步数 int，只要结果不存在，就加入到 map 中
同时在格子移动问题上，由于采用单行 string 的方式来表示当前状态，那么移动方向上下左右分别就是当前位置 +4 -4 +1 -1
但需要注意的是，位于 3 、 4 号位置上的数值并不能相互移动
*/
// map 用于提供一对一的对应关系，每个关键字只能在 map 中出现一次
map<string, int> dp;
// 移动量
int direction[] = {1, -1, 4, -4};

void bfs()
{
    // 创建状态数组
    queue<string> que;
    // 分别表示当前状态和下一步状态
    string str, next;
    // 最终状态，单引号针对 char 类型，双引号针对的是字符串类型
    str = "01234567";
    // 作为初始移动状态 push 到 que 中
    que.push(str);
    // 初始移动状态的步数为 0
    dp[str] = 0;


    while (!que.empty())
    {
        str = que.front();
        que.pop();
        int p;
        // 首先寻找 0 所处位置
        for (int i = 0; i < 8; i++)
        {
            if (str[i] == '0')
            {
                p = i;
                break;
            }
        }

        for (int i = 0; i < 4; i++)
        {
            int n = p + direction[i];
            // 当移动后位置仍在范围内，同时不位于右上角且向右移动，或者位于左下角且向左移动时
            if (n >= 0 && n < 8 && !(p == 3 && i == 0) && !(p == 4 && i == 1))
            {
                // 由于两种状态步数相差 1 ，其余序列都相同，故可以将当前状态先赋值给 next ，然后再进行修改
                next = str;
                swap(next[p], next[n]);
                // 使用 map 中的 find 函数时，返回的是被查找元素的位置，若不存在则返回 map.end()
                if (dp.find(next) == dp.end())
                {
                    // 步数增加 1
                    dp[next] = dp[str] + 1;
                    // 将下一状态 push 如 que 中，进行后续分析
                    que.push(next);
                }
            }
        }
    }

}


int main()
{
    // 先得到所有状态
    bfs();
    int a[10], N;
    // 数组个数
    scanf("%d", &N);
    // 另一种输入方式
    /*
    while (~scanf("%d %d %d %d %d %d %d %d", &a[0], &a[1], &a[2], &a[3], &a[4], &a[5], &a[6], &a[7]));
    {
        string s;
        for(int i = 0; i < 8; i++)
        {
            s += a[i] + '0';
        }
    }
    */
    while (N--)
    {
        string s;
        for (int i = 0; i < 8; i++)
        {
            scanf("%d", &a[i]);
            s += a[i] + '0';
        }
        printf("%d", dp[s]);
    }

    return 0;
}

