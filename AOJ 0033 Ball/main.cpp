#include <iostream>
#include <cstdio>
using namespace std;
// 该题思路：
// 每次判断当前小球是否大于左边容器最上端的球，如果可以就放
// 否则就去看右侧，一旦发现左右两侧都不能放，就判断为 NO
int N;
int a[10];
int flag;
void dfs(int x, int l, int r)
{
    if (x == 10) // 最后结果一次检查 x 应该是 10
    {
        return ;
    }

    if (a[x] > l) // 先对左侧进行检查，若大，则将该数字添加至左侧
    {
        dfs(x + 1, a[x], r);
    }
    else if (a[x] > r) // 否则就添加至右侧
    {
        dfs(x + 1, l, a[x]);
    }
    else // 当左右两侧都不通过时，则将 flag 变为 1
    {
        flag = 1;
        return ;
    }
}
int main()
{
    scanf("%d", &N);
    while (N--)
    {
        flag = 0; // 通过标记 flag 进行判断
        for (int i = 0; i < 10; i++)
        {
            scanf("%d", &a[i]);
        }

        dfs(0, 0, 0);
        if (flag == 0)
        {
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }


    return 0;
}
