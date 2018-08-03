#include <iostream>
#include <cstdio>
#include <set>
#include <string>
#include <algorithm>
using namespace std;
/*
��ǰ��״̬���Զ���Ϊ��ǰλ�á���ǰ���ֳ��ȡ���ǰ����������Ҫ��
����״̬ת�� dfs �ɱ�������������������ִ������ʹ�� set ������Ҫ��
*/
// ���أ�������
int field[5][5];
// ���ڱ����Ժ���������
set<int> results;
// �ƶ�����
int direction[4][2] = {
    {0, 1},
    {0, -1},
    {-1, 0},
    {1, 0},
    };

    // dfs ����
void dfs(const int& x, const int& y, const int& step, const int& number)
{
    // �����ӽ���ʱ
	if (step == 5)
	{
	    // insert ����ֵ����ͬʱ��������ֵ�ĵ�������һ�� bool ֵ
		results.insert(number);
		return;
	}

	// ��������
    for (int i = 0; i < 4; i++)
    {
        // �ƶ�����λ��
        int nx = x + direction[i][0];
        int ny = y + direction[i][1];

        // �ж��ƶ���ĵ��Ƿ����
        if (nx >= 0 && nx < 5 && ny >= 0 && ny < 5)
        {
            // ��û�г��磬����Ϊ����㣬��������
            dfs(nx, ny, step + 1, number * 10 + field[nx][ny]);
        }
    }
}

int main()
{
    // ����
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            scanf("%d", &field[i][j]);
        }
    }

    // ��ÿ������Ϊ���������
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            dfs(i, j, 0, field[i][j]);
        }
    }

    printf("%d", results.size());

    return 0;
}
