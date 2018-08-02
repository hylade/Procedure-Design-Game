#include <iostream>
#include <cstdio>
#include <string.h>
#include <algorithm>
using namespace std;

/*
确定数组的范围和长度，暴力枚举数列，接下来类似于杨辉三角的递推计算
permutation 从递增有序数列开始枚举，直到找到符合 Sum 的值退出即可
*/
// 定义数字个数，执行次数，和
int N, M, Sum;
// 定义中间结果表示方式
int a[10][10];
int main()
{
    // 输入
    scanf("%d %d %d", &M, &N, &Sum);
    while (M--)
    {
        // 数字取值
        int c[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        do
        {
            // 按照 c 中数字排列赋值给 a 数组
            for (int i = 0; i < N; i++)
            {
                a[0][i] = c[i];
            }

            // 计算下一行的和，从而得到最后一个加和得到的数值
            for (int i = 1; i < N; i++)
            {
                for (int j = 0; j < N - i; j++)
                {
                    a[i][j] = a[i - 1][j] + a[i - 1][j + 1];
                }
            }
            // 若该排列最终数值与 Sum 相同则 break
            if (a[N - 1][0] == Sum)
            {
                break;
            }
            // 不然则需要 next_permutation 进行下一次排列
        }while (next_permutation(c, c + N));

        // 得到最终排列的情况下，输出该排列方式
        for (int i = 0; i < N; i++)
        {
            printf("%d", c[i]);
            printf(" ");
        }

        printf("\n");

    }

    return 0;
}
