#include<iostream>

using namespace std;

bool check(int arr[],int n){
    int count=0;
    for(int i=1;i<n;i++)
        if(arr[i-1]>arr[i])
            count++;
    if(arr[0]<arr[n-1])
        count++;
    if(count<=1)return true;
    else return false;
}

int main(){
    int arr[]={7,8,1,2,3,4,5,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<check(arr,n);
    return 0;
}