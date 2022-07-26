#include<iostream>
#include<bits/stdc++.h>

using namespace std;
//in bubble sort, in each iteration the (n-i)th largest element is 
//placed at the right position i.e, the largest element in the remaining  array  placed at,
//is placed at,the right position so we can recursively solve for the remaining array
void bubbleSort(int* arr,int n){
   if(n==0 || n==1)return;

   for(int i=0;i<n-1;i++){
       if(arr[i]>arr[i+1]){
           swap(arr[i],arr[i+1]);
       }
   }

   bubbleSort(arr,n-1);
}

int main(){
    int arr[]={7,9,8,2,5,6,37,812,222};
    int n=sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}