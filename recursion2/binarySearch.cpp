#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool binarySearch(int s, int e, int* arr, int key)
{
    if (s > e)
    {
        return false;
    }
    int mid = (s+e)/2;
    if (arr[mid] == key)
    {
        return true;
    }
    else if (arr[mid] < key)
    {
        return binarySearch(mid + 1, e, arr, key);
    }
    else
    {
        return binarySearch(s,mid-1,arr,key);
    }
}

int main()
{
    int arr[]={};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<binarySearch(0,n-1,arr,900);
    return 0;
}