#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve(vector<vector<int>> &m, vector<vector<bool>> visited, string op, int n, int i, int j, vector<string> &res)
{
    //basecase
    if (i == n - 1 && j == n - 1)
    {
        res.push_back(op);
        return;
    }
    visited[i][j] = true;
    if (i + 1 < n && m[i + 1][j] == 1 && visited[i + 1][j] == false)
    {
        op.push_back('d');
        solve(m, visited, op, n, i + 1, j, res);
        //backtracking step
        op.pop_back();
    }
    if (j + 1 < n && m[i][j + 1] == 1 && visited[i][j + 1] == false)
    {
        op.push_back('r');
        solve(m, visited, op, n, i, j + 1, res);
        //backtracking step
        op.pop_back();
    }
    if (j - 1 >= 0 && m[i][j - 1] == 1 && visited[i][j - 1] == false)
    {
        op.push_back('l');
        solve(m, visited, op, n, i, j - 1, res);
        //backtracking step
        op.pop_back();
    }
    if (i - 1 >= 0 && m[i - 1][j] == 1 && visited[i - 1][j] == false)
    {
        op.push_back('u');
        solve(m, visited, op, n, i - 1, j, res);
        //backtracking step
        op.pop_back();
    }
    visited[i][j] = false;
}

vector<string> findPath(vector<vector<int>> &m, int n)
{
    vector<string> res;
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    string op;
    solve(m, visited, op, n, 0, 0, res);
    sort(res.begin(),res.end());
    return res;
}

int main()
{
    vector<vector<int>> m = {{1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}};
    vector<string> res;
    res = findPath(m, 4);
    for (int i = 0; i < 4; i++)
    {
        cout << res[i] << " ";
    }
    return 0;
}