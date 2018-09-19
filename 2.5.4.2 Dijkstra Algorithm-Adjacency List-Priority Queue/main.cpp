#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
/*
�����ڽӱ�ʱ������ڽӾ����ܽ�ʡ�����ռ䣬���ǲ������Ż��Ļ���ʱ�临�Ӷ���Ϊ O(n^2)
�ʴ˴�ʹ���ڽӱ� + ���ȶ��еķ�ʽ�����Ż�
*/
#define inf 0x7f7f7f7f
int V, E; // ����ͱߵ�����
int start, final; // �����յ�
int from, to, cost;

// d ��ʾ��̾��룬 u ��ʾ������
struct Headnode{
    int d, u;
    // ��С��������
    bool operator < (const Headnode& rhs) const
    {
        return d > rhs.d;
    }
};
struct edge{
    int to;
    int cost;
    edge(int t, int c): to(t), cost(c){}
};
vector<edge> G[1000]; // ���� edge ���͵� vector ����¼�붥�����ڵĵ��������ɱߵ�Ȩֵ
bool visit[1000];
int d[1000];

void dijkstra()
{
    // ��ʼ��
    fill(d+1, d+V+1, inf);
    d[start] = 0;
    // ���ȶ���
    priority_queue<Headnode> que;
    que.push((Headnode){0, start}); // ���� Headnode ������һ��ʵ�� push �� que ��
    while (!que.empty())
    {
        // ȡ��������̵�
        Headnode x = que.top();
        que.pop();
        int u = x.u;
        // ���ݱ�Ų鿴�Ƿ��Ѿ����ʹ�
        if (visit[u]) continue;
        visit[u] = 1;
        for (vector<edge>::size_type i = 0; i < G[u].size(); i++)
        {
            // ������ͨ�ı߸��¾���
            edge e = G[u][i];
            if (d[e.to] > d[u] + e.cost)
            {
                d[e.to] = d[u] + e.cost;
                que.push((Headnode){d[e.to], e.to});
            }
        }
    }

}

int main()
{
    scanf("%d %d", &V, &E);
    scanf("%d %d", &start, &final);
    // ¼����Ȩͼ
    for (int i = 1; i <= E; i++)
    {
        scanf("%d %d %d", &from, &to, &cost);
        G[from].push_back(edge(to, cost));
        G[to].push_back(edge(from, cost));
    }
    // dijkstra �㷨
    dijkstra();
    // ������
    if (d[final] == inf)
    {
        printf("-1");
    }
    else
    {
        printf("%d", d[final]);
    }
    return 0;
}
