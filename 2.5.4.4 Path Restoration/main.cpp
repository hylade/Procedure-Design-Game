#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int prev[100]; // ���·�ϵ�ǰ����

// ·���ؼ�����
vector<int> get_path(int t)
{
    vector<int> path;
    // ����·��
    for(; t != -1; t = prev[t])
    {
        path.push_back(t);
    }
    // ��������
    reverse(path.begin(), path.end());
    return path;
}

int main()
{
    fill(prev+1, prev+V+1, -1);

    prev[edge[j].v] = edge[j].u; // ��¼ǰ����

    vector<int> path;
    path = get_path(V);
    // ���·��
    for (vector<int>::size_type i = 0; i < path.size(); i++)
    {
        cout << path[i] << " ";

    }
    cout << endl;


    return 0;
}
