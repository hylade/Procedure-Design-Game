#include <iostream>
#include <cstdio>
using namespace std;
/*
由于需要 n-1 个数，表示当前第 i 个数的父节点，便在输入的时候直接将其初始化为父节点
本题是并查集和树的节后，在输入的时候，就可以根据父节点的关系建立并查集， 1 的父亲是 1
若被 mark 之后，便将其自身设为父节点
*/
int p[100010];
char s[5];
int x;
int N, Q;

int find(int x)
{
    if (p[x] == x) return x;
    else
    {
        printf("1 %d\n", p[x]);
        return p[x] = find(p[x]);
    }
}
int main()
{
    while (scanf("%d %d", &N, &Q))
    {
        if (N == 0 && Q == 0)
        {
            break;
        }
        for (int i = 2; i <= N; i++)
        {
            scanf("%d", &p[i]);
        }
        p[1] = 1;
        long long sum = 0;
        for (int i = 0; i < Q; i++)
        {
            scanf("%s %d", s, &x);
            // 搜索父节点
            if (s[0] == 'Q')
            {
                sum += find(x);
            }
            //  分离 x 节点（将 x 设为父节点）
            else if (s[0] == 'M')
            {
                p[x] = x;
            }
        }
        cout << sum << endl;
    }


    return 0;
}
