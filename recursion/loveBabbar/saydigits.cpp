#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string digit[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
void sayDigit(int n){
    if(n==0)return;
    sayDigit(n/10);
    cout<<digit[n%10]<<" ";
}
int main(){
    sayDigit(426);
    return 0;
}