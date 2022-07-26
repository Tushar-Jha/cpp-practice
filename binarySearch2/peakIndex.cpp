#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int peakIndex(vector<int>arr){
    int start=0;
    int end=arr.size()-1;
    while(start<end){
        int mid=start+(end-start)/2;
        if(arr[mid]>arr[mid+1]){
            end=mid;
        }else if(arr[mid]<arr[mid+1]){
            start=mid+1;
        }
    }
    return start;
}

int main(){
    vector<int>arr={1,2,4,10,9,8,7,6,5};
    cout<<peakIndex(arr);
    return 0;
}