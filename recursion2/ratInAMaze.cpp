#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve(int i, int j, vector<vector<int>> &m, vector<vector<int>> &visited, string op, vector<string> &output, int n)
{
    if (i ==n-1  && j == n-1)
    {
        output.push_back(op);
        return;
    }
    visited[i][j] = 1;
    if (i + 1 <n && m[i + 1][j] != 0 && visited[i + 1][j] == 0)
    {
        op.push_back('d');
        solve(i + 1, j, m, visited, op, output, n);
        op.pop_back();
    }
    if (j + 1 <n && m[i][j + 1] != 0 && visited[i][j + 1] == 0)
    {
        op.push_back('r');
        solve(i, j + 1, m, visited, op, output, n);
        op.pop_back();
    }
    if (i - 1 >= 0 && m[i - 1][j] != 0 && visited[i - 1][j] == 0)
    {
        op.push_back('u');
        solve(i - 1, j, m, visited, op, output, n);
        op.pop_back();
    }
    if (j - 1 >= 0 && m[i][j - 1] != 0 && visited[i][j - 1] == 0)
    {
        op.push_back('l');
        solve(i, j - 1, m, visited, op, output, n);
        op.pop_back();
    }
    visited[i][j] = 0;
}

vector<string> findPath(vector<vector<int>> &m, int n)
{
    string op;
    vector<string> output;
    vector<vector<int>> visited(n, vector<int>(n, 0));
    solve(0, 0, m, visited, op, output, n);
    return output;
}

int main()
{
    vector<vector<int>>m={{1,0,0,0},{1,1,0,1},{1,1,0,0},{0,1,1,1}};
    vector<string>op=findPath(m,m[0].size());
    for(int i=0;i<op.size();i++){
        cout<<op[i]<<endl;
    }
    return 0;
}