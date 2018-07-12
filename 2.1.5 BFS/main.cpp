#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

/*
��������������BFS, Breadth-First Search����һ�������ֶΣ�����������������ƣ���ĳ��״̬�����������п��Դﵽ��״̬
�� DFS ��ͬ����������˳�򣬿��������������������������ʼ״̬����״̬��
Ҳ����˵�����ǰ��տ�ʼ״̬-ֻ�� 1 ��ת�ƾͿ��Ե��������״̬-ֻ�� 2 ��ת�ƾͿ��Ե��������״̬...
����ͬһ��״̬��������������ֻ����һ�Σ���˸��Ӷ�Ϊ O(״̬��*ת�Ƶķ�ʽ)

�������������ʵ��������ջ���м��㣨�����ȳ���������������������ʹ���˶��У��Ƚ��ȳ���
����ʱ���Ƚ���ʼ״̬���ӵ�������˺�Ӷ��е���ǰ�˲���ȡ��״̬���Ѵ�״̬����ת�Ƶ�״̬����δ���ʵ�״̬������У�
���������ֱ�����б�ȡ�ջ��ҵ���

��ʵ�����ǰ��ճ�ʼ�����ɽ���Զ��˳����������ϵ��£�������
*/
const int INF = 100000000;
// ʹ�� pair ��ʾ״̬ʱ��ʹ�� typedef ���ж�����ӷ���
typedef pair<int, int> P;
int sx, sy; // �������
int gx, gy; // �յ�����
int n, m;
char field[100][100]; // �Թ��ַ���

/*
�����У�״̬��ΪĿǰ����λ�õ����꣬��˿��Թ���� pair ���߱���� int ������״̬
��״̬����ʱ����Ҫ��װ��������ʾ
ת�Ƶķ�������Ϊ�ķ����ƶ���״̬�����Թ��Ĵ�С��ȣ����Ը��Ӷ��� O(4 * N * M) = O(N* M)

���ڱ��������й����У����Ի�õ�����λ�õ���̾��룬���� d[N][M] ���齫��̾��뱣��������ͬʱ��ʼʱ���ô��� INF ����ʼ������Ҫע��������
*/

int d[100][100];
// �ĸ�������ƶ�����
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

int bfs()
{
    queue<P> que;
    for (int a = 0; a < n; a++)
    {
        for (int b = 0; b < m; b++)
        {
            // ������λ�ö���ʼ��Ϊ INF
            d[a][b] = INF;
        }
    }

    // �����������
    que.push(P(sx, sy));
    // �������̾�����Ϊ 0
    d[sx][sy] = 0;

    // ѭ��ֱ������ que ����Ϊ 0
    while (que.size())
    {
        // �Ӷ�����ǰ��ȡ��Ԫ�� P
        P p = que.front();
        que.pop();
        // ��ȡ����ֵΪ�յ�λ�ã����������
        if (p.first == gx && p.second == gy)
        {
            break;
        }
        for (int i = 0; i < 4; i++)
        {
            // �ƶ���λ�� nx�� ny
            int nx = p.first + dx[i], ny = p.second + dy[i];
        // �ж��Ƿ�����ƶ����Ƿ��Ѿ����ʹ����� d[nx][ny] != INF �����Ѿ����ʹ�
            if (0 <= nx && nx <= n && 0 <= ny && ny <= m && field[nx][ny] != '#' && d[nx][ny] == INF)
            {
                // �������ƶ�����ǽ�ڣ�����������������У�ͬʱ����λ�õľ������� 1
                que.push(P(nx, ny));
                d[nx][ny] = d[p.first][p.second] + 1;
            }
        }
    }
    return d[gx][gy];
}
int main()
{
    scanf("%d %d", &n, &m);
    for (int k = 0; k < n; k++)
    {
        scanf("%s", field[k]); // �Թ�
    }
    sx = 0, sy = 1, gx = 9, gy = 8;
    int time = bfs();
    printf("%d", time);

    return 0;
}

/*
�ܽ᣺
�������������������������һ��������������е�״̬�����ǵݹ麯����д��Ϊ��̣����������Ƽ�ʹ�������������
���������·ʱ�������������Ҫ��������ͬ����״̬����ʱӦʹ�ÿ�����������

���������������״ֱ̬�Ӽ�����У�ͨ����Ҫ��״̬�������ȵ��ڴ�ռ䣬��֮��������������������ĵݹ���ȳ�����
һ����״̬����ȣ��ݹ���Ȳ���̫�����Կ���Ϊ������������Ͻ�ʡ�ڴ�
*/