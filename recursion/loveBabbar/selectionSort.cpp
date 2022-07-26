#include<iostream>

using namespace std;

void SelectionSort(int* arr,int n){
    if(n==1)return;
    int minIn=0;
    for(int j=0;j<n;j++){
        if(arr[j]<arr[minIn]){
            minIn=j;
        }
    }
    swap(arr[0],arr[minIn]);
    SelectionSort(arr+1,n-1);
}

int main(){
    int arr[]={3,4,5,24,6,71,23,1,2,8};
    int n=sizeof(arr)/sizeof(arr[0]);
    SelectionSort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}