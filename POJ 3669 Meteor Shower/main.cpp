#include <iostream>
#include <cstdio>
#include <queue>
#include <string.h>
using namespace std;
int M; // ���ǵ�����
struct Meteor // ���ǵ�λ�ü�ʱ��
{
    int x, y, t;
};
Meteor s, current; // s ��ʾ��Ҫ�ƶ�����λ�ã� current ��ʾ��������λ��
int field[300][300]; // ����
int direction[5][2] = {{0, 0},{1, 0}, {-1, 0}, {0, -1}, {0, 1}}; // �ƶ�����
queue<Meteor> que; // ������λ�õ���Ϣ��Ϊ��������

int bfs()
{
    if (field[0][0] == 0) // ����ʼλ���� 0 ʱ���������У�˵��ֱ������������ʧ��ֵ -1
    {
        return -1;
    }

    if (field[0][0] == -1) // ����ʼλ�ò��ᱻ�������У�˵������ֱ�Ӵ���ԭ�أ�����Ҫ�ƶ�����ʱʱ��Ϊ 0
    {
        return 0;
    }

    // ��ʼ����Ϣ
    s.x = 0;
    s.y = 0;
    s.t = 0;

    // ����ʼ�� push ��������
    que.push(s);
    while (!que.empty())
    {
        // ��������Ϊ��
        current = que.front();
        // �����������ĵ�� pop ��
        que.pop();

        for (int j = 0; j < 5; j++)
        {
            // ���ڶ��������������������ƶ�����Ϊ 1 ��ʱ��Ҳ��Ҫ���� 1
            s.x = current.x + direction[j][0];
            s.y = current.y + direction[j][1];
            s.t = current.t + 1;

            // ���ƶ����λ�ó�����Χ����������һ����
            if (s.x < 0 || s.x > 300 || s.y < 0 || s.y > 300)
            {
                continue;
            }
            // ��������λ�õ�Ϊ -1 ��˵���õ�ʼ�ղ����������ǣ��ʿ��������ʱ�ƶ����ƶ�ʱ��
            if (field[s.x][s.y] == -1)
            {
                return s.t;
            }
            // ����ʱ�ƶ��øõ��ʱ���Ѿ����ڴ˵��������������ʱ�䣬����Ҫ������·
            if (s.t >= field[s.x][s.y])
            {
                continue;
            }
            // �����������ʹ�õ���ƶ�ʱ������ 1 ������������жԱ�
            field[s.x][s.y] = s.t;
            // ���ҽ��ƶ����λ�õ����� push �������У���Ϊ�´εĳ�����
            que.push(s);
        }
    }
    return -1;
}
int main()
{
    // ����ʹ����ʱ�䶼�� -1 ����������ж�
    memset(field, -1, sizeof(field));
    // ������������
    scanf("%d", &M);
    while (M--)
    {
        int x, y, t;

        // ����������ǵ�λ�ú�ʱ��
        scanf("%d %d %d", &x, &y, &t);

        // ���г�������
        for (int j = 0; j < 5; j++)
        {
            // ���ν����ж�
            int nx = x + direction[j][0];
            int ny = y + direction[j][1];
            if (nx < 0 || nx >= 300 || ny < 0 || ny >= 300)
            {
                continue;
            }
            // ��֮ǰû���������У���õ��ʱ��Ϊ t
            if (field[nx][ny] == -1)
            {
                field[nx][ny] = t;
            }
            // ��ǰ���ж�����ǣ�����Ҫ��¼��С��������ʱ��
            else
            {
                field[nx][ny] = min(field[nx][ny], t);
            }
        }
    }

    printf("%d", bfs());

    return 0;
}
