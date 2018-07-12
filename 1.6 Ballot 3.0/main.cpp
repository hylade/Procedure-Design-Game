#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
/*
在2.0中方法只对四重循环程序中最内层的循环进行优化，接下来可以着眼于内侧的两个循环，也就是对 kc + kd = m - ka - kb 是否存在
由于存在两个需要考虑的数值，不能直接使用二分搜索，但是可以预先对 kc + kd 进行枚举，从而排序，便可重新使用二分搜索
此时，排序时间为 O(n^2logn);循环时间为O(n^2logn)
*/
const int MAX_N = 1000;
bool Binary_search(int x, int n, int k[]){
        int l = 0, r = n;
        while (r - l >= 1)
        {
            int i = (r + l) / 2;
            if (k[i] == x)
            {
                return true;
            }
            else if(k[i] < x)
            {
                l = i + 1;
            }
            else
            {
                r = i;
            }
        }
        return false;
    }

int main()
{
    int n, m, k[MAX_N * MAX_N];
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &k[i]);
    }
    for (int c = 0; c < n; c++)
    {
        for (int d = 0; d < n; d++)
        {
            k[c * n + d] = k[c] + k[d];
        }
    }
    sort(k, k + n * n);

    bool f = false;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
                if (Binary_search(m - k[i] - k[j], n, k))
                {
                    f = true;
                }
        }
    }
    if (f)
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }

    return 0;
}
