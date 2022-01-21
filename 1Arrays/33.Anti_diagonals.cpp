// https://www.interviewbit.com/problems/anti-diagonals/
#include <bits/stdc++.h>
using namespace std;


void foo(vector<vector<int>>&A, vector<vector<int>>&res, 
        int i, int j, const int &ROWS, const int &COLS){
    vector<int> temp;
    int x = i, y = j;
    while(x<ROWS and y>=0){
        temp.push_back(A[x][y]);
        x++; y--;
    }
    res.push_back(temp);
}

vector<vector<int>> diagonal(vector<vector<int> > &A) {
    const int ROWS = A.size(), COLS = A[0].size();
    // Iterate through all the elements of first row and last column
    vector<vector<int>> res;

    // Iterate through the first row
    for(int j=0;j<COLS;++j){
        foo(A, res, 0, j, ROWS, COLS);
    }

    // Iterate through last column
    for(int i=1;i<ROWS;++i){
        foo(A, res, i, COLS-1, ROWS, COLS);
    }


    return res;
}


