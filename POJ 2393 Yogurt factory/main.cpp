#include <iostream>
#include <cstdio>
#include <stdio.h>
using namespace std;
/*
̰�Ĳ�����ά��ÿ�ܵ���͵�λ�ɱ���ÿ�ܿ���������ʣ�µģ�Ҳ���������µģ����Ǹ��ܵĵ�λ�ɱ�
��������һ�ܵĵ�λ�ɱ����ϴ洢�ѣ�Ҳ�����Ǹ��ܵĵ�λ�ɱ�

ͨ�� min �õ���͵�λ�ɱ�����
*/
int N, S;
int P = 5000;
long long cost;
int main()
{
    scanf("%d %d", &N, &S);

    for (int i = 0; i < N; i++)
    {
        int C, Y;
        scanf("%d %d", &C, &Y);
        P = min(P + S, C);
        cost += P * Y;
    }

    cout << cost << endl;

    return 0;
}
