//first and last occurence of an element in  a sorted array
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int firstOccurence(int arr[],int n,int key){
    int s=0,e=n-1;
    int firstOcc=-1;
    while(s<=e){
        int m=s+(e-s)/2;
        if(arr[m]==key){
            e=m-1;
            firstOcc=m;
        }else if(arr[m]>key)
            e=m-1;
        else 
            s=m+1;
    }
    return firstOcc;
}

int lastOccurence(int arr[],int n,int key){
    int s=0,e=n-1;
    int lastOcc=-1;
    while(s<=e){
        int m=s+(e-s)/2;
        if(arr[m]==key){
            s=m+1;
            lastOcc=m;
        }else if(arr[m]>key)
            e=m-1;
        else 
            s=m+1;
    }
    return lastOcc;
}

int main(){
    int arr[]={1,2,3,3,4,5,6,6,6,6,7};
    int n=sizeof(arr)/sizeof(arr[0]);
    int ans=firstOccurence(arr,n,6);
    int ans2=lastOccurence(arr,n,6);

    cout<<ans<<endl<<ans2;
    return 0;
}