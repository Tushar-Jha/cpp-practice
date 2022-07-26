#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<string> digtis{"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

void saydigits(int n){
    if(n<10){
        cout<<digtis[n]<<" ";
        return;
    }
    saydigits(n/10);
    cout<<digtis[n%10]<<" ";
}

int main()
{
    int n=1257564312;
    saydigits(n);
    return 0;
}