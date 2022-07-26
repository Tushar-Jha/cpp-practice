#include<iostream>
#include<bits/stdc++.h>

using namespace std;


void solve(vector<int>nums,vector<vector<int>>&res,int i){
    if(i==nums.size()){
        res.push_back(nums);
    }
    for(int j=i;j<nums.size();j++){
        swap(nums[i],nums[j]);
        solve(nums,res,i+1);
        swap(nums[i],nums[j]);
    }
}
vector<vector<int>>permute(vector<int>&nums){
    vector<vector<int>>solution;
    solve(nums,solution,0);
    return solution;
}



int main(){
    vector<int>nums={1,2,3,4};
    vector<vector<int>>res;
    res=permute(nums);
    for(int i=0;i<res.size();i++){
        cout<<endl;
        for(int j=0;j<res[i].size();j++){
            cout<< res[i][j] <<" ";
        }
    }
    return 0;
}