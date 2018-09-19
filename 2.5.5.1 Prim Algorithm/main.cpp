#include <iostream>
using namespace std;
int cost[MAX_N][MAX_N];
int mincost[MAX_N];
bool used[MAX_N];
int V;
#define INF 0x3f3f3f3f
/*
����һ������ͼ���������ĳ����ͼ�������������㶼������ͨ������һ��������ô�����������������Spanning Tree��
���������Ȩֵ������ʹ��Ȩֵ����С��������������С��������MST, Minimum Spanning Tree��

Prim �㷨
��ѡȡһ������ T ��Ȼ��̰�ĵ�ѡȡ T ����������֮����������СȨֵ�ıߣ����ҽ�����ӵ� T ��
���Ͻ���������������ɵľ�����С������

֤����
��֤�������� prim ���ɵĲ�����С������
1).�� prim ���ɵ���Ϊ G0
2).������� Gmin ʹ�� cost(Gmin) < cost(G0) ���� Gmin �д��� <u,v> ������G0
3).�� <u,v> ���� G0 �пɵ�һ�������� <u,v> ���Ǹû������(������Ϊ <u,v> �� Gmin)
4).���� prim ÿ��������̱�ì��
5).�ʼ��費�����������֤.

��������СȨֵ�ı�
�� X �� ���� V ���ӵıߵ���СȨֵ��Ϊ mincost[v]
���� X ����Ӷ��� u ʱ��ֻ��Ҫ�鿴�� u �����ı߾Ϳ����ˣ�����ÿ���ߣ�����
mincost[v] = min(mincost[v], ��(u, v) ��Ȩֵ) ����

���ÿ�α���δ������ X �еĵ��� mincost[v] ����Ҫ O(V^2) ʱ�临�Ӷ�
�������ö���ά������Ҫ O(ElogV) ʱ�临�Ӷȼ���
*/
int prim()
{
    // ��ʼ��
    for (int i = 0; i < V; i++)
    {
        mincost[i] = INF;
        used[i] = false;
    }

    mincost[0];
    int res = 0;

    while (true)
    {
        int v = -1;
        // �ҵ���С��
        for (int u = 0; u < V; u++)
        {
            if (!used[u] && (v == -1 || mincost[u] < mincost[v]))
                v = u;
        }
        // ������û�з��ʹ��Ķ������˳�
        if (v == -1) break;
        used[v] = true;
        // �������
        res += mincost[v];

        // �����ܷ��ʵı�
        for (int u = 0; u < V; u++)
        {
            mincost[u] = min(mincost[u], cost[v][u]);
        }
    }
    return res;
}
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
