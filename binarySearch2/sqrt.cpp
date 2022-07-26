#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int squareRoot(int N){
    if(N<=1)
    return N;
    int start=1;
    int end;
    if(N%2==0){
        end=N/2;
    }else{
        end=(N/2)+1;
    }
    int ans=INT_MIN;
    while(start<=end){
        int mid=start+(end-start)/2;
        if(mid*mid==N){
            return mid;
        }
        else if(mid*mid>N){
            end=mid-1;
        }
        else if(mid*mid<N) {
            if(mid>ans){
                ans=mid;
            }
            start=mid+1;
        }
    }
    return ans;
}


int main(){

    for(int i=0;i<=100;i++){
        cout<<i<<" --> "<<squareRoot(i)<<endl;
    }
    return 0;
}