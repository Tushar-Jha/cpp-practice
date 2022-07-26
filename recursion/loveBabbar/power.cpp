#include<iostream>

using namespace std;

int twoPowern(int n){
    if(n==0)return 1;
    return 2*twoPowern(n-1);
}

int main(){
    cout<<twoPowern(1);
    return 0;
}