#include <iostream>
#include <cstdio>
using namespace std;

int n;
int field[20][20];
int h, w;
int t1, t2, c, minstep;
int direc[4][2] = {
    {0, -1},
    {0, 1},
    {-1, 0},
    {1, 0},
};
void dfs(int x, int y, int c)
{
    if (c >= 10 || c > minstep) // ���ڲ��� c ���� c �����涨ֵʱ������Բ��ý�������
    {
        return ;
    }

    for (int i = 0; i < 4; i++) // �����ƶ��������ѡ��
    {
        int cx = x;
        int cy = y; // �ƶ���ʼλ��

        while (cx >= 0 && cx <= h && cy >= 0 && cy <= w) // ��֤�ƶ������ڳ�����
        {
            switch (field[cx][cy]) // ���ƶ���λ����������жϣ��� 0 �� 1 �� 3 ��3�����
            {
                case 0:{
                    cx += direc[i][1];
                    cy += direc[i][0]; // �����ո��ƶ��������� 0 ʱ��˵�����ܳ��÷����˶�
                    break; // �˶������Ҫ�ж���λ�����������Ҫ���� switch ���� while ��ʼ�ж�
                }
                case 3:
                    {
                        if (c + 1 < minstep) // ��ʱ���ִ��յ㣬����Ҫ�жϲ�������С�����Ľ�Сֵ����С�� minstep ���򽫲������� minstep
                        {
                            minstep = c + 1;
                        }
                        cx = -1; // ���ڵִ��յ㣬��Ҫ���� while ��ʹ���µ��ƶ�����
                        break; // ���� switch
                    }
                case 1:{
                    if (!(cx - direc[i][1] == x && cy - direc[i][0] == y)) // �� if ����ж�Ϊ true ʱ��˵���ƶ�λ�����ʼλ�ò����ڣ���ʱ
                                                                           // ���Խ�ʯ�飨3�����飬��Ϊ 0 ��ͬʱ����λ����Ϊ��ʼλ���жϺ������
                    {
                        field[cx][cy] = 0;
                        dfs(cx - direc[i][1], cy - direc[i][0], c + 1);
                        field[cx][cy] = 1; // ���ڻ�Ҫ�������������������Ҫ����λ�ñ�� 1
                    }
                    cx  = -1; // �� if ���Ϊ false ʱ��˵����ʼλ�����ƶ�λ�����ڣ����ܳ��÷����ƶ�������Ҫ���� while �����¶����ƶ�����
                              // ���ߵ� if ���Ϊ true �����Ѿ��������������ж�����Ҫ���� while
                    break;
                }
            }
        }
    }
}
int main()
{
    scanf("%d", &n); // ��Ҫ�������
    while (n--)
    {
        scanf("%d %d", &h, &w); // ���ش�С
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                scanf("%d", &field[i][j]); // ����
            }
        }

        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                if (field[i][j] == 2) // ��ʼλ��
                {
                    t1 = i;
                    t2 = j; // ���濪ʼλ��
                    break;
                }
            }
        }

        field[t1][t2] = 0; // �����Ѿ��ҵ���ʼλ�ã����Խ���λ������ '2' ��Ϊ '0' ,ʹ��Ҳ���Դ����˶�·����
        minstep = 11; // ��ȷ�� minstep Ϊ 11 ���� dfs �޷��ﵽ�յ�λ��ʱ��Ҳ�ܱ�֤��� minstep > 10
        dfs(t1, t2, 0);
        if (minstep > 10)
        {
            minstep = -1; // ����Ҫ�����޷��ﵽ�յ�򳬹����� 10 ������� -1
        }
        printf("%d", minstep);
    }


    return 0;
}
