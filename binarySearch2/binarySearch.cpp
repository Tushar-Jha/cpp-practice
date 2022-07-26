#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int searchB(vector<int>arr,int key){
    int start=0;
    int end=arr.size()-1;
    while(start<=end){
        int mid=start+(end-start)/2;
        if(arr[mid]==key){
            return mid;
        }
        else if(arr[mid]>key){
            end=mid-1;
        }else{
            start=mid+1;
        }
    }
    return -1;
}

int main(){

    vector<int>arr={1,34,456,1231,5567,10221,12222,10281021};
    cout<<searchB(arr,10281021);
    return 0;
}