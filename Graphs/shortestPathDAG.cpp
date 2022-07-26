#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void dfs(int node,vector<bool>&visited,unordered_map<int,list<pair<int,int>>>&adj,stack<int>&topo){
    visited[node]=true;

    for(auto x:adj[node]){
        if(visited[x.first]==false){
            dfs(x.first,visited,adj,topo);
        }
    }

    topo.push(node);
}

vector<int>shortestPathDAG(vector<vector<int>>edges,int n,int src){
    unordered_map<int,list<pair<int,int>>>adj;
    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];
        int w=edges[i][2];

        adj[u].push_back(make_pair(v,w));
    }

    vector<bool>visited(n,false);
    stack<int>topo;
    for(int i=0;i<n;i++){
        if(visited[i]==false){
            dfs(i,visited,adj,topo);
        }
    }

    vector<int>distance(n,INT_MAX);
    distance[src]=0;

    while(!topo.empty()){
        int top=topo.top();
        topo.pop();

        if(distance[top]!=INT_MAX){
            for(auto x:adj[top]){
                if(distance[top]+x.second<distance[x.first]){
                    distance[x.first]=distance[top]+x.second;
                }
            }
        }
    }
    return distance;
}

int main(){

    vector<vector<int>>edges={{0,1,5},{0,2,3},{1,2,2},{1,3,6},{2,3,7},{2,4,4},{2,5,2},{3,4,-1},{4,5,-2}};
    vector<int>ans=shortestPathDAG(edges,6,1);

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}