// https://www.interviewbit.com/problems/sudoku/

#include <bits/stdc++.h>
using namespace std;


bool check(int i,int j,int n,vector<vector<char> > &a,int k){
    // {i, j} = {row, col} and k = value filled at that position

    for(int c = 0;c<n;c++){
        if(a[c][j] == k+'0' || a[i][c] == k+'0') return false; 
    }

    // check the box 3X3
    int x3 = sqrt(n);
    int x1 = i-i%x3,x2 = j-j%x3;
    for(int c1 = 0;c1<x3;c1++){
        for(int c2 = 0;c2<x3;c2++){
            if(a[c1+x1][c2+x2] == k+'0')return false; 
        }
    }
    return true;
}


 bool sol(vector<vector<char>> &a,int n,int i,int j){
    //  Base case
    if(i == n-1 && j==n)
        return true;

    // if we hit the last column
    // move to next row
    if(j==n){
        i++; j=0;
    }

    // if current place is filled
    if(a[i][j] != '.')
        return sol(a,n,i,j+1);
    
    // otherwise fill the current place
    // we have 9 possibilities at each place
    for(int k = 1;k<=9;k++){

        if(check(i,j,n,a,k)){
            a[i][j] = k+'0';
            if(sol(a,n,i,j+1)) return true;
            a[i][j] = '.';
        } 
        
    }  

    return false;    
}

void solveSudoku(vector<vector<char> > &a) {
    int n = a.size();
    sol(a,n,0,0);
}


