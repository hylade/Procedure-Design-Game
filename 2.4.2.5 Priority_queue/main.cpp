#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
/*
大部分情况不需要自行实现堆，都有优先队列的包
在此的 priority_queue 就是优先队列，但是取出的数值是最大值
*/
int main()
{
    priority_queue<int> pque; //priority_queue 类型的队列能将输入的数值，按照从大到小的顺序排列
    pque.push(3);
    pque.push(5);
    pque.push(1);
    while (!pque.empty())
    {
        printf("%d\n", pque.top()); // top 函数返回栈顶元素
        pque.pop(); // 删除第一个元素
    }


    return 0;
}
