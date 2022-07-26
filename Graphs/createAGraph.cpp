#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Graph
{
public:
    unordered_map<int, list<int>> adj;

    void addEdge(int u, int v, bool direction)
    {
        // dir->0====undirected
        // dir->1====directed
        adj[u].push_back(v);
        if (direction == false)
        {
            adj[v].push_back(u);
        }
    }

    void printAdjList()
    {
        for (auto i : adj)
        {
            cout << i.first << " -> ";
            for (auto j : i.second)
            {
                cout << j << ", ";
            }
            cout << endl;
        }
    }
};

void bfs(vector<int> &ans, int node, unordered_map<int, vector<int>> adjList, unordered_map<int, bool> &visited)
{
    queue<int> q;
    visited[node] == true;
    q.push(node);
    while (!q.empty())
    {
        int currNode = node;
        q.pop();
        ans.push_back(currNode);
        for (auto neighbour : adjList[currNode])
        {
            if (visited[neighbour] != true)
            {
                q.push(neighbour);
            }
            visited[neighbour] = true;
        }
    }
}

void dfs(vector<int> &ans, int node, unordered_map<int, vector<int>> adjList, unordered_map<int, bool> &visited)
{
    visited[node] = true;
    ans.push_back(node);

    for (auto neighbour : adjList[node])
    {
        if (visited[neighbour] == false)
        {
            dfs(ans, neighbour, adjList, visited);
        }
        visited[neighbour] = true;
    }
}

vector<vector<int>> traversal(Graph G, int vertex, vector<vector<int>> edges)
{
    unordered_map<int, vector<int>> adjList;
    vector<vector<int>> ans;
    vector<int> bft, dft;
    unordered_map<int, bool> visited;

    for (auto edge : edges)
    {
        G.addEdge(edge[0], edge[1], 0);
    }

    for (int i = 0; i < vertex; i++)
    {
        if (visited[i] == false)
        {
            bfs(bft, i, adjList, visited);
            dfs(dft, i, adjList, visited);
        }
    }

    ans = {bft, dft};
    return ans;
}

int main()
{

    // cout << "Enter number of nodes" << endl;
    // int n;
    // cin >> n;

    // cout << "Enter number of edges" << endl;
    // int m;
    // cin >> m;

    Graph g;

    // for (int i = 0; i < m; i++)
    // {
    //     int u, v;
    //     cin >> u >> v;
    //     g.addEdge(u, v, 0);
    // }

    // g.printAdjList();

    int vertex = 7;
    vector<vector<int>> edges = {{0, 1}, {0, 3}, {1, 3}, {1, 2}, {1, 5}, {1, 6}, {2, 3}, {2, 5}, {2, 4}, {3, 4}, {4, 6}};

    vector<int> bfs = traversal(g, vertex, edges)[0];
    vector<int> dfs = traversal(g, vertex, edges)[1];
    for (int i = 0; i < bfs.size(); i++)
    {
        cout << bfs[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < dfs.size(); i++)
    {
        cout << dfs[i] << " ";
    }
    return 0;
}