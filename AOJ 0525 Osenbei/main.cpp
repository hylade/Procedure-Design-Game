#include <iostream>
#include <cstdio>
#include <algorithm>
#include <bitset>
#include <string.h>
using namespace std;
/*
����һ����ά����٣���Ϊ�����������࣬���Կ��� dfs ��������е����
ͨ�� bitset ����ÿһ�е�����������еķ�ת��ʹ�� bitset �Դ��� flip ��������
����ÿһ�ж�ȷ��ʱ��ͳ�Ƹ��з�ת����Ľϴ�ֵ���Ӷ�ȡ������ֵ
*/
// �����С��С����
int c, r, ans;
// ���� bitset ����
bitset<10000> a[10];

void dfs(int n)
{
    // ��ȷ�������Ƿ�ת�󣬼��ɽ����з�ת����
    if (n == r)
    {
        // ������ȷ��ʱ���з�ת������Ľϴ�ֵ
        int result = 0;
        for (int i = 0; i < c; i++)
        {
            // ����������������ϵĸ���
            int sum = 0;
            for (int j = 0; j < r; j++)
            {
                if (a[j][i] == 1)
                {
                    sum += 1;
                }
            }
            // ȡ�����Ƿ�ת�еĽϴ�ֵ���뵽���������
            result += max(sum, r - sum);
        }
        ans = max(ans, result);
        return ;
    }

    // �����в���תʱ
    dfs(n + 1);
    // ��ת
    a[n].flip();
    // �����з�תʱ
    dfs(n + 1);
}
int main()
{
    while (scanf("%d %d", &r, &c))
    {
        if (c == 0 && r == 0)
        {
            break;
        }
        // �������λ�õ�ֵ
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                bool tmp;
                cin >> tmp;
                a[i][j] = tmp;
            }
        }

        ans = 0;
        dfs(0);
        printf("%d", ans);
    }

    return 0;
}
