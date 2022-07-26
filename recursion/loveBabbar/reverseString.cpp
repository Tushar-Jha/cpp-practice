#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void revString(string &str,int n,int i){
    if(i>=n/2){
        return;
    }
    swap(str[i],str[n-1-i]);
    revString(str,n,++i);
}

int main(){
    string a="ab";
    revString(a,a.length(),0);
    cout<<a;
    return 0;
}