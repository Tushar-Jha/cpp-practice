#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int length(char str[]){
    int len=0;
    for(int i=0;str[i]!='\0';i++){
        len++;
    }
    return len;
}

void reverseStr(char *str,int n){
    int s=0;
    int e=n-1;
    while(s<=e){
        swap(str[s++],str[e--]);
    }
}

bool checkPal(char* str,int n){
    bool pal=true;
    for(int i=0;i<n/2;i++){
        if(str[i]!=str[n-1-i]){
            pal=false;
            break;
        }
    }
    return pal;
}

int main(){
    char str[20];
    cout<<"Enter string "<<endl;
    cin>> str;
    cout<<"Length is "<<length(str);
    int len=length(str);
    cout<<endl;
    reverseStr(str,len);
    cout<<str<<endl;
    cout<<checkPal(str,len);
    return 0;
}