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
// set ʹ��
int main()
{
    set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);

    // ����Ԫ��
    set<int>::iterator ite;

    ite = s.find(1); // find �������ҵ�Ԫ���򷵻ؼ�ֵ��������λ�ã����򣬷������һ��Ԫ��
                     // ���ڴ˴��Ѿ���������� ite ����ɸ�ֵ������ʹ�õ���������Ҫʹ�� *
    if (ite == s.end()) puts("not found"); // end ���ڷ������һ��Ԫ�صĵ�����
                                           // puts ��������ַ���������
    else puts("found");

    ite = s.find(2);
    if (ite == s.end()) puts("not found");
    else puts("found");

    // ɾ��Ԫ��
    s.erase(3); // ɾ�������е�Ԫ��

    // ��������Ԫ�صķ���
    if (s.count(3) != 0) puts("found"); // ����ĳ��ֵԪ�صĸ���
    else puts("not found");

    // ��������Ԫ��
    for (ite = s.begin(); ite != s.end(); ite++) // begin ���ڷ��ص�һ��Ԫ�صĵ�����
    {
        printf("%d\n", *ite);
    }

    return 0;
}
*/
// map ʹ��
int main()
{
    map<int, const char*> m; // ���� int Ϊ���� const char* Ϊֵ

    // ����Ԫ��
    m.insert(make_pair(1, "one")); // meke_pair �ܹ�����д����𣬾Ϳ�������һ�� pair ����
    m.insert(make_pair(10, "ten"));
    m[100] = "hundred"; // ֱ�Ӹ�ֵд��

    // ����Ԫ��
    map<int, const char*>::iterator ite; // ���������
    ite = m.find(1); // ���� 1 �ĵ�����
    puts(ite ->second); // ��� one

    ite = m.find(2);
    if (ite == m.end()) puts("not found");
    else puts("found");

    puts(m[10]); // ����д��
    printf("%s", m[11]); // �������ڣ����� null

    // ɾ��Ԫ��
    m.erase(10);

    // ����Ԫ��
    for (ite = m.begin(); ite != m.end(); ite++)
    {
        printf("%d: %s\n", ite ->first, ite ->second);
    }

    return 0;
}
