#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int fibonacci(int n){
    if(n<=1){
        return n;
    }
    return fibonacci(n-1)+fibonacci(n-2);
}

int main(){
    int n=1;
    cout<<fibonacci(2);
    return 0;
}