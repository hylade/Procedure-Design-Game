#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX_N = 1000;
bool Binary_search(int x, int n, int k[]){ //通过二分搜索，降低时间复杂度，由O(n^4)变为O(n^3logn)
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
    int n, m, k[MAX_N];
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &k[i]);
    }

    sort(k, k+n); // sort函数有三个参数，第三个参数是排序的方法，可以正序，也可以倒序，此参数可以不填；
                  // 其余两个参数必填，第一个参数是数组的起始地址，第二个是结束地址

    bool f = false;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int a = 0; a < n; a++)
                {
                    if (Binary_search(m - k[i] - k[j] - k[a], n, k))
                    {
                        f = true;
                    }
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
