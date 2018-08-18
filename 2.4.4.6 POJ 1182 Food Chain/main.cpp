#include <iostream>
#include <cstdio>
using namespace std;
/*
���ڶ���ÿֻ���ֻ�п������� A B C �е�һ�࣬��ô����ÿֻ��������� i-A i-B i-C 3 ��Ԫ��
ʹ���� 3 * N ��Ԫ�ؽ������鼯�����ò��鼯ά��������Ϣ
1. i-x ��ʾ i ���� x ����
2. ���鼯��ÿһ�����ʾ��������Ԫ�ش���������ͬʱ�����򲻷���

�������²������ɣ�
1.x �� y ͬ�ࡪ�����ϲ� x-A �� y-A �� x-B �� y-B�� x-C �� y-C
2.x �� y ���������� �ϲ� x-A �� y-B �� x-B �� y-C �� x-C �� y-A
*/
int p[50001];
int rank[50001];
int N, K;
int T[50001], X[50001], Y[50001];

void init(int n) // ��ʼ�� n ��Ԫ��
{
    for (int i = 0; i < n; i++)
    {
        p[i] = i;
        rank[i] = 0;
    }
}
// �������ĸ�
int find(int x)
{
    if (p[x] == x) return x;
    return p[x] = find(p[x]);
}
// �ϲ� x �� y ��������
void unite(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x == y)
        return;
    else if (rank[x] < rank[y])
        p[x] = y;
    else
    {
        p[y] = x;
        if (rank[x] == rank[y])
            rank[x]++;
    }
}
// �ж� x �� y �Ƿ�����ͬһ����
bool same(int x, int y)
{
    return find(x) == find(y);
}

int main()
{
    scanf("%d %d", &N, &K);
    for (int i = 0; i < K; i++)
    {
        scanf("%d %d %d", &T[i], &X[i], &Y[i]);
    }
    // �� x x+N x+2N �ֱ��ʾ x-A x-B x-C
    init(3 * N);
    int ans = 0;
    for (int i = 0; i < K; i++)
    {
        int t = T[i];
        // ��ֹ���ޣ��������ֵ -1
        int x = X[i] - 1, y = Y[i] - 1;
        // ���ڲ���ȷ�ı�ţ�ֱ�� ans++
        if (x < 0 || x >= N || y < 0 || y >= N)
        {
            ans++;
            continue;
        }
        // ���� x �� y ����ͬһ�����Ϣ
        if (t == 1)
        {
            // ���Ѵ��ڣ����� x �� y ���� x-A y-B ���� x-A y-C �ķ�ʽ����ʱ������
            if (same(x, y + N) || same(x, y + 2 * N))
            {
                ans++;
                continue;
            }
            // ���� x-A y-A �� x-B y-B �� x-C y-C �ķ�ʽ����
            else
            {
                unite(x, y);
                unite(x + N, y + N);
                unite(x + 2 * N, y + 2 * N);
            }
        }
        // ���� x �� y ����Ϣ
        else
        {
            // ��������ϢΪ x-A y-A ���� x-A y-C ���ͱ���
            if (same(x, y) || same(x, y + 2 * N))
            {
                ans++;
                continue;
            }
            // �������ڣ��Ͱ��� x-A y-B �� x-B y-C �� x-C y-A ���д���
            else
            {
                unite(x, y + N);
                unite(x + N, y + 2 * N);
                unite(x + 2 * N, y);
            }
        }
    }
    printf("%d", ans);

    return 0;
}
