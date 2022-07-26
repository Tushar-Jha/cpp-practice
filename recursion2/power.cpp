#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int exponent(int a,int n){
    if(n==0){
        return 1;
    }
    if(n==1){
        return a;
    }
    if(n%2!=0){
        return a*exponent(a,n/2)*exponent(a,n/2);
    }else{
        return exponent(a,n/2)*exponent(a,n/2);
    }
}

int main(){
    int a=7;
    int b=3;
    cout<<exponent(a,b);
    return 0;
}