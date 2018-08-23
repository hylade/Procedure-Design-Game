#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
/*
���·���⣺�Ǹ����������㣬������������Ϊ�����յ��·���У��ߵ�Ȩֵ����С��·��
��Դ���·�����ǹ̶�һ����㣬�������������е�����·����
�յ�̶��������������֮������·���⣬�����߸��Ӷ���ͬ����һ�㵥����Դ���·�������

�Ǵ���� s ���������� i ����̾���Ϊ d[i]
�� d[i] = min(d[j] + �� j �� i �ıߵ�Ȩֵ)

�������ڸ�Ȧ����ô���²��������޵ģ���ô����֮��� d �����������̾���

��ͼ�в����ڴ� s �õ��ĸ�Ȧ����ô���·���ᾭ��ͬһ�����Σ���ôѭ����� V-1 ����
���Ӷ�ӦΪ O(VE)
�������ڴ� s �ɴ�ĸ�Ȧ����ô�� V ��ѭ��Ҳ����� d ��ֵ���ʿɰ��˼�鸺Ȧ
���ձ����������������ѭ�����������ɳڣ�˵�����ڸ�Ȧ

// ���ô�����鸺Ȧ
for (int i = 0; i < V; i++)
{
    for (int j = 0; j < E; j++)
    {
        edge e = es[i];
        if (d[e.to] > d[e.from] + e.cost)
        {
            d[e.to] = d[e.from] + e.cost;
            if (i == V-1) return true;
        }
    }
}
return false;
*/

struct edge {
    int from, to;
    int cost;
    // ���캯�������ڱ�����ֵ���
    edge(int _from, int _to, int _cost)
    {
        from = _from; to = _to; cost = _cost;
    }
};
vector<edge> pedge; // �߼�����
int d[100];
int V, E;
#define inf 0x7f7f7f7f

void shortest_path(int s)
{
    // ��¼�Ƿ���ڸ���
    // ������ָ�ɸ�Ȩ��ɵĻ��������Ͳ��������·��ÿ��ѭ��·��ֵ�����С
    bool bNativeLoop = false;
    // ��ʼ��
    for (int i = 1; i <= V; i++)
    {
        d[i] = inf;
    }
    // ʼ���ʼ��
    d[s] = 0;

    // ѭ��ÿ����
    for (int i = 1; i <= V; i++)
    {
        // ѭ��ÿ����
        // unsigned integer �� signed integer
        for (vector<edge>::size_type j = 0; j < pedge.size(); j++)
        {
            int s = pedge[j].from, e = pedge[j].to, v=pedge[j].cost;
            // ����ʼ����Ե��� s �㣬������ɳ�
            if (d[s] != inf)
            {
                d[e] = min(d[e], d[s] + v);
            }
        }
    }

    // ��鸺��
    for (vector<edge>::size_type i = 0; i < pedge.size(); i++)
    {
        int s = pedge[i].from, e = pedge[i].to, v=pedge[i].cost;
        // ����֮ǰѭ����Ϻ������ɳڣ�˵�����ڸ���
        if (d[e] > d[s] + v)
        {
            bNativeLoop = true;
            break;
        }
    }
    if (bNativeLoop == true) {cout << " Exit Native Loop" << endl;}
    else{
            // ����������·
        for (int i = 1; i <= V; i++)
        {
            cout << d[i] << " ";
        }
        cout << endl;
    }
}
int main()
{
    scanf("%d %d", &V, &E);
    for (int i = 1; i <= E; i++)
    {
        int f, t, c;
        scanf("%d %d %d", &f, &t, &c);
        pedge.push_back(edge(f, t, c));
        pedge.push_back(edge(t, f, c)); // ��������ͼ
    }
    shortest_path(1);
    return 0;
}
