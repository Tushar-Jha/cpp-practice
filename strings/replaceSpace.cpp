#include<iostream>
#include<bits/stdc++.h>

using namespace std;

string replaceSpaces(string &s){
    int n=s.length();
    string s2="@40";
    for(int i=0;i<n;i++){
        if(s[i]==' '){
            s.erase(s.begin()+i);
            s.insert(i,s2);
        }
    }
    return s;
}


int main(){
    string str="abc def ghi";
    cout<<replaceSpaces(str);
    return 0;
}