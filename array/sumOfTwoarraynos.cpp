#include<iostream>
#include<bits/stdc++.h>

using namespace std;

vector<int> add(vector<int>a,vector<int>b){
    vector<int>c(max(a.size(),b.size()));
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    
    int i=0;
    int carry=0;
    while(i<max(a.size(),b.size())){
        int temp=(i<a.size()?a[i]:0)+(i<b.size()?b[i]:0)+carry;
        if(temp>=10){
            carry=1;
            temp=temp%10;
        }else   
            carry=0;
        c[i]=temp;
        i++;
    }
    if(carry==1){
        c.push_back(1);
    }

    reverse(c.begin(),c.end());
    return c;
}

int main(){
    vector<int>a={7,6};
    vector<int>b={1,8,4};
    vector<int>res=add(a,b);
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
    return 0;
}