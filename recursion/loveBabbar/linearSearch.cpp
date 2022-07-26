#include<iostream>

using namespace std;

bool linearSearch(int* arr,int n,int key){
    if(n==0)return false;
    if(arr[0]==key)return true;
    else return linearSearch(arr+1,n-1,key);
}

int main(){
    int arr[]={3,5,1,2,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<linearSearch(arr,n,5);
    return 0;
}