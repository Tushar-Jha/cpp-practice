#include<iostream>
#include<bits/stdc++.h>

using namespace std;

vector<int> move(vector<int>&a,int n){
    int i=0;
    for(int j=0;j<n;j++){
        if(a[j]!=0){
            int temp=a[i];
            a[i]=a[j];
            a[j]=temp;
            i++;
        } 
    }
    return a;
}

int main(){
    vector<int> a={1,2,4,0,0,3,2,0,4,0,2,0};
    int n=a.size();
    vector<int> res=move(a,n);
    for(int i=0;i<n;i++){
        cout<<res[i]<<" ";
    }
    return 0;
}