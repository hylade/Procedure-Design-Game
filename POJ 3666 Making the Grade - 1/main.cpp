#include <iostream>
#include <cstdio>
#include <algorithm>
#include <math.h>
#include <string.h>
using namespace std;
/*
���� dp[i][j] ��ʾǰ i+1 ������ɵ��������һ������ b[j] ����ʱ����С�ɱ�
dp[i][j] = min(dp[i-1][k]) + |a[i] - b[j]| (k = 0, ..., j)
��ʾǰ i+1 ��������С�ɱ�Ӧ�õ���ǰ i ���������һ����ȫ������һ�����Сֵ�����Ҽ��ϵ� i+1 �����滻Ϊ b[j] �ĳɱ�

�ٸ�����˵��dp״̬���̵�ת�ƣ�
��ԭ����ΪA = 1 3 2������������ΪB = 1 2 3������������ΪC = 3 2 1
dp[1][0] = min{dp[0][0], abs(3 - 1)} = 2
dp[2][1] = min{dp[1][0], dp[1][1]} + abs(2 �C 2)
�����ڱ���dp[1][1]��Ӧ�����Ž�1 2������£���B[1]=2��ӵ�β���õ� 1 2 2��������
dp[2][2] = min{dp[1][0], dp[1][1]��dp[1][2]} + abs(2 �C 3)
�����ڱ���dp[1][2]��Ӧ�����Ž�1 3������£���B[2]=3��ӵ�β���õ� 1 3 3��������
*/
int N;
int a[2001], b[2001];
int dp[2001][2001];

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &a[i]);
    }
    // memcpy �������������� 1 ��������Ŀ���ڴ棬 �� 2 ����������Ը�ڴ棬�� 3 ������������С
    memcpy(b, a, sizeof(a));
    // ����
    sort(b, b + N);
    // ���� 1 �����ĸı�ɱ���Ϊ�� 1 ���������������ֵĲ�
    for (int j = 0; j < N; j++)
    {
        dp[0][j] = abs(a[0] - b[j]);
    }

    for (int i = 1; i < N; i++)
    {
        // dp[i-1][0 ... j] ����Сֵ
        int min_cost = dp[i - 1][0];
        for (int j = 0; j < N; j++)
        {
            min_cost = min(min_cost, dp[i - 1][j]);
            // ǰһ�����Ž�Ļ����ϣ����� b[j] �ճ� i+1 ���ȵĸ�����
            dp[i][j] = min_cost + abs(a[i] - b[j]);
        }
    }
    // �� min_element ����λ�ã���� * ���ܷ�����Ӧ��ֵ
    cout << *min_element(dp[N - 1], dp[N - 1] + N) << endl;

    return 0;
}
