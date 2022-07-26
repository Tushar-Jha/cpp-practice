#include<iostream>
#include<bits/stdc++.h>
#define N 5
using namespace std;

bool isSafe(int board[][N],int row,int col){
    //column
    for(int i=0;i<row;i++){
        if(board[i][col]==1){
            return false;
        }
    }

    //hill diagnol
    for(int i=row,j=col;i>0,j<N;i--,j++){
        if(board[i][j]==1){
            return false;
        }
    }

    //dale diagnol
    for(int i=row,j=col;i>0,j>0;i--,j--){
        if(board[i][j]==1){
            return false;
        }
    }

    return true;
}

bool solve(int board[][N],int r){
    if(r==N){
        for(int i=0;i<N;i++){
            cout<<endl;
            for(int j=0;j<N;j++)
                cout<<board[i][j]<<" ";
        }
        return true;
    }
    for(int j=0;j<N;j++){
        if(isSafe(board,r,j)){
            board[r][j]=1;
            if(solve(board,r+1)){
                return true;
            }
            board[r][j]=0;
        }
    }
    return false;
}

// int nqueen(int N){
//     int board[][N]={0};
//     solve(board,N,0);
//     return 1;
// }

int main(){
    int board[N][N]={0};
    bool solution=solve(board,0);
    return 0;
}