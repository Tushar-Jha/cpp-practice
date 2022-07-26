#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void rev(string& s,int i,int j){
    cout<<s<<endl;
    if(i>j){
        return;
    }
    swap(s[i],s[j]);
    rev(s,++i,--j);
}

int main(){
    string name="tu";
    rev(name,0,name.length()-1);
    cout<<name;
    return 0;
}