#include<iostream>
#include<bits/stdc++.h>

using namespace std;

bool isSorted(int arr[],int n){
    if(n==1){
        return true;
    }
    if(arr[n-1]<arr[n-2]){
        return false;
    }else{
        return isSorted(arr,n-1);
    }
}

int main(){
    int arr[]={2};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<isSorted(arr,n);
    return 0;
}