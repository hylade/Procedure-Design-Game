#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int t, l, n, pos, minans, maxans;

    scanf("%d", &t);;
    while(t--) {
        minans = 0;
        maxans = 0;

        scanf("%d %d", &l, &n);
        for(int i = 1; i <= n; i++) {
            scanf("%d", &pos);

            minans = max(minans, min(pos, l - pos)); // �������ʱ�䣬Ӧ��Ant�����϶̵�һ������ʱ�Ľϴ�ֵ

            maxans = max(maxans, max(pos, l - pos)); // �����ʱ�䣬ӦΪAnt���ϳ�һ������ʱ�����ֵ����ֻAnt�໥�Ӵ�����ʵ������Ϊ
                                                     // �Գ�ԭ�����˶���������Ϊ��ֻ���ϲ������ٶ�
        }

        printf("%d %d\n", minans, maxans);
    }

    return 0;
}
