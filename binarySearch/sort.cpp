#include<iostream>

using namespace std;

void selectionSort(int arr[],int n){
    for(int i=0;i<n;i++){
        int minI=i;
        for(int j=i;j<n;j++){
            if(arr[j]<arr[minI]){
                minI=j;
            }
        }
        swap(arr[i],arr[minI]);
    }
}


int main(){
    int arr[]={3,1,4,2,5,6,21,0,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    selectionSort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}