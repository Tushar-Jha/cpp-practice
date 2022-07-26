//shortest path in a Directed Weighted Acyclic Graph
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Graph{
    public:
    unordered_map<int,list<pair<int,int>>>adjList;

    void addEdge(int u,int v,int w){
        pair<int,int>p;
        p.first=v;
        p.second=w;
        adjList[u].push_back(p);
    }

    void printAdj(){
        for(auto i:adjList){
            cout<<i.first<<" -> ";
            for(auto j:i.second){
                cout<<" ( "<<j.first<<" , "<<j.second<<" ) ";
            }
            cout<<endl;
        }
    }

    void dfs(int node, unordered_map<int,bool>&visited, stack<int>&s){
        visited[node]=true;
        
        for(auto n:adjList[node]){
            if(visited[n.first]!=true){
                dfs(n.first,visited,s);
            }
        }

        s.push(node);
    }

    void getShortestPath(int src,vector<int>&dist,stack<int>&s){
        dist[src]=0;

        while(!s.empty()){
            int top=s.top();
            s.pop();

            if(dist[top]!=INT_MAX){
                for(auto i:adjList[top]){
                    if(dist[top]+i.second<dist[i.first]){
                        dist[i.first]=dist[top]+i.second;
                    }
                }
            } 
        }
    }
};



int main(){


    Graph g;

    g.addEdge(0,1,5);
    g.addEdge(0,2,3);
    g.addEdge(1,2,2);
    g.addEdge(1,3,6);
    g.addEdge(2,3,7);
    g.addEdge(2,4,4);
    g.addEdge(2,5,2);
    g.addEdge(3,4,-1);
    g.addEdge(4,5,-2);


    g.printAdj();

    unordered_map<int,bool>visited;
    int n=6;

    stack<int>s;
    for(int i=0;i<n;i++){
        if(visited[i]!=true){
            g.dfs(i,visited,s);
        }
    }

    vector<int>distance(n,INT_MAX);
    int source=1;
    g.getShortestPath(source,distance,s);

    cout<<endl;
    for(auto ele:distance){
        cout<<ele<<" ";
    }

    return 0;
}
