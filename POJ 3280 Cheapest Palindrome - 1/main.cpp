#include <iostream>
#include <cstdio>
#include <math.h>
#include <algorithm>
#include <string.h>
#include <map>
using namespace std;
/*
�� dp[i][j] ��ʾ���� (i, j) �䵽�����ַ�����Ҫ�ķ���
�� s[i] = s[j]
�� dp[i][j] = dp[i + 1][j - 1]
����������־��������� i j ����λ�õĳ�ͻ
1. �������� s[j] �ַ�
2. ɾ�� s[j]
3. ���Ҳ���� s[i] �ַ�
4. ɾ�� s[i]
�ۺϵõ���
1. �� dp[i+1][j] ��Ϊ���Ĵ��������軨�Ѷ�ӦΪ min(dp[i+1][j]+add[str[i]], dp[i+1][j]+del[str[i]])
2. �� dp[i][j-1]��Ϊ���Ĵ��������軨�Ѷ�ӦΪ min(dp[i][j-1]+add[str[j]], dp[i][j-1]+del[str[j]])
// ȡ���������������Сֵ����
3. �� str[i]==str[j] ���� dp[i+1][j-1] ��Ϊ���Ĵ��������軨�Ѷ�ӦΪ dp[i+1][j-1]
*/
int N, M;
// ����ÿ���ַ�����Ϣ
struct Cow{
    int add;
    int del;
};
// dp ����
int dp[2000][2000];
// ���� map �ܽ�Ψһ�� char ��Ӧ�� Cow ��
map <char, Cow> cow;
string s;
#define inf 0x7f7f7f7f;

int main()
{
    while (scanf("%d %d", &N, &M) != EOF)
    {
        // �����ַ���
        cin >> s;

        for (int i = 0; i < N; i++)
        {
            char c;
            int add, del;
            // ��������ַ���Ӻ�ɾ���ķ���
            cin >> c >> add >> del;
            // ��ֵ�������ַ���
            cow[c].add = add;
            cow[c].del = del;
        }

        for (int i = 0; i < M; i++)
        {
            for (int j = i + 1; j < M; j++)
            {
                // ��ͷβ�ַ���ͬʱ���൱�ڽ����߶�ɾ������ʣ�ಿ�ַ���
                if (s[i] == s[j])
                    dp[i][j] = dp[i + 1][j - 1];
                int mincost = inf;
                // ȡ�׶˻�β��ɾ���ַ�����Сֵ
                mincost = min(mincost, dp[i][j - 1] + cow[s[j]].del);
                mincost = min(mincost, dp[i + 1][j] + cow[s[i]].del);
                // ȡ�׶���� j λ���ַ���β����� i λ���ַ��Ľ�Сֵ
                int temp = min(dp[i][j - 1] + cow[s[j]].add, dp[i + 1][j] + cow[s[i]].add);
                // ȡ���ַ����Ľ�Сֵ
                dp[i][j] = min(mincost, temp);
            }
        }

        printf("%d", dp[0][M - 1]);
    }

    return 0;
}
