#include<iostream>
#include<bits/stdc++.h>

using namespace std;

bool isPossible(int arr[],int n,int m,int mid){
    int cowCount=1;
    
}

int aggressiveCows(int arr[],int n,int m){
    sort(arr,arr+n);
    int s=0;
    int maxi=-1;
    for(int i=0;i<n;i++){
        maxi=max(maxi,arr[i]);
    }
    int e=maxi;
    int ans=-1;
    while(s<=e){
        int mid=s+(e-s)/2;
        if(isPossible(arr,n,m,mid)){
            ans=mid;
            s=mid+1;
        }else{
            e=mid-1;
        }
    }
    return ans;
}

int main(){
    return 0;
}