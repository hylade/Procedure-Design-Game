#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

/*
使用 C++ 标准库中的 next_permutation 函数，将 n 个元素的共 n！ 种不同的排列生成出来
*/

/*
特殊状态的枚举代码大致如下：
bool used[MAX_N]
int perm[MAX_N]
// 生成{0, 1, 2, 3,..., n-1}的 n！ 种排列

void permutation1(int pos, int n)
{
    if (pos == n)
    {
        // 在此处编写对 perm 的操作
    }
    // return ;
}

// 针对 perm 的第 pos 个位置，究竟使用 0 ~ n-1 中哪个进行循环
for (int i = 0; i < n ; i++)
{
    if (!used[i])
    {
        perm[pos] = i;
        // i 已经被使用，所以要将标记设为 true
        used[i] = true;
        permutation1(pos + 1, n);
        // 返回后将标记复原
        used[i] = false;
    }
    return ;
}
*/

/*
示例：
Description：小明十分聪明，而且十分擅长排列计算。
比如给小明一个数字5，他能立刻给出1-5按字典序的全排列，如果你想为难他，在这5个数字中选出几个数字让他继续全排列，
那么你就错了，他同样的很擅长。现在需要你写一个程序来验证擅长排列的小明到底对不对。

Input：
第一行输入整数N（1<N<10）表示多少组测试数据，
每组测试数据第一行两个整数 n m (1<n<9,0<m<=n)

Output：
在1-n中选取m个字符进行全排列，按字典序全部输出,每种排列占一行，每组数据间不需分界。如样例

Sample：
Input：
2
3 1
4 2

Output：
1
2
3
12
13
14
21
23
24
31
32
34
41
42
43
*/

bool used[100];
int perm[100];
int a, n, m;

void permutation(int pos, int r)
{
    if (pos == r)
    {
        for (int i = 0; i < pos; i++)
        {
            printf("%d", perm[i]);
        }
        printf("\n");
        return ;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!used[i])
        {
            perm[pos] = i;
            used[i] = true;
            permutation(pos + 1, r);
            used[i] = false;
        }
    }
}

int main()
{
    scanf("%d", &a);
    while (a--) // 次数
    {
        scanf("%d %d", &n, &m); // 输入 n 和 m
        permutation(0, m);
    }


    return 0;
}
