#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
/*
�󲿷��������Ҫ����ʵ�ֶѣ��������ȶ��еİ�
�ڴ˵� priority_queue �������ȶ��У�����ȡ������ֵ�����ֵ
*/
int main()
{
    priority_queue<int> pque; //priority_queue ���͵Ķ����ܽ��������ֵ�����մӴ�С��˳������
    pque.push(3);
    pque.push(5);
    pque.push(1);
    while (!pque.empty())
    {
        printf("%d\n", pque.top()); // top ��������ջ��Ԫ��
        pque.pop(); // ɾ����һ��Ԫ��
    }


    return 0;
}
