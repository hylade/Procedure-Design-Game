#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
/*
���У�Queue����ջһ��֧�� push �� pop ��������������ջ��ͬ�� pop ��ɵĲ���ȡ����˵�Ԫ�أ�����ȡ����׶˵�Ԫ��
Ҳ����˵��������Ԫ���ܹ����ȱ�ȡ����������Ϊ������ FIFO�� First In First Out, ���Ƚ��ȳ�

��ջ��ʹ��һ������Ҫ�Ƚ���׼�� <queue> ��������

queue::front ������������׶����ݵĺ���
*/
int main()
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    printf("%d\n", q.front());
    q.pop();
    printf("%d\n", q.front());
    q.pop();
    printf("%d\n", q.front());



    return 0;
}
