//Find the peak value index in a mountain array
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int peakInMountain(int arr[],int n){
    int s=0,e=n-1;
    while(s<e){
        int m=s+(e-s)/2;
        if(arr[m]>arr[m+1]){
            e=m;
        }
        else{
            s=m+1;
        }
    }
    return s;
}

int main(){
    int arr[]={1,3,5,7,8,6,4,2,1,0};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<peakInMountain(arr,n)<<endl;
    return 0;
}