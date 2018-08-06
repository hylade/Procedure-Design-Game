#include <iostream>
#include <cstdio>
#include <stdio.h>
using namespace std;
/*
贪心策略是维持每周的最低单位成本，每周可能用上周剩下的，也可能生产新的，于是该周的单位成本
可能是上一周的单位成本加上存储费，也可能是该周的单位成本

通过 min 得到最低单位成本即可
*/
int N, S;
int P = 5000;
long long cost;
int main()
{
    scanf("%d %d", &N, &S);

    for (int i = 0; i < N; i++)
    {
        int C, Y;
        scanf("%d %d", &C, &Y);
        P = min(P + S, C);
        cost += P * Y;
    }

    cout << cost << endl;

    return 0;
}
