#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

vector<int> G[100];
int V, E;
// ������ɫ��ʼ��Ϊ 0 ����ɫ������ 1 �� -1
int color[100];

bool dfs(int v, int s)
{
    // ������ȾɫΪ s
    color[v] = s;
    // G[i][j] ���� i �������ڵ�
    // ����һ��ʹ�÷��� for (int i = 0 ...) ����� warning
    // ����Ŀ���Ƿ�ֹһ�����ķ����͵�����ת��Ϊ�޷�����ʱ�������һ������������Ҫ�ĺܴ������
    // ͬʱ signed �� unsigned ���ݷ�ΧҲ��ͬ
    // ��������������£��� i ��Ϊ vector �����Ͷ��������
    for (vector<int>::size_type i = 0; i < G[v].size(); i++)
    {
        // �����ǰ������ڵ�ͬɫ�ͷ��� false
        if (color[G[v][i]] == s) return false;
        // ����ǰ����ڵ�û��Ⱦɫ��ȾΪ -s �����Ըõ����ͬ��������
        if (color[G[v][i]] == 0 && !dfs(G[v][i], -s)) return false;
    }
    // ����ǰ����ڵ㶼Ⱦ��ɫ���Ҷ�Ϊ -s ���򷵻� true
    return true;
}

void solve()
{
    for (int i = 0; i < V; i++)
    {
        // ���ڸ����ڵ���û��Ⱦɫ���㿪ʼ dfs ����
        if (color[i] == 0)
        {
            if (!dfs(i, 1))
            {
                printf("NO\n");
                return ;
            }
        }
    }
    printf("YES\n");
}
// �������ӱ�����ͼ����ڵ�ͱ�
int main()
{
    scanf("%d %d", &V, &E);
    for (int i = 0; i < E; i++)
    {
        int s, t;
        scanf("%d %d", &s, &t);
        G[s].push_back(t);
        G[t].push_back(s);
    }
    solve();

    return 0;
}
