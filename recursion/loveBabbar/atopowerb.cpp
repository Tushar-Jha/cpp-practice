#include<iostream>

using namespace std;

int power(int m,int n){
    if(n==0) return 1;
    return m*power(m,n-1);
}


//optimized
int powerTwo(int m,int n){
    if(n==0)return 1;
    if(n==1)return m;
    int b=powerTwo(m,n/2);
    int j=b*b;
    if(n%2==0)return j;
    else return m*j;
}

int main(){
    cout<<powerTwo(5,1);
    return 0;
}