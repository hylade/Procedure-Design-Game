#include <iostream>
#include <cstdio>
#include <math.h>
#include <algorithm>
using namespace std;
/*
对于 N 个数字，可以看出，最先合并的数字被开根号的次数最多，所以越大的数字应该越先合并
所以先排序，从大到小一个个合并
*/
double a[100];
int N;

int main()
{
    while (scanf("%d", &N) != EOF)
    {
        for (int i = 0; i < N; i++)
        {
            scanf("%lf", &a[i]);
        }

        // 排序
        sort(a, a + N, greater<double>());

        // 对于 double 类型的变量，在 printf 的说明符可以使用 %f 或者 %lf
        // 在 scanf 中的说明符只能使用 %lf
        double ans = a[0];

        // 循环合并
        for (int i = 1; i < N; i++)
        {
            ans = 2 * sqrt(ans * a[i]);
        }

        // 输出
        printf("%.3lf", ans);
    }

    return 0;
}
