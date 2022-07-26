#include<iostream>
#include<bits/stdc++.h>

using namespace std;



void solve(string digits,string output,vector<string>& ans,int i ,vector<string>map){
    if(i==digits.size()){
        ans.push_back(output);
        return;
    }
    int number=digits[i]-'0';
    string value=map[number];

    for(int j=0;j<value.size();j++){
        output.push_back(value[j]);
        solve(digits,output,ans,i+1,map);
        output.pop_back();
    }
}


vector<string> letterCombinations(string digits){
    vector<string>ans;
    vector<string> map={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    string output="";
    solve(digits,output,ans,0,map);
    return ans;
}



int main(){
    string digits="23";
    vector<string>ans=letterCombinations(digits);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}