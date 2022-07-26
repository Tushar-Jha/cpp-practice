#include<iostream>
#include<bits/stdc++.h>

using namespace std;

bool checkPal(string s,int i){
    if(i>=s.length()/2){
        return true;
    }
    if(s[i]!=s[s.length()-1-i]){
        return false;
    }else{
        return checkPal(s,i+1);
    }
}


int main(){
    string s="ooo";
    cout<<checkPal(s,0);
    return 0;
}