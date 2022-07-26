#include<iostream>

using namespace std;

bool isSorted(int*arr,int n){
    if(n==0){
        return true;
    }
    if(arr[n-1]<=arr[n-2])
        return false;
    else
        isSorted(arr,n-1);
    return true;
}

int main(){
    int arr[]={24,33,46,145,257,899,900,911,920,720};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<isSorted(arr,n);
    return 0;
}