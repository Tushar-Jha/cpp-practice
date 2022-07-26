#include<iostream>

using namespace std;

void counting(int n){
    if(n==1){
        cout<<n;
        return;
    }
    cout<<n<<" ";
    counting(n-1);
}

int main(){
    counting(5);
    return 0;
}