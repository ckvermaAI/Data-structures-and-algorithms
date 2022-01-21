// https://www.interviewbit.com/problems/rotate-matrix/

#include <bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int> > &A) {
    /* 
    
    Approach 1 =>
        There are four directions in the array top, right, bottom and left
        swap these 4 elements 

    Approach 2 =>
        First take transpose -> reverse each row
        that will result in 

    */

    // Approach2
    const int ROWS =A.size(), COLS = A[0].size();
    // Transpose the matrix
    for(int i=0;i<ROWS;++i){
        for(int j=i;j<COLS;++j){
            swap(A[i][j], A[j][i]);
        }
    }

    // reverse each ROW
    for(int i=0;i<ROWS;++i){
        reverse(A[i].begin(), A[i].end());
    }
    
    
}