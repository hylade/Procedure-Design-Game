#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
/*
ʹ���ڽӾ�����ģ�⣬ͨ�� bfs ����ͼ
*/
bool flag = false;
// �ڽӾ���
int G[100][100];
int V, E;
// ������ɫ��ʼ��Ϊ 0 ����ɫ������ 1 �� -1
int color[100];

bool bfs(int v)
{
    // ������ȾɫΪ 1
    color[v] = 1;
    queue<int> que;
    que.push(v);
    while (!que.empty())
    {
        int from = que.front();
        que.pop();
        for (int i = 1; i <= V; i++)
        {
            // �����ڵĵ�û��Ⱦɫ����ɫ
            if(G[from][i] && color[i] == 0)
            {
                que.push(i);
                color[i] = -color[from];
            }
            // �����ڵĵ���ɫ��ͬ���ͷ��� false
            if (G[from][i] && color[i] == color[from])
                return false;
        }
    }
    // �����ڵĵ㶼��Ⱦ��ɫ�������ڵ���ɫ������ͬ
    return true;
}

void solve()
{
    for (int i = 1; i <= V; i++)
    {
        // ����û��Ⱦɫ���㿪ʼ bfs ����
        if (color[i] == 0 && !bfs(i))
        {
            flag = true;
            break;
        }
    }
}
// �������ӱ�����ͼ����ڵ�ͱ�
int main()
{
    scanf("%d %d", &V, &E);
    for (int i = 0; i < E; i++)
    {
        int s, t;
        scanf("%d %d", &s, &t);
        // �ڽӾ��󴴽�
        G[s][t] = G[t][s] = 1;
    }
    solve();
    if (flag)
    {
        printf("NO\n");
    }
    else
    {
        printf("YES\n");
    }

    return 0;
}
