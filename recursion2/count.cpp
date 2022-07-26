#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void count(int n){
    if(n==0){
        cout<<n;
        return;
    }
    count(n-1);
    cout<<n;
   
}

int main(){
    count(5);
    return 0;
}