#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Graph{
    public:
        int vertices;
        unordered_map<int,list<int>>adjList;

        void addEdge(int u,int v){
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        void printAdj(){
            for(auto i:adjList){
                cout<<" --> ";
                for(auto j:i){
                    cout<<j<<",";
                }
                cout<<endl;
            }
        }
};

int main(){

    return 0;
}