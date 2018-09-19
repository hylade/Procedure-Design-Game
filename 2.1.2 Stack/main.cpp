#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;

/*
栈（Stack）是支持 push 和 pop 的数据结构， push 是在栈的顶端放入一组数据的操作，反之 pop 是从顶端取出一组数据
因此，最后进入栈的数据最先被取出，这种行为被称为 LIFO： Last In First Out ，即后入先出

在 C++ 的标准库中， stack::pop 完成的便是移除最顶端的数据；若需要访问最顶端的数据，需要使用 stack::top 函数（通常也被称为 peek 函数）

调用时需要先将标准库 <stack> 包括进来,同时需要声明存储的类型，比如 int 类型
*/

// 通过 stack 来改写递归函数，如阶乘
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
    使用 stack 的例子
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
