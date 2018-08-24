#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int prev[100]; // 最短路上的前驱点

// 路径关键函数
vector<int> get_path(int t)
{
    vector<int> path;
    // 倒退路径
    for(; t != -1; t = prev[t])
    {
        path.push_back(t);
    }
    // 逆序排列
    reverse(path.begin(), path.end());
    return path;
}

int main()
{
    fill(prev+1, prev+V+1, -1);

    prev[edge[j].v] = edge[j].u; // 记录前驱点

    vector<int> path;
    path = get_path(V);
    // 输出路径
    for (vector<int>::size_type i = 0; i < path.size(); i++)
    {
        cout << path[i] << " ";

    }
    cout << endl;


    return 0;
}
