#include<iostream>

using namespace std;

int fib(int n){
    if(n<2){
        return n;
    }
    return fib(n-1)+fib(n-2);
}


int main(){
    int ansFor=0;
    int a=0; int b=1;int temp;
    int n=8;
    for(int i=0;i<=n-2;i++){
        temp=a+b;
        a=b;
        b=temp;
    }
    cout<<b;
    return 0;
}