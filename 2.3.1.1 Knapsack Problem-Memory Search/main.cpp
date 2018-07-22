#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;
/*
���� 2.3.1.1 Knapsack Problem ����ʵ����ʱĳЩ���������˶�Σ���ʱ���صĽ��Ӧ����ͬ
���ǣ��ڶ��ε��õ�ʱ��ȴ�װ��˷��˼���ʱ�䣬��ʱ��ͨ������һ�ε���ʱ�Ľ����¼����
�Ӷ�ʡ�Եڶ����Ժ���ظ����㣬�Ӷ�����ʱ��

��ʱ������ͬ���Ĳ�����ֻ���ڵ�һ�α�����ʱִ�еݹ鲿�֣��ڶ���֮���ֱ�ӷ���
��������ϲ��� nm �֣���������ֻ��Ҫ���� 2 �εݹ飬����ֻ��Ҫ O(nm) �ĸ��ӶȾ��ܽ������
*/

int n ,m;
int w[100], v[100];
int dp[101][101]; // �����洢����

int rec(int i, int j)
{
    if (dp[i][j] > 0)
    {
        return dp[i][j]; // �� dp ��ֵ > 0 �������ò����Ѿ������������ֱ�ӵ���
    }
    int res;
    if (i == n)
    {
        res  = 0; // ��ʱ�Ѿ�û��ʣ����Ʒ��Ҫ���
    }
    else if (j < w[i])
    {
        res = rec(i + 1, j); // ����ʱ���������޷��������Ʒ
    }
    else
    {
        res = max(rec(i + 1, j), rec(i + 1, j - w[i]) + v[i]); // ����ѡ����ѡ�����г���
    }
    return dp[i][j] = res; // ���������¼�������У�ͬʱ����
}
int main()
{
    memset(dp, -1, sizeof(dp)); // �� -1 ��ʾ��δ���������ʼ���������飻���� memset ��������Ҫ���� string.h ͷ�ļ�
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &w[i], &v[i]);
    }

    printf("%d", rec(0, m));

    return 0;
}


/*
memset �ǰ��� 1 �ֽ�Ϊ��λ���ڴ������䣬 -1 ��ÿһλ������λ���� 1
�����ڸ����Ķ�����λ���ȶԸ����ľ���ֵ�������λ��Ȼ�������� 1��
���� -1 ������ 0 һ��ʹ�� memset ���г�ʼ����ͨ�� memset ���Կ��ٶ�
��ά������г�ʼ����������Ҫע���޷���ʼ��Ϊ 1 ֮�����ֵ

ԭ�����ڣ� memset ��һ���ֽ�һ���ֽ����õģ����� 1 �� int �� 4 ���ֽ�
����ʼ��Ϊ 1 ʱ��ÿ���ֽڶ�����Ϊ 00000001 ����ʱ���� int ��Ϊ 16843009
*/