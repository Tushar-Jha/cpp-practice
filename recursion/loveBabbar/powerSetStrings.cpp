#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void powerSet(string s,int n,string output,int i){
    if(i==n){
        cout<<output<<endl;
        return;
    }
    //include
    powerSet(s,n,output+s[i],i+1);
    //exclude
    powerSet(s,n,output,i+1);
}

int main(){
    string a="bac";
    string op="";
    int n=a.length();
    powerSet(a,n,op,0);
    return 0;
}