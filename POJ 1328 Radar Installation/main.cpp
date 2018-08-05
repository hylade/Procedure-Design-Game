#include <iostream>
#include <cstdio>
#include <algorithm>
#include <math.h>
using namespace std;
/*
本题使用贪心算法，对于岛屿到海岸线的距离 y ，当 y > r 时，说明雷达无论如何都到达不了岛屿位置，故直接输出 -1
当 y <= r 时，则雷达的建造有一个活动区域 [x1, x2] ，因此，可以针对每个岛屿求得相应的活动区间，该问题随即转化为最少区间的选择问题

在 n 个区间内选择一个区间集合，该集合中各个区间都不相交，同时集合中的元素个数最少，此时个数便是解
*/
// 定义区间的左右侧
struct coordinate{
    double left;
    double right;
};
// 对于每个点都有其区间， temp 用于确定当前区间范围
coordinate p[1005], temp;
double r;
int n;
int flag;
// 用于排序
bool sor(coordinate a, coordinate b)
{
    return a.left < b.left;
}

int main()
{
    // cas 用来确定输出的序号
    int cas = 0;
    // 输入 n 、 r
    while (scanf("%d %lf", &n, &r))
    {
        // 通过 flag 确定是否有不能覆盖的点
        flag = 0;
        // 当输入 0 0 时结束
        if (n == 0 && r == 0)
        {
            break;
        }
        // 输入各个点坐标
        for (int i = 0; i < n; i++)
        {
            double a, b;
            scanf("%lf %lf", &a, &b);
            // 当 b > r 时，将 flag 改为 1 ，在输出时便可由此依据
            if (b > r)
            {
                flag = 1;
            }
            // 确定各个点区间
            else{
                p[i].left = a - sqrt(r * r - b * b);
                p[i].right = a + sqrt(r * r - b * b);
            }
        }

        printf("Case %d:", ++cas);

        // 当 flag 为 1 时便输出 -1
        if (flag)
        {
            printf("-1\n");
        }
        else{
            // 从最左端开始扫描，个数初始化为 1
            int count = 1;
            // 将各个点区间进行排列，方便从左开始扫描
            sort(p, p + n, sor);
            // 用于确定当前区间
            temp = p[0];

            for (int i = 1; i < n; i++)
            {
                // 不重叠情况，此时需要加一个区间，并且当前区间 temp 要置为 p[i]
                if (p[i].left > temp.right)
                {
                    count += 1;
                    temp = p[i];
                }
                // 此时为重叠情况，此时需要使用小区间，但个数不用叠加
                else if (p[i].right < temp.right){
                    temp = p[i];
                }
                // 对于部分重叠的情况，将使用重叠区间，仍使用当前区间 temp 的右侧坐标即可
            }
            printf("%d\n", count);
        }
        printf("\n");

    }


    return 0;
}
