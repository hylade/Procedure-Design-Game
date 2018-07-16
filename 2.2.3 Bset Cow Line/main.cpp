#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;
/*
���ڸ������ֵ�����ָ����ǰ����Ƚ������ַ�����С�ķ��������ȱȽϵ� 1 ���ַ��������ͬ��� 1 ���ַ���С���ַ�����С��
�����ͬ������Ƚϵ� 2 ���ַ�...��˼��������Ƚ������ַ����Ĵ�С

̰���㷨ʵ�֣�
������ȡ�ַ��� S �Ŀ�ͷ��ĩβ�н�С��һ���ַ���ӵ� T ��ĩβ
����ʱû�п�����β�ַ���ͬ�����Σ�������ʱ����Ҫ����һ���ַ����бȽ�

1. �����ֵ���Ƚ� S �ͽ� S ��ת����ַ��� S'
2. ��� S ��С����� S ��ͷ��ȡһ���ַ�׷�ӵ� T ��β��
3. ��� S' ��С����� S ��β��ȡ��һ���ַ�׷�ӵ� T ��β��
*/
int n;
int main()
{
    string S = "";
    while(~scanf("%d",&n)){
        char c;
        for(int i = 0; i < n; i++){
            cin >> c;
            S += c;
        } // �����ַ��� S
    int l = 0, r = n - 1;
    while(l <= r)
    {
        bool left; // ��ʾ�Ƿ�ȡ���
        for (int i = 0; l + i <= r; i++)
        {
            if (S[l + i] < S[r - i]) // ���бȽϣ�����ͬ�� i++ ��������һ�ַ��Ƚ�
            {
                left = true;
                break;
            }
            else if (S[l + i] > S[r - i])
            {
                left = false;
                break;
            }
        }

            if (left)
            {
                putchar(S[l++]); // ���� putchar(S[l]), l++;
            }
            else
            {
                printf("%c", S[r--]);
            }
        }
    }
    return 0;
}
