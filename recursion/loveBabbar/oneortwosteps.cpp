#include<iostream>

using namespace std;

int nStairs(int n){
    if(n<0)return 0;
    if(n==0)return 1;
    return nStairs(n-1)+nStairs(n-2);
}

int main(){
    cout<<nStairs(8);
    return 0;
}