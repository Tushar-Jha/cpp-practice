#include<iostream>
#include<math.h>
#include<bits/stdc++.h>

using namespace std;

double morePrecision(int n,int precision,int tempSol){
    double factor=1;
    double ans=tempSol;

    for(int i=0;i<precision;i++){
        factor/=10;
        for(double j=ans;j*j<n;j=j+factor){
            ans=j;
        }
    }
    return ans;
}

int squareRoot(int n){
    int s=0,e=n-1,ans=-1;
    while(s<=e){
        int m=s+(e-s)/2;
        if(pow(m,2)==n)
            return m;
        else if(pow(m,2)>n)
            e=m-1;
        else{
            s=m+1;
            ans=m;
        }
    }
    return ans;
}

int main(){
    int temp=squareRoot(37);
    cout<<morePrecision(37,3,temp);
    return 0;
}