#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void dfs(int node, vector<list<int>>&adjList,vector<bool>&visited,vector<int>&components,int &index){
    visited[node]=true;
    components[index]++;
    for(auto n:adjList[node]){
        if(visited[n]==false){
            dfs(n,adjList,visited,components,index);
        }
    }
}

int journeyToMoon(int n, vector<vector<int>> astronaut) {
    vector<list<int>>adjList(n);
    for(int i=0;i<astronaut.size();i++){
        int u=astronaut[i][0];
        int v=astronaut[i][1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    //print adjlist
    for(int i=0;i<n;i++){
        cout<<i<<" --> ";
        for(auto j:adjList[i]){
            cout<<j<<" ";
        }
        cout<<endl;
    }

    vector<bool>visited(n,false);
    vector<int>components(n,0);
    int index=0;
    for(int i=0;i<n;i++){
        if(visited[i]==false){
            dfs(i,adjList,visited,components,index);
            index++;
        }
    }

    int ans=0;

    for(int i=0;i<components.size();i++){
        if(components[i]!=0){
            for(int j=i+1;j<components.size();j++){
                if(components[j]!=0){
                    ans+=components[i]*components[j];
                }
            }
        }
    }

    return ans;
}

int main(){
    vector<vector<int>>astronaut={{0,2},{1,8},{1,4},{2,8},{2,6},{3,5},{6,9}};
    int n=10;
    cout<<journeyToMoon(n,astronaut);
    return 0;
}

//5 3
//0 1
//2 3
//0 4


//4 1
//0 2

//0 2
// 1 8
// 1 4
// 2 8
// 2 6
// 3 5
// 6 9