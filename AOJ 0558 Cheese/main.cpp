#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
// 输入场地维度及工厂最大编号
int H, W, N;
char field[1000][1000];
// 各点到当前工厂的距离
int d[1000][1000];
// 使用二维数组确定工厂的位置
int factory[15][2];
// 定义位置
typedef pair<int, int> P;
// 定义方向
int direcion[4][2] = {
{-1, 0},
{1, 0},
{0, -1},
{0, 1},
};

int bfs(int sx, int sy, int gx, int gy)
{
    // 将未访问的位置确定为 -1
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            d[i][j] = -1;
        }
    }
    // 定义位置队列
    queue<P> que;
    // 将初始位置添加入队列
    que.push(P(sx, sy));
    // 初始点距离为 0
    d[sx][sy] = 0;

    while (que.size())
    {
        // 取队列 que 中各个位置点进行距离分析
        P p = que.front();
        // 对于取过的位置点不再进行分析 pop 掉
        que.pop();
        // 如果是终点，就结束该循环
        if(p.first == gx && p.second == gy)
            break;
        // 四方向漫游，寻找位置点
        for(int i = 0; i < 4; i++)
        {
            int nx = p.first + direcion[i][0];
            int ny = p.second + direcion[i][1];
            // 确定该点是否移动，并且该点是否没有访问过
            if (nx >= 0 && nx <= H && ny >= 0 && ny <= W && field[nx][ny] != 'X' && d[nx][ny] == -1)
            {
                // 将运行 1 个距离后的点，push 到队列中，便于后续分析
                que.push(P(nx, ny));
                // 距离将增加 1
                d[nx][ny] = d[p.first][p.second] + 1;
            }
        }
    }
    // 返回到终点的距离
    return d[gx][gy];
}
int main()
{
    scanf("%d %d %d", &H, &W, &N);
    for (int i = 0; i < H; i++)
    {
        // 输入地形图
        scanf("%s", field[i]);
    }
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            // 找到 S 起点，并将 'S' 变为 . ，使后续也可在此点移动；并且保存其坐标点
            if (field[i][j] == 'S')
            {
                field[i][j] = '.';
                factory[0][0] = i;
                factory[0][1] = j;
            }
            // 若是数字，则代表工厂
            else if (isdigit(field[i][j]))
            {
                // 保存工厂坐标点
                int fac = field[i][j] - '0';
                factory[fac][0] = i;
                factory[fac][1] = j;
            }
        }
    }

    // 将总距离定义为 step
    int step = 0;
    for (int i = 0; i < N; i++)
    {
        step += bfs(factory[i][0], factory[i][1], factory[i + 1][0], factory[i + 1][1]);
    }
    printf("%d", step);


    return 0;
}
