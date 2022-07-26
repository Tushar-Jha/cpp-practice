#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void dfs(int i, vector<bool> &visited, unordered_map<int, list<int>> &adj, 
vector<int> &path, int &specialPaths, vector<int> &vals)
{
    visited[i] = true;
    for (auto n : adj[i])
    {
        if (!visited[n] && vals[n - 1] <= vals[path[0] - 1])
        {
            path.push_back(n);
            if (vals[n - 1] == vals[path[0] - 1])
                specialPaths++;
            dfs(n, visited, adj, path, specialPaths, vals);
            path.pop_back();
        }
    }
    visited[i] = false;
}

int specialPaths(int N, vector<vector<int>> edges, vector<int> vals)
{
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int specialPaths = 0;
    vector<int> path;
    vector<bool> visited(N + 1, false);
    for (int i = 1; i <= N; i++)
    {
        if (visited[i] == false)
        {
            path.push_back(i);
            dfs(i, visited, adj, path, specialPaths, vals);
            path.pop_back();
        }
    }
    return specialPaths/2;
}

int main()
{
    int N = 6;
    vector<vector<int>> edges = {{1, 2}, {1, 3}, {3, 4}, {3, 5}, {2, 6}};
    vector<int> vals = {2, 3, 1, 2, 3, 3};
    cout << specialPaths(N, edges, vals);
    return 0;
}