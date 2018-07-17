#include <iostream>
#include <cstdio>
using namespace std;
/*
可以将长度 Li 按照大小顺序排列，最短的板应该就是 L1 而次短的为 L2。
同时它们为兄弟节点，那么意味着它们是从一块长度为 (L1 + L2) 的板切割而来，
这样在该次切割前，各板长度为 (L1 + L2), L3, L4...LN
此时共有 N - 1 块木板。递归求解即可
*/
int n;
int L[50000];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &L[i]);
    }

    int ans = 0;

    while (n > 1)
    {
        int mii1 = 0, mii2 = 1;
        if (L[mii1] > L[mii2])
        {
            swap(mii1, mii2);
        }
        for (int i = 2; i < n; i++) // 使 mii1 为最小值，同时 mii2 为次小值
        {
            if (L[i] < L[mii1])
            {
                mii2 = mii1;
                mii1 = i;
            }
            else if (L[i] < L[mii2])
            {
                mii2 = i;
            }
        }

        int t = L[mii1] + L[mii2]; // 将最小两值相加，等同于获得这两个值的木板长度
        ans += t; // 添加相应的费用

        if (mii1 == n - 1) // 由于后续代码中，需要将未切割木板长度添加进数组中，同时数组长度在不断减小，
                           // 不能使其在最后一位而被删除
        {
            swap(mii1, mii2);
        }
        L[mii1] = t; // 将新获得的未切割木板长度添加，此时 mii1 长度由于已经使用，可以被替换
        L[mii2] = L[n - 1]; // 将 mii2 的长度进行替换，由于 mii2 已被使用，可以被替换，同时若 mii2 不在最后一位，
                            // 则需要将最后一位进行保存；若本身就是最后一位，也不会产生影响
        n--;
    }

    printf("%d", ans);

    return 0;
}
