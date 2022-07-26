#include<iostream>

using namespace std;

void merge(int* arr,int s,int mid, int e){
    int l1=mid-s+1;
    int l2=e-mid;
    int A[l1],B[l2];
    for(int i=0;i<l1;i++)
        A[i]=arr[s+i];
    for(int j=0;j<l2;j++)
        B[j]=arr[mid+1+j];

    int i=0,j=0,k=s;

    while(i<l1 && j<l2){
        if(A[i]<B[j])
            arr[k++]=A[i++];
        else
            arr[k++]=B[j++];
    }

    while(i<l1){
        arr[k++]=A[i++];
    }

    while(j<l2){
        arr[k++]=B[j++];
    }
}

void mergeSort(int* arr,int s, int e){
    if(s>=e)return;
    int mid=s+(e-s)/2;
    mergeSort(arr,s,mid);
    mergeSort(arr,mid+1,e);
    merge(arr,s,mid,e);
}

int main(){
    int arr[]={24,35,12,36,2,1,368,9,222};
    int n=sizeof(arr)/sizeof(arr[0]);
    mergeSort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}