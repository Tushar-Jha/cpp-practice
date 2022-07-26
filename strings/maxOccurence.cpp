#include<iostream>
#include<bits/stdc++.h>

using namespace std;

char maxOccurence(string s){
    int occ[26]={0};

    for(int i=0;i<s.length();i++){
        if(s[i]>='a'&&s[i]<='z'){
            occ[s[i]-'a']++;
        }else{
            occ[s[i]-'A']++;
        }
    }

    int maxIn=0;
    for(int i=0;i<26;i++){
        if(occ[i]>occ[maxIn]){
            maxIn=i;
        }
    }
    char ch='a'+maxIn;
    return ch;
}

int main(){
    string str="abcdABbefaguibbcdaddddddda";
    cout<<maxOccurence(str);
    return 0;
}