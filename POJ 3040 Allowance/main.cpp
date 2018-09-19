#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string.h>
using namespace std;
/*
̰�Ĳ�����ʹ�෢�������С����ʱΪ���Ž�
1. ������С�� C ��Ӳ������û�취��Լ�����ͣ�ֱ�ӷ���
2. ����Ӳ�����Ӵ�С�����յýӽ� C ��������ڻ��� C �����ǲ��ܳ��� C
3. ���Ű�Ӳ������С������� C ����������˼��������һ����С��ֵ����С��ֵ��ָ
ʣ��Ӳ����������Ϊ 0 ��Ӳ���е���С��ֵ��������֮��ó����Ž⣬������һ�࣬Ȼ�����½��� 2

ΪʲôҪ�ȷ������ٷ�С��
��Ϊ�����С�ı��������Դ�ķŽ�ȥ������һ��Ҫ�Ž�ȥ����ΪС�Ĳ�����ôȡ���ڳ��� C ֮ǰһ����յ���������
��ô�ô�����һ�����š���һ����ɺ�һ��Ҫ�Ž�ȥһ��Ӳ�ң�ѡ����С�Ĳ�����ʹ�ʹ��� C ��һ��Ҳ�����ŵ�
*/
// ����Ӳ���� ��ֵ������
typedef pair<int, int> Coin;
Coin coin[20];
// ÿ��Ӳ�һ�ĳ����Ӳ����ϴﵽ C ʱ�������������
int need[20];
int N, C;
int main()
{
    // ����Ӳ������͹��� C
    while (scanf("%d %d", &N, &C) != EOF)
    {
        // �������Ӳ�ҵ���ֵ������
        for (int i = 0; i < N; i++)
        {
            scanf("%d %d", &coin[i].first, &coin[i].second);
        }

        // ��ʼ������
        int week = 0;

        // ������ֵ���� C ��Ӳ�ң�ֱ�ӽ��������ӵ� week �ϣ����ҽ���������Ϊ 0
        for (int i = 0; i < N; i++)
        {
            if (coin[i].first > C)
            {
                week += coin[i].second;
                coin[i].second = 0;
            }
        }

        // ���� sort ����Ӳ����������򣬴Ӵ�С����
        // C++ ���ṩ�˱ȽϺ���
        // less<Type>() ��С��������
        // greater<Type>() �Ӵ�С����
        // less_equal<Type>() <= ����
        // greater_equal<Type>() >= ����
        sort(coin, coin + N, greater<Coin>());

        while (1)
        {
            // �ȴ������� sum
            int sum = C;
            // ���Ƚ� need �����ʼ��Ϊ 0
            memset(need, 0, sizeof(need));

            // �Ӵ���ֵ��ʼ����
            for (int i = 0; i < N; i++)
            {
                // ��ʣ������� sum > 0 ���Ҹ���ֵ�������ж���ʱ
                if (sum > 0 && coin[i].second >0)
                {
                    // ȡʣ��������ʹ�ܺͲ����� sum ��Ӳ�������Ľ�Сֵ
                    int can = min(coin[i].second, sum / coin[i].first);

                    if (can > 0)
                    {
                        // ������Ҫ������ sum
                        sum -= coin[i].first * can;
                        // ����Ӳ�ҵ���Ҫ����
                        need[i] = can;
                    }
                }
            }

            // ��С��ֵ��ʼ����
            for (int i = N - 1; i >= 0; i--)
            {
                if (sum > 0 && coin[i].second > 0)
                {
                    // coin[i].second - need[i] ����Ҫ���Ƕ���ͬ��Ӳ������һ��ѭ����ʹ����һ����
                    // (coin[i].first + sum - 1) / coin[i].first) ������һ����������ֵ�Ľ��
                    int can = min(coin[i].second - need[i], (coin[i].first + sum - 1) / coin[i].first);

                    if (can > 0)
                    {
                        sum -= coin[i].first * can;
                        need[i] += can;
                    }
                }
            }

            // �� sum ��ѭ������Դ��� 0 ��˵��ĳ����ݵ�Ӳ�Ҳ��ܴﵽ C ��Ҫ��
            if (sum > 0)
            {
                break;
            }

            int mina = 2e9;

            // ����Ӳ��������Ӳ����Ҫ�������ʹ�ø�������µ� week ֵ
            for (int i = 0; i < N; i++)
            {
                if (need[i] != 0)
                {
                    mina = min(mina, coin[i].second / need[i]);
                }
                else{
                    continue;
                }
            }

            // ����Ӳ�����
            for (int i = 0; i < N; i++)
            {
                if (need[i] == 0)
                {
                    continue;
                }
                else{
                    coin[i].second -= mina * need[i];
                }
            }

            week += mina;
        }
        printf("%d", week);
    }

    return 0;
}
