#include <iostream>
#include <cstdio>
#include <queue>
#include <string.h>
using namespace std;
int M; // 流星的数量
struct Meteor // 流星的位置及时间
{
    int x, y, t;
};
Meteor s, current; // s 表示将要移动到的位置， current 表示现在所处位置
int field[300][300]; // 场地
int direction[5][2] = {{0, 0},{1, 0}, {-1, 0}, {0, -1}, {0, 1}}; // 移动方向
queue<Meteor> que; // 将各个位置点信息作为队列输入

int bfs()
{
    if (field[0][0] == 0) // 当开始位置在 0 时被流星砸中，说明直接死亡，返回失败值 -1
    {
        return -1;
    }

    if (field[0][0] == -1) // 当开始位置不会被流星砸中，说明可以直接待在原地，不需要移动，此时时间为 0
    {
        return 0;
    }

    // 开始点信息
    s.x = 0;
    s.y = 0;
    s.t = 0;

    // 将开始点 push 到队列中
    que.push(s);
    while (!que.empty())
    {
        // 现在所处为置
        current = que.front();
        // 对于搜索过的点就 pop 掉
        que.pop();

        for (int j = 0; j < 5; j++)
        {
            // 对于多个方向进行搜索，由于移动距离为 1 ，时间也需要增加 1
            s.x = current.x + direction[j][0];
            s.y = current.y + direction[j][1];
            s.t = current.t + 1;

            // 当移动后点位置超过范围，则搜索下一个点
            if (s.x < 0 || s.x > 300 || s.y < 0 || s.y > 300)
            {
                continue;
            }
            // 若搜索到位置点为 -1 ，说明该点始终不会遭受流星，故可以输出此时移动的移动时间
            if (field[s.x][s.y] == -1)
            {
                return s.t;
            }
            // 若此时移动该该点的时间已经大于此地流星砸落的最少时间，则需要更改线路
            if (s.t >= field[s.x][s.y])
            {
                continue;
            }
            // 其余情况，则使该点的移动时间增加 1 ，方便后续进行对比
            field[s.x][s.y] = s.t;
            // 并且将移动后的位置点重新 push 到队列中，作为下次的出发点
            que.push(s);
        }
    }
    return -1;
}
int main()
{
    // 首先使场地时间都是 -1 ；方便进行判断
    memset(field, -1, sizeof(field));
    // 输入流星数量
    scanf("%d", &M);
    while (M--)
    {
        int x, y, t;

        // 输入各个流星的位置和时间
        scanf("%d %d %d", &x, &y, &t);

        // 进行场地生成
        for (int j = 0; j < 5; j++)
        {
            // 漫游进行判断
            int nx = x + direction[j][0];
            int ny = y + direction[j][1];
            if (nx < 0 || nx >= 300 || ny < 0 || ny >= 300)
            {
                continue;
            }
            // 当之前没有流星砸中，则该点的时间为 t
            if (field[nx][ny] == -1)
            {
                field[nx][ny] = t;
            }
            // 当前后有多个流星，则需要记录最小流星砸中时间
            else
            {
                field[nx][ny] = min(field[nx][ny], t);
            }
        }
    }

    printf("%d", bfs());

    return 0;
}
