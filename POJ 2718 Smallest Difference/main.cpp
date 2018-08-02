#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string.h>
using namespace std;
/*
要想求两个数的最小值，就需要将原数值对半分，暴力求解方法如下
本题中关键在于使用 next_permutation() 函数求数的全排列
*/
// 生成数字数组，由于只有 0 - 9 是个数字
int a[10];
// 用于确定数字个数
int n;
// 定义无限大数
#define inf 0x3f3f3f3f
int solve()
{
    // 当首位为 0 时，需要使用 next_permutation 来进行全排列
    // 即对于当前序列 pn ，它的下一个序列 pn+1 满足：不存在其他序列 pm ，使 pn < pm < pn+1
    while (a[0] == 0)
    {
        // 防止首位为 0
        next_permutation(a, a + n);
    }
    int ans = inf;
    // 用于将数值一分为二
    int mid = (n + 1) / 2;
    // 进行 do - while 循环，这种方式将保证循环一定能进行一次
    do
    {
        // 当中间位置数值为 0 时，说明第二个数的首位将为 0 ，这种情况将不能满足使用全部数值的要求，故不进行分析
        if (a[mid])
        {
            int x = a[0], y = a[mid];
            // 得到第一个数
            for (int i = 1; i < mid; i++)
            {
                x = 10 * x + a[i];
            }
            // 得到第二个数
            for (int i = mid + 1; i < n; i++)
            {
                y = 10 * y + a[i];
            }
            // 判断此时差值与已有最小值的大小并决定是否替换
            if (ans > abs(x - y))
            {
                ans = abs(x - y);
            }
        }
        // 进行判断，是否还能继续执行 next_permutation ，若不存在排列，将返回 false ， 若存在则返回 true
    }while(next_permutation(a, a + n));
    return ans;
}
int main()
{
    int N;
    // 程序执行次数
    scanf("%d", &N);
    while (N--)
    {
        // 将数组 a 初始化为 0 ，这样对后续分析不会产生影响
        memset(a, 0, sizeof(a));
        // 初始数字个数为 0
        n = 0;
        char c;
        // 使用 getchar() 吃掉取 N 后敲击的回车键
        getchar();
        // 由于输入单字符时敲击回车键也会被输入，所以将定义 c 不能为回车键，否则将终止此次循环
        while (scanf("%c", &c), c != '\n')
        {
            // 当为空格时，将读取下一字符
            if (c == ' ')
            {
                continue;
            }
            // 将读取的字符输入到数组中
            a[n++] = c - '0';
        }
        // 当数组中元素只有一个时，直接输出
        if (n == 1)
        {
            printf("%d\n", a[0]);
        }
        // 当数组中元素有两个时，输出两者差值，由于从小到大输入，所以是后者减去前者
        else if (n == 2)
        {
            printf("%d\n", a[1] - a[0]);
        }
        // 当有多个数字时，则执行 solve 函数
        else
        {
            printf("%d\n", solve());
        }
    }


    return 0;
}
