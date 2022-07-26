#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int pivot(vector<int>arr){
    int start=0;
    int end=arr.size()-1;
    while(start<end){
        int mid=start+(end-start)/2;
        if(arr[mid]<arr[0]){
            end=mid;
        }else{
            start=mid+1;
        }
    }
    return start;
}

int main(){
    vector<int>arr={1,2,3,4,5,6,7,8};
    cout<<pivot(arr);
    return 0;
}