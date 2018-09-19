#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;
/*
�ڽӱ���Ҫ�ֶ��ӱ�
*/
int V, E; // ����ͱߵ�����
int from, to, cost;
int edge; // ���ڼ�¼��Ӧ�ıߵı��
int head[100]; // ����ƥ��ߵı�źͱ�
int dis[100]; // ����
bool visit[100]; // �Ƿ���ʹ�
#define inf 0x7f7f7f7f

struct node
{
    int to, w; // �¸���;���
    int next; // ����ͬ��������һ����
}e[100];

// ��ʼ�����
void init()
{
    memset(head, -1, sizeof(head));
    edge = 0;
}

// ��ӱߣ�����ͬ������ĵ�һ������ next Ϊ -1 ��������� head ������
void add(int u, int v, int c)
{
    e[edge].to = v;
    e[edge].w = c;
    e[edge].next = head[u];
    head[u] = edge++; // ע�⣬������ edge++ ������Ҫ�ȷ� edge ���� edge++
}

void dijkstra(int s)
{
    // ��ʼ����������
    memset(visit, 0, sizeof(visit));
    // ��ʼ����������
    for (int i =1; i <= V; i++)
    {
        dis[i] = inf;
    }
    // ���¾��룬ֱ�� i Ϊ -1 ���˴� ~i Ϊ��λȡ��
    for (int i = head[s]; ~i; i = e[i].next)
    {
        int v = e[i].to;
        dis[v] = min(dis[v], e[i].w);
    }

    // ��ʼ�������Ϣ
    visit[s] = 1;
    dis[s] = 0;

    // ��ʼ��������������̾���
    for (int i = 0; i < V-1; i++)
    {
        int k = s;
        int mn = inf;
        // ������ǰ����£�û�з��ʹ��ľ�����̵ĵ�
        for (int j = 1; j <= V; j++)
        {
            if (!visit[j] && dis[j] < mn)
            {
                k = j;
                mn = dis[j];
            }
        }

        visit[k] = 1;
        // �����ҵ��ĵ㣬������֮���ڵĵ�ľ���
        for (int i = head[k]; ~i; i = e[i].next)
        {
            int v = e[i].to;
            if (!visit[v] && dis[k] + e[i].w < dis[v])
            {
                dis[v] = dis[k] + e[i].w;
            }
        }
    }
}
int main()
{
    scanf("%d %d", &V, &E);
    init();
    // �����ڽӱ�
    for (int i = 0; i < E; i++)
    {
        scanf("%d %d %d", &from, &to, &cost);
        add(from, to, cost);
        add(to, from, cost);
    }

    // �����㷨
    dijkstra(1);
    // ���
    printf("%d\n", dis[V]);

    return 0;
}
