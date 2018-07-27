#include <iostream>
#include <cstdio>
using namespace std;

int H, W;
char field[100][100];
int ans = 0;

void dfs(int x, int y, char c)
{
    if (x < 0 || x > H || y < 0 || y > W) // �������ߴ�ʱ�������ж�
        return ;
    field[x][y] = '!'; // ����ǰ�жϹ��ĵ���Ϊ '!'
    if (field[x - 1][y] == c)
    {
        dfs(x - 1, y, c);
    }
    if (field[x + 1][y] == c)
    {
        dfs(x + 1, y, c);
    }
    if (field[x][y - 1] == c)
    {
        dfs(x, y - 1, c);
    }
    if (field[x][y + 1] == c)
    {
        dfs(x, y + 1, c);
    }
}
int main()
{
    while(scanf("%d %d", &H, &W) != EOF) // �������
    {
        if (H == 0 && W == 0)
        {
            break; // ���������������ʱ������
        }
        for (int i = 0; i < H; i++)
        {
            scanf("%s", field[i]); // ����
        }

        for (int i = 0; i < H; i++)
        {
            for (int j = 0; j < W; j++)
            {
                if (field[i][j] != '!') // ���õ㻹û���жϹ�������в���
                {
                    dfs(i, j, field[i][j]); // ͨ�� dfs �ж���Χ��ͬ�ĵ㣬���ҽ���ͬ�ĵ㶼��Ϊ '!'
                    ans += 1; // �������� 1
                }
            }
        }
        printf("%d", ans);
    }

    return 0;
}
