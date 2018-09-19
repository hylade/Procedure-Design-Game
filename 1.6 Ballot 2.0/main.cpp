#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX_N = 1000;
bool Binary_search(int x, int n, int k[]){ //ͨ����������������ʱ�临�Ӷȣ���O(n^4)��ΪO(n^3logn)
        int l = 0, r = n;
        while (r - l >= 1)
        {
            int i = (r + l) / 2;
            if (k[i] == x)
            {
                return true;
            }
            else if(k[i] < x)
            {
                l = i + 1;
            }
            else
            {
                r = i;
            }
        }
        return false;
    }

int main()
{
    int n, m, k[MAX_N];
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &k[i]);
    }

    sort(k, k+n); // sort��������������������������������ķ�������������Ҳ���Ե��򣬴˲������Բ��
                  // �����������������һ���������������ʼ��ַ���ڶ����ǽ�����ַ

    bool f = false;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int a = 0; a < n; a++)
                {
                    if (Binary_search(m - k[i] - k[j] - k[a], n, k))
                    {
                        f = true;
                    }
                }
        }
    }
    if (f)
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }

    return 0;
}
