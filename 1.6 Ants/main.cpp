#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int t, l, n, pos, minans, maxans;

    scanf("%d", &t);;
    while(t--) {
        minans = 0;
        maxans = 0;

        scanf("%d %d", &l, &n);
        for(int i = 1; i <= n; i++) {
            scanf("%d", &pos);

            minans = max(minans, min(pos, l - pos)); // 对于最短时间，应当Ant都朝较短的一侧爬行时的较大值

            maxans = max(maxans, max(pos, l - pos)); // 对于最长时间，应为Ant朝较长一侧爬行时的最大值，两只Ant相互接触后，其实可以认为
                                                     // 仍朝原方向运动，这是因为两只蚂蚁不区分速度
        }

        printf("%d %d\n", minans, maxans);
    }

    return 0;
}
