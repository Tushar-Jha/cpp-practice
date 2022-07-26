#include<iostream>

using namespace std;

int binarySearch(int* arr,int l,int r,int key){
    if(l>r)return -1;
    int m=l+(r-l/2);
    if(arr[m]==key)
        return m;
    else if(arr[m]>key)
        binarySearch(arr,l,m-1,key);
    else 
        binarySearch(arr,m+1,r,key);
}

int main(){
    int arr[]={21,24,36,38,90,102,354,412,499,513,588,699,799,899,999};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<binarySearch(arr,0,n-1,36);
    return 0;
}