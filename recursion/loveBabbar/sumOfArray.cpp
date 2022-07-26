#include<iostream>

using namespace std;

int SumofArray(int* arr,int n){
    if(n==0)return 0;
    return arr[n-1]+SumofArray(arr,n-1);
}

int main(){
    int arr[]={34,66};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<SumofArray(arr,n);
    return 0;
}