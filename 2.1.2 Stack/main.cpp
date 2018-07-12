#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;

/*
ջ��Stack����֧�� push �� pop �����ݽṹ�� push ����ջ�Ķ��˷���һ�����ݵĲ�������֮ pop �ǴӶ���ȡ��һ������
��ˣ�������ջ���������ȱ�ȡ����������Ϊ����Ϊ LIFO�� Last In First Out ���������ȳ�

�� C++ �ı�׼���У� stack::pop ��ɵı����Ƴ���˵����ݣ�����Ҫ������˵����ݣ���Ҫʹ�� stack::top ������ͨ��Ҳ����Ϊ peek ������

����ʱ��Ҫ�Ƚ���׼�� <stack> ��������,ͬʱ��Ҫ�����洢�����ͣ����� int ����
*/

// ͨ�� stack ����д�ݹ麯������׳�
int fact(int n)
{
    stack<int> s;
    s.push(1);
    if (n == 0)
    {
        return s.top();
    }
    else
    {
        s.push(n * fact(n - 1));
        return n * fact(n - 1);
    }
}
int main()
{
    /*
    ʹ�� stack ������
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    printf("%d\n", s.top());
    s.pop();
    printf("%d\n", s.top());
    s.pop();
    printf("%d\n", s.top());
    */
    int n = 3;
    int a = fact(n);
    printf("%d", a);


    return 0;
}
