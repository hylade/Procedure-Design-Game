#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define inf 0x7f7f7f7f
int V, E;
int prev[100]; // ���·�ϵ�ǰ����
struct Edge
{
    int u, v;
    int cost;
};
Edge edge[100];
int d[100];

bool Bellman_Ford(int s)
{
    // ��ʼ��
    for (int i = 1; i <= V; i++)
    {
        d[i] = inf;
    }
    d[s] = 0;
    // ���ÿ����������ӵı�
    for (int i = 0; i <= V-1; i++)
    {
        for (int j = 1; j <= E; j++)
        {
            if (d[edge[j].v] > d[edge[j].u] + edge[j].cost)
            {
                d[edge[j].v] = d[edge[j].u] + edge[j].cost;
                prev[edge[j].v] = edge[j].u; // ��¼ǰ����
            }
        }
    }
    // �������
    bool flag = 1;
    for (int i = 1; i <= E; i++)
    {
        if (d[edge[i].v] > d[edge[i].u] + edge[i].cost)
        {
            flag = 0;
            break;
        }
    }
    return flag;
}

// ·���ؼ�����
vector<int> get_path(int t)
{
    vector<int> path;
    // ����·��
    for(; t != -1; t = prev[t])
    {
        path.push_back(t);
    }
    // ��������
    reverse(path.begin(), path.end());
    return path;
}

int main()
{
    scanf("%d %d", &V, &E);
    // ���������
    for (int i = 1; i <= E; i++)
    {
        scanf("%d %d %d", &edge[i].u, &edge[i].v, &edge[i].cost);
    }
    fill(prev+1, prev+V+1, -1);
    if (Bellman_Ford(1))
    {
        for (int i = 1; i <= V; i++)
        {
            printf("%d\n", d[i]);
        }
    }
    else
    {
        printf("Negative circle\n");
    }

    vector<int> path;
    path = get_path(V);
    // ���·��
    for (vector<int>::size_type i = 0; i < path.size(); i++)
    {
        cout << path[i] << " ";

    }
    cout << endl;

    return 0;
}
