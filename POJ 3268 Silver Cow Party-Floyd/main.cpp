#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;
/*
ʹ�� floyd �㷨�� O(n^3) ���Ǻܺã��������������ױ�
*/
int N, M, X;
int map[1001][1001];
#define inf 0x3f3f3f3f

// �ҵ�������
void floyd()
{
    for (int k = 0; k < N; k++)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (map[i][j] > map[i][k] + map[k][j])
                    map[i][j] = map[i][k] + map[k][j];
            }
        }
    }
}

int main()
{
    scanf("%d %d %d", &N, &M, &X);
    X--;
    // ��ʼ��
    memset(map, inf, sizeof(map));
    for (int i = 0; i < N; i++)
    {
        map[i][i] = 0;
    }
    // ����
    while (M--)
    {
        int s, e, t;
        scanf("%d %d %d", &s, &e, &t);
        s--, e--;
        map[s][e] = t;
    }
    floyd();
    int ans = 0;
    // �����ֵ
    for (int i = 0; i < N; i++)
    {
        ans = max(ans, map[i][X] + map[X][i]);
    }
    printf("%d", ans);

    return 0;
}
