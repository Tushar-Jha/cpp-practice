#include<iostream>
#include<bits/stdc++.h>

using namespace std;

bool search(int arr[],int n,int key){
    if(n==0){
        return false;
    }
    if(arr[n-1]==key){
        return true;
    }else{
        return search(arr,n-1,key);
    }
}

int main(){
    int arr[]={2,3,4,5,6,7,8};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<search(arr,n,7);
    return 0;
}