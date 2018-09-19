#include <iostream>
#include <cstdio>
#include <algorithm>
#include <math.h>
using namespace std;
/*
����ʹ��̰���㷨�����ڵ��쵽�����ߵľ��� y ���� y > r ʱ��˵���״�������ζ����ﲻ�˵���λ�ã���ֱ����� -1
�� y <= r ʱ�����״�Ľ�����һ������� [x1, x2] ����ˣ��������ÿ�����������Ӧ�Ļ���䣬�������漴ת��Ϊ���������ѡ������

�� n ��������ѡ��һ�����伯�ϣ��ü����и������䶼���ཻ��ͬʱ�����е�Ԫ�ظ������٣���ʱ�������ǽ�
*/
// ������������Ҳ�
struct coordinate{
    double left;
    double right;
};
// ����ÿ���㶼�������䣬 temp ����ȷ����ǰ���䷶Χ
coordinate p[1005], temp;
double r;
int n;
int flag;
// ��������
bool sor(coordinate a, coordinate b)
{
    return a.left < b.left;
}

int main()
{
    // cas ����ȷ����������
    int cas = 0;
    // ���� n �� r
    while (scanf("%d %lf", &n, &r))
    {
        // ͨ�� flag ȷ���Ƿ��в��ܸ��ǵĵ�
        flag = 0;
        // ������ 0 0 ʱ����
        if (n == 0 && r == 0)
        {
            break;
        }
        // �������������
        for (int i = 0; i < n; i++)
        {
            double a, b;
            scanf("%lf %lf", &a, &b);
            // �� b > r ʱ���� flag ��Ϊ 1 �������ʱ����ɴ�����
            if (b > r)
            {
                flag = 1;
            }
            // ȷ������������
            else{
                p[i].left = a - sqrt(r * r - b * b);
                p[i].right = a + sqrt(r * r - b * b);
            }
        }

        printf("Case %d:", ++cas);

        // �� flag Ϊ 1 ʱ����� -1
        if (flag)
        {
            printf("-1\n");
        }
        else{
            // ������˿�ʼɨ�裬������ʼ��Ϊ 1
            int count = 1;
            // ������������������У��������ʼɨ��
            sort(p, p + n, sor);
            // ����ȷ����ǰ����
            temp = p[0];

            for (int i = 1; i < n; i++)
            {
                // ���ص��������ʱ��Ҫ��һ�����䣬���ҵ�ǰ���� temp Ҫ��Ϊ p[i]
                if (p[i].left > temp.right)
                {
                    count += 1;
                    temp = p[i];
                }
                // ��ʱΪ�ص��������ʱ��Ҫʹ��С���䣬���������õ���
                else if (p[i].right < temp.right){
                    temp = p[i];
                }
                // ���ڲ����ص����������ʹ���ص����䣬��ʹ�õ�ǰ���� temp ���Ҳ����꼴��
            }
            printf("%d\n", count);
        }
        printf("\n");

    }


    return 0;
}
