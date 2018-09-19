#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

/*
ʹ�� C++ ��׼���е� next_permutation �������� n ��Ԫ�صĹ� n�� �ֲ�ͬ���������ɳ���
*/

/*
����״̬��ö�ٴ���������£�
bool used[MAX_N]
int perm[MAX_N]
// ����{0, 1, 2, 3,..., n-1}�� n�� ������

void permutation1(int pos, int n)
{
    if (pos == n)
    {
        // �ڴ˴���д�� perm �Ĳ���
    }
    // return ;
}

// ��� perm �ĵ� pos ��λ�ã�����ʹ�� 0 ~ n-1 ���ĸ�����ѭ��
for (int i = 0; i < n ; i++)
{
    if (!used[i])
    {
        perm[pos] = i;
        // i �Ѿ���ʹ�ã�����Ҫ�������Ϊ true
        used[i] = true;
        permutation1(pos + 1, n);
        // ���غ󽫱�Ǹ�ԭ
        used[i] = false;
    }
    return ;
}
*/

/*
ʾ����
Description��С��ʮ�ִ���������ʮ���ó����м��㡣
�����С��һ������5���������̸���1-5���ֵ����ȫ���У��������Ϊ����������5��������ѡ������������������ȫ���У�
��ô��ʹ��ˣ���ͬ���ĺ��ó���������Ҫ��дһ����������֤�ó����е�С�����׶Բ��ԡ�

Input��
��һ����������N��1<N<10����ʾ������������ݣ�
ÿ��������ݵ�һ���������� n m (1<n<9,0<m<=n)

Output��
��1-n��ѡȡm���ַ�����ȫ���У����ֵ���ȫ�����,ÿ������ռһ�У�ÿ�����ݼ䲻��ֽ硣������

Sample��
Input��
2
3 1
4 2

Output��
1
2
3
12
13
14
21
23
24
31
32
34
41
42
43
*/

bool used[100];
int perm[100];
int a, n, m;

void permutation(int pos, int r)
{
    if (pos == r)
    {
        for (int i = 0; i < pos; i++)
        {
            printf("%d", perm[i]);
        }
        printf("\n");
        return ;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!used[i])
        {
            perm[pos] = i;
            used[i] = true;
            permutation(pos + 1, r);
            used[i] = false;
        }
    }
}

int main()
{
    scanf("%d", &a);
    while (a--) // ����
    {
        scanf("%d %d", &n, &m); // ���� n �� m
        permutation(0, m);
    }


    return 0;
}
