// https://www.interviewbit.com/problems/set-matrix-zeros/
#include <bits/stdc++.h>
using namespace std;

void setZeroes(vector<vector<int>> &A) {

    /*
    
    Best Run time possible =>
    To know where the zeros are present in the matrix
    we must need to traverse the array once 
    Therefore, the Best run time possible is O(N^2)
    
    Approach =>
    1) find the position corresponding to all zeros
        - position indicates the rows and columns which will be finally 
          full of zeros
    2) In other iteration, smartly iterate to cover all the points
       in some order.

    Time complexity = O(N^2)

    */

    const int N = A.size(), M = A[0].size();
    // Iterate through array to find out the ROWS and COLS we need to set zero
    vector<bool> ROWS(N, false), COLS(M, false);
    // if ROWS[i] or COLS[i] = True then set that element to zero

    for(int i=0;i<N;++i){
        for(int j=0;j<M;++j){
            if(A[i][j]==0){
                ROWS[i]=true;
                COLS[j]=true;
            }
        }
    }

    for(int i=0;i<N;++i){
        for(int j=0;j<M;++j){
            if(ROWS[i] or COLS[j]){
                A[i][j]=0;
            }
        }
    }

    
}