#include <iostream>
#include <vector>
using namespace std;

void solve(int col, vector<string> &board, vector<vector<string>> &ans, vector<int> &leftRow, vector<int> &lowerDiagonal, vector<int> &upperDiagonal, int n, int column){
    if (col == n){
        ans.push_back(board);
        return;
    }
    if (col == column) solve(col+1,board,ans,leftRow,lowerDiagonal,upperDiagonal,n,column);
    
    for (int row = 0; row < n; row++){
        if (leftRow[row] == 0 && upperDiagonal[row+col] == 0 && lowerDiagonal[n-1+col-row] == 0){
            board[row][col] = 'Q';
            leftRow[row] = 1;
            upperDiagonal[row+col] = 1;
            lowerDiagonal[n-1+col-row] = 1;
            solve(col+1,board,ans,leftRow,lowerDiagonal,upperDiagonal,n,column);
            board[row][col] = '.';
            leftRow[row] = 0;
            upperDiagonal[row+col] = 0;
            lowerDiagonal[n-1+col-row] = 0;
        }
    }
}

int main()
{
    int n;
    cout << "Enter n: "; cin >> n;
    vector<string> board(n);
    string s(n,'.');
    for (int i = 0; i < n; i++) board[i] = s;
    vector<vector<string>> ans;
    vector<int> leftRow(n,0), lowerDiagonal(2*n-1,0), upperDiagonal(2*n-1,0);
    board[1][0] = 'Q'; leftRow[1] = 1; upperDiagonal[1] = 1; lowerDiagonal[n-2] = 1;
    solve(0,board,ans,leftRow,lowerDiagonal,upperDiagonal,n,0);
    
    for (auto it: ans){
        for (int i = 0; i < n; i++){
            cout << it[i] << endl;
        }
        cout << endl << endl;
    }
    return 0;
}


/*
#include <bits/stdc++.h>
using namespace std;

bool isSafe(int row, int col, vector<string> &board, int n){
    int i = row, j = col;
    
    for (int k = 0; k < n; k++){
        if (board[row][k] == 'Q') return false;
    }
    
    while (i >= 0 && j >= 0){
        if (board[i][j] == 'Q') return false;
        i--;j--;
    }
    
    i = row; j = col;
    while (i < n && j >= 0){
        if (board[i][j] == 'Q') return false;
        i++;j--;
    }
    
    return true;
}

void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n){
    if (col == n){
        ans.push_back(board);
        return;
    }
    
    for (int row = 0; row < n; row++){
        if (isSafe(row,col,board,n)){
            board[row][col] = 'Q';
            solve(col+1,board,ans,n);
            board[row][col] = '.';
        }
    }
}

int main(){
    int n;
    cout << "Enter n: "; cin >> n;
    string s(n,'.');
    vector<string> board(n);
    for (int i = 0; i < n; i++) board[i] = s;
    vector<vector<string>> ans;
    solve(0,board,ans,n);
    
    for (auto it: ans){
        for (int i = 0; i < n; i++){
            cout << it[i] << endl;
        }
        cout << endl << endl;
    }
    return 0;
}
 */