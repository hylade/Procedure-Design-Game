#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
/*
对于该问题，可以从最左侧开始考虑，对于这个点，带有标记的点一定在其右侧（包括其自身）
标记的点应该是距离 R 以内，距离最远的点
加上了第一个标记的点后，剩下的部分也可用同样的办法处理，对于添加了符号的点右侧超过 R 的下一个点
采用同样的方法找到其右侧 R 距离以内最远的点进行标记，在所有的点都被覆盖之前一直重复过程
*/
int n, r;
int x[1000];
int main()
{
    scanf("%d %d", &n, &r);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x[i]);
    }

    sort(x, x + n);

    int i = 0, ans = 0;
    while(i < n)
    {
        int s = x[i++]; // s 是没有被覆盖的最左的点
        while (i < n && x[i] - s > r) // 一直向右前进直到距 s 的距离大于 R 的点
        {
            i++;
        }
        int p = x[i - 1]; // p 是新加上标记的点的位置
        while (i < n && x[i] <= p + r) // 一直向右前进直到距 p 距离大于 R 的点，即寻找下一个进行分析的点
        {
            i++;
        }
        ans++; // 完成一个标记点
    }
    printf("%d", ans);



    return 0;
}
