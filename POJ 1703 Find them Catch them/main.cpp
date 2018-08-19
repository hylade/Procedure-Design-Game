#include <iostream>
#include <cstdio>
using namespace std;
/*
�����鼯�е� i-x ����Ϊ i ���� x ����
ͬһ�����鼯�е�Ԫ��ͬʱ����

������ҪԪ�ظ���Ϊ 2*N ����� i ��ʾ���ڰ��� A ����ô i+N ��ʾ���ڰ��� B
ÿ�����������һﲻ��ͬһ���ɣ���ô�ͺϲ� x-A y-B �� x-B y-A
*/
int p[100001];
int r[100001];
int T, N, M;
int x, y;
char operation; // ��������

void init(int N)
{
    for (int i = 0; i < N; i++)
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
    else if (r[x] < r[y])
        p[x] = y;
    else
    {
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
    // �������
    scanf("%d", &T);
    while (T--)
    {
        // �������������
        scanf("%d %d", &N, &M);
        // ��ʼ��
        init(2 * N);
        for (int i = 0; i < M; i++)
        {
            scanf("%s", &operation);
            scanf("%d %d", &x, &y);
            if (operation == 'A')
            {
                // ������ͬһ�����У��� x-A y-A �� x-B y-B
                if (same(x, y))
                    printf("In the same gang.");
                    // ������ͬһ���ɣ��� x-A y-B �� x-B y-A
                else if (same(x, y + N))
                    printf("In different gangs.");
                    // ����˵����û�й�ϵ
                else
                    printf("Not sure yet.");
            }
            // ��Ϊ D ����ϲ� x-A y-B �� x-B y-A
            else
            {
                unite(x, y + N);
                unite(x + N , y);
            }
        }
    }

    return 0;
}
