#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;
/*
对于该题中字典序是指：从前到后比较两个字符串大小的方法。首先比较第 1 个字符，如果不同则第 1 个字符较小的字符串更小，
如果相同则继续比较第 2 个字符...如此继续，来比较整个字符串的大小

贪心算法实现：
不断提取字符串 S 的开头和末尾中较小的一个字符添加到 T 的末尾
但此时没有考虑首尾字符相同的情形，在这种时候，需要对下一个字符进行比较

1. 按照字典序比较 S 和将 S 反转后的字符串 S'
2. 如果 S 较小，则从 S 的头部取一个字符追加到 T 的尾端
3. 如果 S' 较小，则从 S 的尾端取出一个字符追加到 T 的尾端
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
        } // 输入字符串 S
    int l = 0, r = n - 1;
    while(l <= r)
    {
        bool left; // 表示是否取左边
        for (int i = 0; l + i <= r; i++)
        {
            if (S[l + i] < S[r - i]) // 进行比较，若相同则 i++ ，进行下一字符比较
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
                putchar(S[l++]); // 等于 putchar(S[l]), l++;
            }
            else
            {
                printf("%c", S[r--]);
            }
        }
    }
    return 0;
}
