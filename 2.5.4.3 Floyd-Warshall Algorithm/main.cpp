#include <iostream>
#include <cstdio>
using namespace std;
/*
�����������飬��������֮�����̾��룬��Ҫ������������㣬���߸���Ķ���
����ֻ�ܾ��� 1 �Ŷ���ʱ���ж� e[i][j] �Ƿ�� e[i][1] + e[1][j] ��
e[i][j] ��ʾ�� i �Ŷ��㵽 j �Ŷ���֮���·�̣� e[i][1] + e[1][j] ��ʾ
i �Ŷ����ȵ� 1 �Ŷ��㣬�ٴ� 1 �Ŷ��㵽 j �Ŷ����·��֮��

���ԣ�����˼����ǣ��ʼֻ������ 1 �Ŷ��������ת��������ֻ������ 1 �� 2
���������ת...������ 1-n ���ж�����ת������������֮������·��

һ�仰�������ǣ��� i �Ŷ��㵽 j �Ŷ���ֻ����ǰ k �Ŷ�������·��

���㷨ʵ�ּ򵥣�����ʱ�临�ӶȽϴ�
*/
int map[100][100];
int V, E; // ����ͱߵ�����
#define inf 99999999 // ��α�ʾ�����һ�㶨��Ϊ 99999999 ����Ϊ������ʹ������������ӣ�
                     // �Ӳ����� int ����
int from, to, cost;

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
                }
            }
        }
    }

    // ���
    for(int i = 1; i <= V; i++)
    {
        for (int j = 1; j <= V; j++)
        {
            printf("%d ", map[i][j]);
        }
        cout << endl;
    }

    return 0;
}
