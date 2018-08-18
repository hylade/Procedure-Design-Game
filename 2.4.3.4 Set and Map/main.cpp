#include <iostream>
#include <cstdio>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
using namespace std;
/*
// set 使用
int main()
{
    set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);

    // 查找元素
    set<int>::iterator ite;

    ite = s.find(1); // find 函数若找到元素则返回键值迭代器的位置，否则，返回最后一个元素
                     // 由于此处已经定义迭代器 ite ，便可赋值，若不使用迭代器，需要使用 *
    if (ite == s.end()) puts("not found"); // end 用于返回最后一个元素的迭代器
                                           // puts 用于输出字符串并换行
    else puts("found");

    ite = s.find(2);
    if (ite == s.end()) puts("not found");
    else puts("found");

    // 删除元素
    s.erase(3); // 删除集合中的元素

    // 其他查找元素的方法
    if (s.count(3) != 0) puts("found"); // 返回某个值元素的个数
    else puts("not found");

    // 遍历所有元素
    for (ite = s.begin(); ite != s.end(); ite++) // begin 用于返回第一个元素的迭代器
    {
        printf("%d\n", *ite);
    }

    return 0;
}
*/
// map 使用
int main()
{
    map<int, const char*> m; // 声明 int 为键， const char* 为值

    // 插入元素
    m.insert(make_pair(1, "one")); // meke_pair 能够无需写出类别，就可以生成一个 pair 对象
    m.insert(make_pair(10, "ten"));
    m[100] = "hundred"; // 直接赋值写法

    // 查找元素
    map<int, const char*>::iterator ite; // 定义迭代器
    ite = m.find(1); // 返回 1 的迭代器
    puts(ite ->second); // 输出 one

    ite = m.find(2);
    if (ite == m.end()) puts("not found");
    else puts("found");

    puts(m[10]); // 其他写法
    printf("%s", m[11]); // 若不存在，返回 null

    // 删除元素
    m.erase(10);

    // 遍历元素
    for (ite = m.begin(); ite != m.end(); ite++)
    {
        printf("%d: %s\n", ite ->first, ite ->second);
    }

    return 0;
}
