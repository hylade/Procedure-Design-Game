#include <iostream>
#include <cstdio>
#include <algorithm>
#include <math.h>
#include <string.h>
using namespace std;
/*
���汾 -1 �Ͱ汾 -2 ��û�п����½����е��������֪��ʲôԭ��-_-��
ͬʱ��Ŀ˵���ֿ��ܽϴ󣬹�Ӧ��ʹ�� long long ����
*/
int N;
long long ans1, ans2;
int a[2001], b[2001];
long long dp1[2001];
long long dp2[2001];

long long Search_Increase(const int);
long long Search_Decrease(const int);

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &a[i]);
    }
    // memcpy �������������� 1 ��������Ŀ���ڴ棬 �� 2 ����������Ը�ڴ棬�� 3 ������������С
    memcpy(b, a, sizeof(a));
    // ���򣬴�С����
    sort(b, b + N);
    ans1 = Search_Increase(N);

    // �Ӵ�С
    sort(b, b + N, greater<int>());
    ans2 = Search_Decrease(N);
    // ����������Сֵ���жԱ�
    cout << min(ans1, ans2) << endl;

    return 0;
}

long long Search_Increase(const int N)
{
    // ʹ�� dp1 �� dp2 ����ʾǰһ�����Ⱥ͵�ǰ���ȣ�����ʼ��
    memset(dp1, 0, sizeof(dp1));
    memset(dp2, 0, sizeof(dp2));

    long long min_tmp, *dp_tmp = NULL, *p1 = dp1, *p2 = dp2, ans;
    for (int i = 0; i < N; i++)
    {
        // �� min_tmp �ҵ�ǰһ��������С�ĳɱ�
        min_tmp = p1[0];
        for (int j = 0; j < N; j++)
        {
            min_tmp = min(min_tmp, p1[j]);
            // ���ϵ�ǰ�ı�ɱ�
            p2[j] = abs(a[i] - b[j]) + min_tmp;
        }
        // �ı�ָ��ʹ����ָ��ǰһ�����Ⱥ͵�ǰ���ȣ����ƹ�������
        dp_tmp = p1; p1 = p2; p2 = dp_tmp;
    }
    // Ѱ����Сֵ
    ans = p1[0];
    for (int i = 1; i < N; i++)
    {
        ans = min(ans, p1[i]);
    }
    return ans;
}

long long Search_Decrease(const int N)
{
    memset(dp1, 0, sizeof(dp1));
    memset(dp2, 0, sizeof(dp2));

    long long min_tmp, *dp_tmp = NULL, *p1 = dp1, *p2 = dp2, ans;
    for (int i = 0; i < N; i++)
    {
        min_tmp = p1[0];
        for (int j = 0; j < N; j++)
        {
            min_tmp = min(min_tmp, p1[j]);
            p2[j] = abs(a[i] - b[j]) + min_tmp;
        }
        dp_tmp = p1; p1 = p2; p2 = dp_tmp;
    }
    ans = p1[0];
    for (int i = 1; i < N; i++)
    {
        ans = min(ans, p1[i]);
    }
    return ans;
}
