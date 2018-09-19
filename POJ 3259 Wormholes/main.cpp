#include <iostream>
#include <cstdio>
#include <vector>
#include <string.h>
using namespace std;
/*
Ҫ�ص���ȥ������Ҫ�ص�����ʱ��Ϊ���������ص�����ʱ���Ǹ���
˵�����ǿ���ͨ����Щ·����ʹ������ʱ��Խ��Խ��
һ��·��Ϊ˫�򣬳涴·��Ϊ���򣬲�Ϊ��ֵ

������Ļ���˼·�������Ƿ���ڸ�����ͨ�� bellman-ford ����
*/
int T;
int N, M, W;
// ������㣬�յ��Ȩֵ
struct Edge{
    int s, e, w;
    Edge(int ss, int ee, int ww): s(ss), e(ee), w(ww){};
};
vector<Edge> edges; // �߼�
int dist[501]; // ��������
#define inf 0x3f3f3f3f

bool bellman(int s)
{
    // ��ʼ��
    memset(dist, inf, sizeof(dist));
    dist[s] = 0;
    bool flag; // ��ʶ
    for (int i = 1; i < N; i++)
    {
        flag = false;
        // ���ݱ߸��¾���
        for (vector<Edge>::size_type j = 0; j < edges.size(); j++)
        {
            if (dist[edges[j].e] > dist[edges[j].s] + edges[j].w)
            {
                dist[edges[j].e] = dist[edges[j].s] + edges[j].w;
                flag = true;
            }
        }
        if (!flag)
        {
            break;
        }
    }
    // �鿴�Ƿ��γɸ�Ȧ
    for (vector<Edge>::size_type j = 0; j < edges.size(); j++)
    {
        if (dist[edges[j].e] > dist[edges[j].s] + edges[j].w)
        {
            return true;
        }
    }
    return false;
}
int main()
{
    scanf("%d", &T); // ����ũ����
    while (T--)
    {
        scanf("%d %d %d", &N, &M, &W);
        // ����·��
        for (int i = 0; i < M; i++)
        {
            int s, e, t;
            scanf("%d %d %d", &s, &e, &t);
            edges.push_back(Edge(s, e, t));
            edges.push_back(Edge(e, s, t));
        }
        // ����涴
        for (int i = 0; i < W; i++)
        {
            int s, e, t;
            scanf("%d %d %d", &s, &e, &t);
            edges.push_back(Edge(s, e, -t));
        }
        if (bellman(1))
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
    return 0;
}
