#include <iostream>
#include <cstdio>
#include <algorithm>
#include <math.h>
#include <string.h>
using namespace std;
/*
������ÿ�ζ���ʹ�� dp[i] �� dp[i-1] ���ʿ������ù��������Ż�
*/
int N;
int a[2001], b[2001];
int dp[2][2001];

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
        int cur = 1 & i;
        int pre = 1 & (i - 1);
        // dp[i-1][0 ... j] ����Сֵ
        int min_cost = dp[pre][0];
        for (int j = 0; j < N; j++)
        {
            min_cost = min(min_cost, dp[pre][j]);
            // ǰһ�����Ž�Ļ����ϣ����� b[j] �ճ� i+1 ���ȵĸ�����
            dp[cur][j] = min_cost + abs(a[i] - b[j]);
        }
    }
    // �� min_element ����λ�ã���� * ���ܷ�����Ӧ��ֵ
    int cur = (N - 1) & 1;
    cout << *min_element(dp[cur], dp[cur] + N) << endl;

    return 0;
}
