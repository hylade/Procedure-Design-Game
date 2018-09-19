#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
/*
队列（Queue）与栈一样支持 push 和 pop 两个操作。但与栈不同， pop 完成的不是取出最顶端的元素，而是取出最底端的元素
也就是说最初放入的元素能够最先被取出，这种行为被叫做 FIFO： First In First Out, 即先进先出

与栈的使用一样，需要先将标准库 <queue> 包括进来

queue::front 是用来访问最底端数据的函数
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
