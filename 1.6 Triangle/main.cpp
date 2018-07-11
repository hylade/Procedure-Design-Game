#include <iostream>
#include <cstdio>
using namespace std;
const int MAX_N = 100;
int main()
{
    int MAX_L = 0;
    int L = 0;
    int n, k[MAX_N];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &k[i]);
    }
    for (int a = 0; a < n; a++) //三重循环
    {
        for (int b = a + 1; b < n; b++)
        {
            for (int c = b + 1; c < n; c++)
            {
                int MAX_I = max(k[a], max(k[b], k[c]));
                int REST = k[a] + k[b] + k[c] - MAX_I;
                if (MAX_I < REST) //最大值需要小于另两者之和时，可以形成三角形
                {
                    L = k[a] + k[b] + k[c];
                    if (L > MAX_L)
                    {
                        MAX_L = L;
                    }
                }
                else
                {
                    L = 0;
                }
            }
        }
    }
    printf("%d", MAX_L);

    return 0;
}
