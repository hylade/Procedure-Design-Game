#include <iostream>
#include <algorithm>
#include <cstdio>
#include <math.h>
#include <string.h>
#include <queue>
using namespace std;
/*
ʹ����������
������Ҫȷ��ʹ��̰�Ĳ��ԣ������� minSPF �������£�������Ҫ�� SPF �ķ�ɹ˪���� maxSPF ��С����ţ����
��Ϊ maxSPF �����ţ�и����ѡ��ռ䣬��һ����С����ά�� maxSPF ����Сֵ����
*/
int C, L;
typedef pair <int, int> p;
p cow[2501], bot[2501];
// ���ȶ��У�ʹ��СԪ�����ȳ���
// �������ȶ��У���������������������һ������������ type ���ڶ����Ǳ������ݵ����� Container
// Container ����Ϊ vector ���� deque �ȣ�������ʹ�� list ��Ĭ���� vector
// �����������ǱȽϲ�����������������ȱʡ�Ļ�����ʾ�󶥶�
priority_queue<int, vector<int>, greater<int> > q;

int main()
{
    scanf("%d %d", &C, &L);
    // ����ţ����Ϣ�� minSPF �� maxSPF
    for (int i = 0; i < C; i++)
    {
        scanf("%d %d", &cow[i].first, &cow[i].second);
    }
    // �����ɹ˪����Ϣ�� SPF ������
    for (int i = 0; i < L; i++)
    {
        scanf("%d %d", &bot[i].first, &bot[i].second);
    }
    // �������򣬴�С�����������Ա�֤��Чʹ��
    sort(cow, cow + C);
    sort(bot, bot + L);

    int j = 0, ans = 0;
    // ���ڲ�ͬ�ķ�ɹ˪��������ͬ��ţ������ɹ˪�� SPF ���� ţ�� minSPF
    // �� push ţ�� maxSPF �� q �������棬��С��������
    for (int i = 0; i < L; i++)
    {
        while (j < C && cow[j].first <= bot[i].first)
        {
            q.push(cow[j].second);
            j++;
        }
        // ������ɺ󣬶� q ���н���������������һ���� pop ��һ��
        // �������������ݴ��ڸ�ƿ��ɹ˪�� SPF ��˵������ʹ�ã���ô������� 1 �����Ҹ�ƿ��ɹ˪���� -1
        // ������ q Ϊ�ջ��߸÷�ɹ˪ʹ�����
        while (!q.empty() && bot[i].second)
        {
            int x = q.top();
            q.pop();
            // �� maxSPF С�ڷ�ɹ˪�� SPF ˵������ʹ��
            if (x < bot[i].first)
            {
                continue;
            }
            ans++;
            bot[i].second--;
        }
    }
    printf("%d", ans);
    return 0;
}
