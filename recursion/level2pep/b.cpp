//maximum score

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int solve(vector<string> strVec, vector<int>farr,vector<int>score, int i)
{
    if (i == strVec.size())
    {
        return 0;
    }
    //not including
    int notAdded=solve(strVec, farr,score, i + 1);
    //including
    int sword=0;
    bool canAdd=true;
    //to check if the string can be added to the subset or not
    for(int j=0;j<strVec[i].length();j++){
        if(farr[strVec[i][j]-'a']==0){
            canAdd=false;
        }
        farr[strVec[i][j]-'a']--;
        sword+=score[strVec[i][j]-'a'];
    }
    int added=0;
    if(canAdd){
        added=sword+solve(strVec,farr,score,i+1);
    }
    //backtracking step;
    for(int j=0;j<strVec[i].length();j++){
        farr[strVec[i][j]-'a']++;
    }
    return max(added,notAdded);
}


int main()
{
    vector<string> strVec={"dog","cat","good","dad"};   
    vector<int>score={1,0,9,5,0,0,3,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0};
    vector<int>farr={1,1,1,3,0,0,1,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0};
    int ans=solve(strVec,farr,score,0);
    cout<<ans;
    return 0;
}