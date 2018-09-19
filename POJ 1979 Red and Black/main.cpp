#include <iostream>
#include <cstdio>
using namespace std;

int H, W; // ������εĴ�С
char field[20][20]; // ����
int dfs(int x, int y, char field[][20])
{
    if (x < 0 || x >= H || y < 0 || y >= W || field[x][y] == '#') // ��Խ����λ��Ϊ '#' ʱ���� 0
        return 0;
    int n = 1;
    field[x][y] = '#'; // ��ֹ�ظ�����
    n += dfs(x - 1, y, field) + dfs(x + 1, y, field) + dfs(x, y - 1, field) + dfs(x, y + 1, field);
    return n;
}

int main()
{
    int t1, t2;
    scanf("%d %d", &H, &W);
    for (int i = 0; i < H; i++)
    {
        scanf("%s", field[i]);
    }

    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            if (field[i][j] == '@') // ���ҿ�ʼ��
            {
                t1 = i;
                t2 = j;
            }
        }
    }
    printf("%d", dfs(t1, t2, field));

    return 0;
}
