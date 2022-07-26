#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int sumOfArray(int arr[],int n){
    if(n==0){
        return 0;
    }
    return arr[n-1]+sumOfArray(arr,n-1);
}

int main(){
    int arr[]={3};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<sumOfArray(arr,n);
    return 0;
}