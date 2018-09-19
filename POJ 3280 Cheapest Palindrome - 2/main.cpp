#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
 /*
 ��ʵ�����׶�����ĳ����ĸ��β�����ĳ����ĸЧ������ͬ�ģ�ȡ�仨����Сֵ����
 ��Ϊ�����β��ɾ��ĸ x ������ʹһ���ַ��� s ��ɻ��ĵĻ�����ôӦ��ѡȡ���ѽ�С��
 */
int n,m,i,j,x,y;
int dp[2005][2005],cost[28];
char str[2005],c[2];

int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        // �� dp �����ʼ��Ϊ 0
        memset(dp, 0, sizeof(dp));
        // �����ַ���
        scanf("%s", str);
        for(i = 0; i < n; i++)
        {
            // ��������ַ����仰��
            scanf("%s%d%d",c,&x,&y);
            // ���ϵ͵Ļ��Ѵ��� cost �����У���һһ��Ӧ
            cost[c[0] - 'a'] = min(x, y);
        }
        for(j = 1; j < m; j++)
        {
            for(i = j - 1; i >= 0; i--)//���ÿ������ļ�ֵ��������С�ļ�ֵ
            {
                dp[i][j] = min(dp[i + 1][j] + cost[str[i]-'a'], dp[i][j - 1] + cost[str[j] - 'a']);
                if(str[i] == str[j])
                    dp[i][j] = min(dp[i][j], dp[i+1][j-1]);
            }
        }
        printf("%d\n", dp[0][m - 1]);
    }

    return 0;
}
