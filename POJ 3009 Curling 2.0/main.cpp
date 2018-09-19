#include <iostream>
#include <cstdio>
using namespace std;

int n;
int field[20][20];
int h, w;
int t1, t2, c, minstep;
int direc[4][2] = {
    {0, -1},
    {0, 1},
    {-1, 0},
    {1, 0},
};
void dfs(int x, int y, int c)
{
    if (c >= 10 || c > minstep) // 对于步数 c ，当 c 超过规定值时，便可以不用进行运行
    {
        return ;
    }

    for (int i = 0; i < 4; i++) // 对于移动方向进行选择
    {
        int cx = x;
        int cy = y; // 移动初始位置

        while (cx >= 0 && cx <= h && cy >= 0 && cy <= w) // 保证移动后仍在场地内
        {
            switch (field[cx][cy]) // 对移动后位置情况进行判断，有 0 ， 1 ， 3 ，3种情况
            {
                case 0:{
                    cx += direc[i][1];
                    cy += direc[i][0]; // 当按照该移动方向碰到 0 时，说明仍能朝该方向运动
                    break; // 运动后便需要判断新位置情况，故需要跳出 switch ，从 while 开始判断
                }
                case 3:
                    {
                        if (c + 1 < minstep) // 此时若抵达终点，则需要判断步数与最小步数的较小值，若小于 minstep ，则将步数赋予 minstep
                        {
                            minstep = c + 1;
                        }
                        cx = -1; // 由于抵达终点，需要跳出 while ，使用新的移动方案
                        break; // 跳出 switch
                    }
                case 1:{
                    if (!(cx - direc[i][1] == x && cy - direc[i][0] == y)) // 当 if 语句判断为 true 时，说明移动位置与初始位置不相邻，此时
                                                                           // 可以将石块（3）打碎，变为 0 ，同时将该位置作为初始位置判断后续情况
                    {
                        field[cx][cy] = 0;
                        dfs(cx - direc[i][1], cy - direc[i][0], c + 1);
                        field[cx][cy] = 1; // 由于还要考虑其他情况，所以仍要将该位置变回 1
                    }
                    cx  = -1; // 当 if 语句为 false 时，说明初始位置与移动位置相邻，不能超该方向移动，便需要跳出 while ，重新定义移动方向
                              // 或者当 if 语句为 true ，但已经做完上述过程判定，需要跳出 while
                    break;
                }
            }
        }
    }
}
int main()
{
    scanf("%d", &n); // 需要试验次数
    while (n--)
    {
        scanf("%d %d", &h, &w); // 场地大小
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                scanf("%d", &field[i][j]); // 场地
            }
        }

        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                if (field[i][j] == 2) // 开始位置
                {
                    t1 = i;
                    t2 = j; // 保存开始位置
                    break;
                }
            }
        }

        field[t1][t2] = 0; // 由于已经找到开始位置，可以将该位置数字 '2' 变为 '0' ,使其也可以处于运动路径中
        minstep = 11; // 先确定 minstep 为 11 ，当 dfs 无法达到终点位置时，也能保证输出 minstep > 10
        dfs(t1, t2, 0);
        if (minstep > 10)
        {
            minstep = -1; // 按照要求，若无法达到终点或超过步数 10 ，则输出 -1
        }
        printf("%d", minstep);
    }


    return 0;
}
