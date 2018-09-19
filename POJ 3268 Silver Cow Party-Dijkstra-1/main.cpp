#include <iostream>
#include <cstdio>
#include <vector>
#include <string.h>
#include <queue>
using namespace std;
/*
�޸Ĵ�ͳ dijkstra �㷨��ʹ��֧�������������·�㷨
*/
int N, M, X;
// �Ӷ��� from ָ�򶥵� to ��ȨֵΪ cost �ı�
struct Edge{
    int to, cost;
    Edge(int _to, int _cost): to(_to), cost(_cost){}
};
// ͼ
vector<Edge> G[1001];
// ����
int d[1001][1001];
// first Ϊ���·���� second Ϊ������
typedef pair<int, int> P;
#define inf 0x3f3f3f3f

// ���Ӷ��� s �����е����̾���
void dijkstra(int s)
{
    priority_queue<P, vector<P>, greater<P> > que;
    memset(d[s], inf, 1001 * sizeof(int));
    d[s][s] = 0;
    que.push(P(0, s));

    while (!que.empty())
    {
        P p = que.top();
        que.pop();
        int v = p.second;
        if (d[s][v] < p.first) continue;
        for (vector<Edge>::size_type i = 0; i < G[v].size(); i++)
        {
            Edge e = G[v][i];
            if (d[s][e.to] > d[s][v] + e.cost)
            {
                d[s][e.to] = d[s][v] + e.cost;
                que.push(P(d[s][e.to], e.to));
            }
        }
    }
}

int main()
{
    scanf("%d %d %d", &N, &M, &X);
    X--;
    while (M--)
    {
        int s, e, t;
        // ����
        scanf("%d %d %d", &s, &e, &t);
        s--, e--;
        G[s].push_back(Edge(e, t));
    }
    // ���Ӹ��㵽��������ľ���
    for (int i = 0; i < N; i++)
    {
        dijkstra(i);
    }
    int ans = 0;
    // �ҵ����ֵ
    for (int i = 0 ; i < N; i++)
    {
        if (i == X) continue;
        ans = max(ans, d[i][X] + d[X][i]);
    }
    printf("%d", ans);

    return 0;
}
