#include <iostream>
#include <cstdio>
using namespace std;
int path[100][100];
int map[100][100];
int V, E; // ����ͱߵ�����
#define inf 99999999 // ��α�ʾ�����һ�㶨��Ϊ 99999999 ����Ϊ������ʹ������������ӣ�
                     // �Ӳ����� int ����
int from, to, cost;

void floyd(int V)
{
    // ����ѭ���������·��
    for (int k = 1; k <= V; k++)
    {
        for (int i = 1; i <= V; i++)
        {
            for (int j = 1; j <= V; j++)
            {
                if (map[i][j] > map[i][k] + map[k][j])
                {
                    map[i][j] = map[i][k] + map[k][j];
                    // path[i][j] = k ��ʾ���·�� i-j ��ֱ��ǰ��Ϊ k ���� i-k-j
                    path[i][j] = k;
                }
            }
        }
    }
}

 void getPath(int i ,int j){
    if(i == j) return;
    if(path[i][j] == 0) printf("%d ", j);
    else{
        getPath(i, path[i][j]);
        getPath(path[i][j], j);
    }
}


int main()
{
    scanf("%d %d", &V, &E);
    for (int i = 1; i <= V; i++)
    {
        // ��ʼ��
        for (int j = 1; j <= V; j++)
        {
            if (i == j)
            {
                map[i][j] = 0;
            }
            else
                map[i][j] = inf;
        }
    }

    // ������Ϣ
    for (int i = 1; i <= E; i++)
    {
        scanf("%d %d %d", &from, &to, &cost);
        map[from][to] = cost;
        map[to][from] = cost;
    }
    floyd(V);

    // ���
    for(int i = 1; i <= V; i++)
    {
        for (int j = 1; j <= V; j++)
        {
            printf("%d ", map[i][j]);
        }
        cout << endl;
    }

    getPath(1, V);

    return 0;
}
