#include <iostream>
#include <cstdio>
#include <map>
#include <string.h>
#include <queue>
using namespace std;
/*
�����������з�ʽ����״̬���� '01234567' ����ô���Է������룬ֻҪ�������״̬�ﵽ���н��ʱ����С��������¼����ô����
ͨ�����õ��������з�ʽ��Ӧ�Ĳ���

0 ��ʾ��λ�ã��Կ�λ����Χ�ĸ��Ӳ��ù�����ȷ�ʽ�ƶ��� 0 ������¼����С�����Ľ������

ͨ�� map �����ж�Ӧ string ����С���� int��ֻҪ��������ڣ��ͼ��뵽 map ��
ͬʱ�ڸ����ƶ������ϣ����ڲ��õ��� string �ķ�ʽ����ʾ��ǰ״̬����ô�ƶ������������ҷֱ���ǵ�ǰλ�� +4 -4 +1 -1
����Ҫע����ǣ�λ�� 3 �� 4 ��λ���ϵ���ֵ�������໥�ƶ�
*/
// map �����ṩһ��һ�Ķ�Ӧ��ϵ��ÿ���ؼ���ֻ���� map �г���һ��
map<string, int> dp;
// �ƶ���
int direction[] = {1, -1, 4, -4};

void bfs()
{
    // ����״̬����
    queue<string> que;
    // �ֱ��ʾ��ǰ״̬����һ��״̬
    string str, next;
    // ����״̬����������� char ���ͣ�˫������Ե����ַ�������
    str = "01234567";
    // ��Ϊ��ʼ�ƶ�״̬ push �� que ��
    que.push(str);
    // ��ʼ�ƶ�״̬�Ĳ���Ϊ 0
    dp[str] = 0;


    while (!que.empty())
    {
        str = que.front();
        que.pop();
        int p;
        // ����Ѱ�� 0 ����λ��
        for (int i = 0; i < 8; i++)
        {
            if (str[i] == '0')
            {
                p = i;
                break;
            }
        }

        for (int i = 0; i < 4; i++)
        {
            int n = p + direction[i];
            // ���ƶ���λ�����ڷ�Χ�ڣ�ͬʱ��λ�����Ͻ��������ƶ�������λ�����½��������ƶ�ʱ
            if (n >= 0 && n < 8 && !(p == 3 && i == 0) && !(p == 4 && i == 1))
            {
                // ��������״̬������� 1 ���������ж���ͬ���ʿ��Խ���ǰ״̬�ȸ�ֵ�� next ��Ȼ���ٽ����޸�
                next = str;
                swap(next[p], next[n]);
                // ʹ�� map �е� find ����ʱ�����ص��Ǳ�����Ԫ�ص�λ�ã����������򷵻� map.end()
                if (dp.find(next) == dp.end())
                {
                    // �������� 1
                    dp[next] = dp[str] + 1;
                    // ����һ״̬ push �� que �У����к�������
                    que.push(next);
                }
            }
        }
    }

}


int main()
{
    // �ȵõ�����״̬
    bfs();
    int a[10], N;
    // �������
    scanf("%d", &N);
    // ��һ�����뷽ʽ
    /*
    while (~scanf("%d %d %d %d %d %d %d %d", &a[0], &a[1], &a[2], &a[3], &a[4], &a[5], &a[6], &a[7]));
    {
        string s;
        for(int i = 0; i < 8; i++)
        {
            s += a[i] + '0';
        }
    }
    */
    while (N--)
    {
        string s;
        for (int i = 0; i < 8; i++)
        {
            scanf("%d", &a[i]);
            s += a[i] + '0';
        }
        printf("%d", dp[s]);
    }

    return 0;
}

