#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Graph{
    public:
        unordered_map<int,list<int>>adjList;
        void addEdge(int u,int v){
            adjList[u].push_back(v);
            adjList[v].push_back(u);
            return;
        }

        void printAdjList(){
            for(auto i:adjList){
                cout<<i.first<<" --> ";
                for(auto j:i.second){
                    cout<<j<<" , ";
                }
                cout<<endl;
            }
        }
};

int main(){

    Graph g;
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(1,3);
    g.addEdge(3,4);
    g.addEdge(1,4);
    g.addEdge(4,0);

    g.printAdjList();
    return 0;
}