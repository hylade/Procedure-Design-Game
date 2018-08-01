#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
// ���볡��ά�ȼ����������
int H, W, N;
char field[1000][1000];
// ���㵽��ǰ�����ľ���
int d[1000][1000];
// ʹ�ö�ά����ȷ��������λ��
int factory[15][2];
// ����λ��
typedef pair<int, int> P;
// ���巽��
int direcion[4][2] = {
{-1, 0},
{1, 0},
{0, -1},
{0, 1},
};

int bfs(int sx, int sy, int gx, int gy)
{
    // ��δ���ʵ�λ��ȷ��Ϊ -1
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            d[i][j] = -1;
        }
    }
    // ����λ�ö���
    queue<P> que;
    // ����ʼλ����������
    que.push(P(sx, sy));
    // ��ʼ�����Ϊ 0
    d[sx][sy] = 0;

    while (que.size())
    {
        // ȡ���� que �и���λ�õ���о������
        P p = que.front();
        // ����ȡ����λ�õ㲻�ٽ��з��� pop ��
        que.pop();
        // ������յ㣬�ͽ�����ѭ��
        if(p.first == gx && p.second == gy)
            break;
        // �ķ������Σ�Ѱ��λ�õ�
        for(int i = 0; i < 4; i++)
        {
            int nx = p.first + direcion[i][0];
            int ny = p.second + direcion[i][1];
            // ȷ���õ��Ƿ��ƶ������Ҹõ��Ƿ�û�з��ʹ�
            if (nx >= 0 && nx <= H && ny >= 0 && ny <= W && field[nx][ny] != 'X' && d[nx][ny] == -1)
            {
                // ������ 1 �������ĵ㣬push �������У����ں�������
                que.push(P(nx, ny));
                // ���뽫���� 1
                d[nx][ny] = d[p.first][p.second] + 1;
            }
        }
    }
    // ���ص��յ�ľ���
    return d[gx][gy];
}
int main()
{
    scanf("%d %d %d", &H, &W, &N);
    for (int i = 0; i < H; i++)
    {
        // �������ͼ
        scanf("%s", field[i]);
    }
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            // �ҵ� S ��㣬���� 'S' ��Ϊ . ��ʹ����Ҳ���ڴ˵��ƶ������ұ����������
            if (field[i][j] == 'S')
            {
                field[i][j] = '.';
                factory[0][0] = i;
                factory[0][1] = j;
            }
            // �������֣��������
            else if (isdigit(field[i][j]))
            {
                // ���湤�������
                int fac = field[i][j] - '0';
                factory[fac][0] = i;
                factory[fac][1] = j;
            }
        }
    }

    // ���ܾ��붨��Ϊ step
    int step = 0;
    for (int i = 0; i < N; i++)
    {
        step += bfs(factory[i][0], factory[i][1], factory[i + 1][0], factory[i + 1][1]);
    }
    printf("%d", step);


    return 0;
}
