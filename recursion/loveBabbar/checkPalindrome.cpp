#include<iostream>
#include<bits/stdc++.h>

using namespace std;

bool isPal(string str,int n,int i){
    if(i>=n/2) return true;
    if(str[i]!=str[n-1-i]) return false;
    else return isPal(str,n,++i);
}

int main(){
    string str="abccba";
    cout<<isPal(str,str.length(),0);
    return 0;
}