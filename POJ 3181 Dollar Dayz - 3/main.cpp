#include <iostream>
#include <cstdio>
#include <algorithm>
#include <math.h>
#include <string.h>
using namespace std;
/*
对于 版本 -2 中的数组，其实可以简化为一维数组
*/
int N, K;
unsigned long long a[1005],b[1005],inf=1;

int main()
{
    while (scanf("%d %d", &N, &K))
    {
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        if (N == 0 && K == 0)
        {
            break;
        }
        inf = 1;
        for (int i = 1; i < 18; i++)
        {
            inf *= 10;
        }

        // 使用任何价格配出金额为 0 的方案数都是 1
        for (int i = 0; i <= K; i++)
        {
            a[0] = 1;
        }

        for (int i = 1; i <= K; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                if (j >= i)
                {
                    // 处理大数前面的部分，当超过 int64 时，就开始存入 b 数组，因为 int64 是 10^18 次方，保证当两个 a 相加时不会超过 int64
                    // 由于只将 a[0] 初始化，所以只有当 a 数组的值大于 inf 时， b 数组中才会有数值传入
                    b[j] = (b[j] + b[j - i]) + (a[j] + a[j - i]) / inf;
                    a[j] = (a[j] + a[j - i]) % inf;
                }
            }
        }
        if(b[N])
            cout << b[N];
        cout << a[N] << endl;
    }
    return 0;
}

