#include <iostream>
#include <cstdio>
using namespace std;
/*
����˼·��
�ò��鼯��������Ի������ͨ���
ÿ���޺õ�ú󣬽�������ͨ�ŵĵ��ԣ������������Ѿ��޺ã�������ͨ
*/
int p[1010];
int r[1010];
int N, d;
char operation; // ���� O ���� S
int x, y;
bool status[1010]; // �Ƿ��޺�
pair<int, int> computer[1010];
int square(int x)
{
    return x * x; // ����ƽ��
}

void init(int n)
{
    for (int i = 0; i < n; i++)
    {
        p[i] = i;
        r[i] = 0;
    }
}

int find(int x)
{
    if (p[x] == x) return x;
    else{
        return p[x] = find(p[x]);
    }
}

void unite(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x == y)
    {
        return;
    }

    if (r[x] < r[y])
    {
        p[x] = y;
    }
    else{
        p[y] = x;
        if (r[x] == r[y])
        {
            r[x]++;
        }
    }
}

bool same(int x, int y)
{
    return find(x) == find(y);
}


int main()
{
    scanf("%d %d", &N, &d);
    for(int i = 0; i < N; i++)
    {
        scanf("%d %d", &computer[i].first, &computer[i].second);
    }

    init(N);
    while (scanf("%s", &operation))
    {
        if (operation == 'O')
        {
            scanf("%d", &x);
            x -= 1; // ��ֹ���� -1
            status[x] = true;
            for (int i = 0; i < N; i++)
            {
                if (x == i) // ��Ϊͬһ�㣬��������һ��
                {
                    continue;
                }
                else{
                        // ���޺��Ҿ�������Ҫ��������벢�鼯
                    if (status[i] && square(computer[x].first-computer[i].first) + square(computer[x].second - computer[i].second) <= square(d))
                    {
                        unite(x, i);
                    }
                }
            }
        }
        else
        {
            // ��Ϊ S
            scanf("%d %d", &x, &y);
            x -= 1;
            y -= 1;
            // �Ƿ���ͨ�����Ƿ���ͬһ������
            if (same(x, y))
            {
                printf("SUCCESS");
            }
            else
            {
                printf("FAIL");
            }
        }
    }

    return 0;
}
