#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
/*
dijkstra �㷨ֻ���û�и��ߵ���������� bellman-ford �㷨��
�� d[i] ��������̾��룬��ô��ʹ���� d[j] = d[i] + (�� i �� j �ߵ�Ȩֵ) ����
��ô d[j] Ҳ��������̾��룬ͬʱ���� d[i] û�б仯��Ҳ��ѭ������ i ���������б�
�������˷�ʱ��

���� dijkstra �㷨�н����������޸ģ�
1. �ҵ���̾����Ѿ�ȷ���Ķ��㣬���������������ڶ������̾���
2. �˺�����Ҫ���� 1 �е�"��̾����Ѿ�ȷ���Ķ���"

����Ҫȷ����̾���ȷ���ĵ㣬�ʼ��ֻ��������̾�����ȷ���ģ�������δʹ�ù��Ķ�����
���� d[i] ��С�Ķ��������̾���ȷ���Ķ���

ʹ���ڽӾ���ʵ�� dijkstra �㷨�����Ӷ�Ϊ O(V^2)
*/
#define inf 0x7f7f7f7f // Ȩֵ����
int mat[100][100]; // �ڽӾ���
int V, E; // ���㼰������
int f, t, dis;
// �����Զ������ͣ��������� operator < ����д�ȽϺ���
// ����ڵ㣬���� id �͵�Դ����ľ���
struct node
{
    int id, weight;
    // ��Ҫʵ����С�ѣ����������У����������������СΪ��
    friend bool operator < (node a, node b)
    {
        return a.weight > b.weight;
    }
};
priority_queue<node> que;
// Դ�㵽���ж�������·
node d[100];
// �ж��Ƿ��Ѿ��ҵ����·��
bool visited[100];
// ���ڱ��游�׽ڵ㣬����ɾ��
int parent[100];
void dijkstra(int s)
{
    // ��ʼ��
    for (int i = 1; i <= V; i++)
    {
        d[i].id = i;
        // ��ʼ���������
        d[i].weight = inf;
        // �������и��ڵ��ҳ�ʼ�������û�з��ʹ�
        parent[i] = -1;
        visited[i] = false;
    }
    // Դ��ȨֵΪ 0
    d[s].weight = 0;
    que.push(d[s]);
    while (!que.empty())
    {
        // ȥ����ֵ���㵽�������
        node cd = que.top();
        que.pop();
        int u = cd.id;
        if (visited[u])
        {
            continue;
        }
        visited[u] = true;
        // �ɳڲ���
        for (int v = 1; v <= V; v++)
        {
            // �ҵ�������֮���ڵĶ��㣬�����ɳڲ��������¾��룬�� push �� que ��
            if (v != u && !visited[v] && d[v].weight > d[u].weight + mat[u][v])
            {
                d[v].weight = d[u].weight + mat[u][v];
                parent[v] = u;
                que.push(d[v]);
            }
        }
    }
}


int main()
{
    while (scanf("%d %d", &V, &E))
    {
        if (V == 0 && E == 0)
        {
            break;
        }
        // �ڽӾ����ʼ��
        for(int i = 1; i <= V; i++)
        {
            for (int j = i; j <= V; j++)
            {
                mat[i][j] = mat[j][i] = inf;
            }
        }

        // ��������ͨ�Ľڵ����
        for (int i = 0; i < E; i++)
        {
            scanf("%d %d %d", &f, &t, &dis);
            if (dis < mat[f][t])
            {
                mat[f][t] = mat[t][f] = dis;
            }
        }
        dijkstra(1);
        printf("%d", d[7].weight);
    }
    return 0;
}
