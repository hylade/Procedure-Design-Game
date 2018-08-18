#include <iostream>
#include <cstdio>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <queue>
using namespace std;
/*
������ 2.2 ���е� Fence Repair ��Ŀ��ͬ���� 2.2 ����ʹ�õĶ���ѭ�������Ӷ���Ҫ O(n^2)
����ʹ�����ȶ��У�ÿ�δӶ�����ȡ����̵����飬���ҽ�����Ϊ����峤��֮�͵İ���뵽�����м���
���ʱ�临�Ӷ�ֻ�� O(nlogn)
*/
int N, ans, L[20001];
// ����һ����С������������ȶ��� que
priority_queue<int, vector<int>, greater<int> > que;

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &L[i]);
    }
    for (int i = 0; i < N; i++)
    {
        que.push(L[i]);
    }

    // ѭ����ֻ��һ��ľ��Ϊֹ�����ľ�������պϳɵ�ľ��
    while (que.size() > 1)
    {
        // ȡ�����ľ�����̵�ľ��
        int first = que.top();
        que.pop();
        int second = que.top();
        que.pop();
        // ��ӣ��� push �� que ���棬���� ans ���ۼ�
        int t = first + second;
        ans += t;
        que.push(t);
    }
    printf("%d", ans);
    return 0;
}
