#include <iostream>
#include <cstdio>
using namespace std;
// ����˼·��
// ÿ���жϵ�ǰС���Ƿ��������������϶˵���������Ծͷ�
// �����ȥ���Ҳ࣬һ�������������඼���ܷţ����ж�Ϊ NO
int N;
int a[10];
int flag;
void dfs(int x, int l, int r)
{
    if (x == 10) // �����һ�μ�� x Ӧ���� 10
    {
        return ;
    }

    if (a[x] > l) // �ȶ������м�飬�����򽫸�������������
    {
        dfs(x + 1, a[x], r);
    }
    else if (a[x] > r) // �����������Ҳ�
    {
        dfs(x + 1, l, a[x]);
    }
    else // ���������඼��ͨ��ʱ���� flag ��Ϊ 1
    {
        flag = 1;
        return ;
    }
}
int main()
{
    scanf("%d", &N);
    while (N--)
    {
        flag = 0; // ͨ����� flag �����ж�
        for (int i = 0; i < 10; i++)
        {
            scanf("%d", &a[i]);
        }

        dfs(0, 0, 0);
        if (flag == 0)
        {
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }


    return 0;
}
