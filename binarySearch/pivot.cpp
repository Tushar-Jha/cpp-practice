//find pivot element index in the array
//and search in rotated array
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int pivot(int arr[],int n){
    int s=0,e=n-1;
    while(s<e){
        int m=s+(e-s)/2;
        if(arr[m]>arr[0]){
            s=m+1;
        }else{
            e=m;
        }
    }
    return s;
}

int bsearch(int arr[],int n,int key,int beg,int end){
    int s=beg,e=end;
    while(s<=e){
        int m=s+(e-2)/2;
        if(arr[m]==key)
            return m;
        else if(key>arr[m])
            s=m+1;
        else
            e=m-1; 
    }   
    return -1;
}

int searchInRotated(int arr[],int n,int key){
    int pivotindex=pivot(arr,n);
    if(key==arr[0])
        return 0;
    else if(key=arr[pivotindex])
        return pivotindex;
    else if(key>arr[0]){
        return bsearch(arr,n,key,0,pivotindex-1);
    }
    else 
        return bsearch(arr,n,key,pivotindex,n-1);
}

int main(){
    int arr[]={9,11,13,14,5,6,7,8};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<searchInRotated(arr,n,5);
    return 0;
}