#include<iostream>
#include<bits/stdc++.h>

using namespace std;

vector<string> solve(string small, vector<string> words){

    vector<string>op;
    for(int i=0;i<words.size();i++){
        bool conatains=true;
        for(int j=0;j<small.size();j++){
            if(small[j]!=words[i][j]){
                conatains=false;
                break;
            }
        }
        if(conatains==true){
            op.push_back(words[i]);
        }
    }

    return op;
}

int main(){

    vector<string>words={"abcde","acdeb","abfgsjd","aaaa","ashdueb","abababa","abtudhd"};
    string small ="ab";

    vector<string> op= solve(small,words);
    for( int i=0;i<op.size();i++){
        cout<<op[i]<<" ";
    }

    return 0;
}