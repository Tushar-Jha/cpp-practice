#include<iostream>
#include<bits/stdc++.h>

using namespace std;

//to lower case
char tlc(char ch){
    if((ch>='a'&& ch<='z')||(ch>='0'&& ch<='9'))
        return ch;
    else if(ch>='A'&& ch<='Z') {
        char temp=ch+'a'-'A';
        return temp;    
    }
}

bool isPalindrome(string s) {
    int i=0;
    for(int j=0;j<s.length();j++){
        if((s[j]>='a'&& s[j]<='z')||(s[j]>='A'&& s[j]<='Z')||(s[j]>='0'&& s[j]<='9')){
            swap(s[i],s[j]);
            i++;
        }
    }
    cout<<s;
    for(int n=0;n<=i/2;n++){
        if(tlc(s[n])!=tlc(s[i-n-1])){
            return false;
        }
    }
    return true;        
}

int main(){
    string a="A man, a plan, a canal: Panama";
    cout<< isPalindrome(a);
    return 0;
}