#include <iostream>
#include <cstdio>
using namespace std;
/*
�������������DFS, Depth-First-Search����һ�������ֶΣ����Ǵ�ĳ��״̬��ʼ�����ϵ�ת��״ֱ̬���޷�ת�ƣ�����˵�ǰһ����״̬
����ת�Ƶ�����״̬����˲����ظ���ֱ���ҵ����ս⣻�������ص㣬���õݹ麯��ʵ�ֽ�Ϊ��

������������Ǵ��ʼ��״̬�������������п��Դﵽ��״̬���ɴ˿��Զ�����״̬���в������о�����״̬
*/

// �Ѿ���ǰ i ��õ��˺� sum_p ��Ȼ����� i ��֮��Ľ��з���
bool dfs(int i, int sum, int n, int sum_p, int a[])
{
    if (n == i) return sum_p == sum; // ����Ѿ���ǰ n �������ˣ��򷵻� sum �Ƿ��� sum_p ���
    if (dfs(i + 1, sum, n, sum_p, a)) return true; // ���� a[i] �����
    if (dfs(i + 1, sum, n, sum_p + a[i], a)) return true; // ���� a[i] �����
    return false; // �����Ƿ���� a[i] ���޷��õ� sum ���򷵻� false
}
int main()
{
    int MAX_N = 20;
    int n, m, a[MAX_N];
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    if (dfs(0, m, 4, 0, a)) printf("YES");
    else printf("NO");


    return 0;
}
