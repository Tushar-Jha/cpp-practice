#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void superset(vector<int>&nums,int i,vector<int>op,vector<vector<int>>& output){
    if(i==nums.size()){
        output.push_back(op);
        return;
    }
    superset(nums,i+1,op,output);
    op.push_back(nums[i]);
    superset(nums,i+1,op,output);
}

vector<vector<int>> subsets(vector<int>& nums){
    vector<int>op;
    vector<vector<int>>result;
    superset(nums,0,op,result);
    return result;
}

int main(){
    vector<int>nums={1,2,3};
    vector<vector<int>>res;
    res=subsets(nums);
    for(int i=0;i<res.size();i++){
        cout<<endl;
        for(int j=0;j<res[i].size();j++){
            cout<<res[i][j]<<" ";
        }
    }
    return 0;
}