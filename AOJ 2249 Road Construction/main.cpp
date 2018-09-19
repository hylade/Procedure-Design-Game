#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;
/*
���������·��⣬��Ѱ�����·�е���ͻ���
*/
int N, M;
// �߽ṹ��
struct edge
{
    int to, distance, cost;
    edge(int _to, int _distance, int _cost):to(_to), distance(_distance), cost(_cost){}
};
vector<edge> G[20001];
typedef pair<int, int> P;
int d[10001];

// dijkstra �㷨
void dijkstra(int s)
{
    priority_queue<P, vector<P>, greater<P> > que;
    memset(d, 0x3f3f3f3f, sizeof(d));
    d[s] = 0;
    que.push(P(0, s));

    while (!que.empty())
    {
        P p = que.top();
        que.pop();
        int v = p.second;
        if (d[v] < p.first) continue;
        for (vector<edge>::size_type i = 0; i < G[v].size(); i++)
        {
            edge e = G[v][i];
            if (d[e.to] > d[v] + e.distance)
            {
                d[e.to] = d[v] + e.distance;
                que.push(P(d[e.to], e.to));
            }
        }
    }
}

int main()
{
    while (scanf("%d %d", &N, &M))
    {
        // Ϊ 0 ʱ����
        if (N == 0 && M == 0) break;
        // ���
        for (int i = 0; i < N; i++)
        {
            G[i].clear();
        }
        // ��ֵ
        for (int i = 0; i < M; i++)
        {
            int f, t, d, c;
            scanf("%d %d %d %d", &f, &t, &d, &c);
            --f, --t;
            G[f].push_back(edge(t, d, c));
            G[t].push_back(edge(f, d, c));
        }
        dijkstra(0);
        int ans = 0;
        for (int i = 1; i < N; i++)
        {
            // ����ÿ���㣬��ʼ�����Ļ���ֵ��ʼ��Ϊ minx ���������Сֵ
            int minx = 0x3f3f3f3f;
            for (vector<edge>::size_type j = 0; j < G[i].size(); j++)
            {
                // ��ʾ�� i �㵽 j �㣬�� j �����С����������߾������ i ����С����
                // ˵����ʱ·��Ϊ���·������ʱȡ������С��·��
                // ����Ŀ��Ϊ��֪�յ������㣬��ֻΪ������·
                if (d[G[i][j].to] + G[i][j].distance == d[i] && G[i][j].cost < minx)
                {
                    minx = G[i][j].cost;
                }
            }
            ans += minx;
        }
        printf("%d", ans);
    }
    return 0;
}
