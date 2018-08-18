#include <iostream>
#include <cstdio>
#include <math.h>
#include <string.h>
#include <queue>
#include <algorithm>
using namespace std;
/*
�����������ܹ���Ч���
1. ����һ����ֵ
2. ��ѯ�Ƿ����ĳ����ֵ
3. ɾ��ĳ����ֵ

�ڶ��������������нڵ㣬�������������ϵ����нڵ㶼���Լ�С�����������ϵ����нڵ㶼���Լ���

������ֵ������������ֵ�Ƚϣ�ȷ������������������������Ȼ��ѭ��

������ֵ�����ղ�����ֵ�ķ������Ϳ���֪����Ӧ�ڵ�����λ�ã�Ȼ�����Ǹ�λ�ò����µĽڵ㼴��

ɾ����ֵ����Ҫ��Ϊ���������
1. ��Ҫɾ���Ľڵ�û������ӣ���ô�Ͱ��Ҷ�������ȥ
2. ��Ҫɾ���Ľڵ�������û���Ҷ��ӣ���ô�Ͱ����������ȥ
3. �������������������Ļ����Ͱ���������������Ľڵ��ᵽ��Ҫɾ���Ľڵ���

�����������ĸ��Ӷ������ĸ߶ȳ����ȣ�ƽ��ÿ�β���Ϊ O(log)
*/

// ��ʵ�ִ���

// ��ʾ�ڵ�Ľṹ��
struct node{
    int val;
    node *lch, *rch;
};

// ������ֵ x
node *insert(node *p, int x){
    if (p == NULL) // ���ڵ㲻����ʱ���㴴���½ڵ㣬�����ӽڵ��Ϊ NULL
    {
        node *q = new node;
        q ->val = x;
        q ->lch = q ->rch = NULL;
        return q;
    }
    else{
        if (x < p ->val) p->lch = insert(p ->lch, x); // ����ֵС�� p ��ֵ������������ѭ��
        else p ->rch = insert(p ->rch, x); // ������������ѭ��
        return p;
    }
}

// ������ֵ x
bool find(node *p, int x)
{
    if (p == NULL) return false; // ����ʼѰ�ҵĽڵ�Ϊ�գ��㷵�� 0 (�Ҳ���)
    else if (x == p ->val) return true; // ����ֵ���ʱ��˵���ҵ���ֵ������ true
    else if (x < p ->val) return find(p ->lch, x); // ����ֵС�� p ��ֵ������������ѭ��Ѱ��
    else return find(p ->rch, x); // ������������ѭ������
}

// ɾ����ֵ x
node *remove(node *p, int x)
{
    if (p == NULL) return NULL; // ���ڵ㲻���ڣ����ؿ�
    else if (x < p ->val) p ->lch = remove(p ->lch, x); // ��ֵ�����ʱ���������������Ҹ���ֵ
    else if (x > p ->rch) p ->rch = remove(p ->rch, x);
    else if (p ->lch == NULL) // ���ҵ�����ֵ�ڵ㣬ͬʱ����ڵ�Ϊ�գ���Ӧ��һ���������ô�����ҽڵ�����ȥ��ɾ�� p �ڵ�
    {
        node *q = p ->rch;
        delete p;
        return q;
    }
    else if (p ->lch->rch == NULL) // ����ڵ��������Ϊ��ʱ����Ӧ�ڶ�������������������ᣬ����ԭ��������Ϊ�½ڵ��������
    {
        node *q = p ->lch;
        q ->rch = p ->rch;
        delete p;
        return q;
    }
    else{ // �����Ӧ���������
        node *q;
        for (q = p ->lch; q ->rch->rch != NULL; q = q ->rch); // �ҵ�����������ֵ���ĵ㣬��һֱ��������
        node *r = q ->rch;
        q ->rch = r ->lch; // �� q ���������� r ������������
        r ->lch = p ->lch; // r �̳� p ����������
        r ->rch = p ->rch;
        delete p;
        return r;
    }
}
int main()
{

    return 0;
}
