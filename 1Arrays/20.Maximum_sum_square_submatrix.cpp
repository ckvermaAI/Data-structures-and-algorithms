// https://www.interviewbit.com/problems/maximum-sum-square-submatrix/
#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<int> > &A, int B) {
    /*
    
    Brute Force approach =>
    Simply iterate the all possible N-B+1 matrices 
    of size B x B 
    Time complexity will be  O( (N-B+1)*(B*B) )

    But there is some duplicated work, we do not need 
    calculate the sum of each submatrix from scratch
    we can use previous calculated sum to calculate 
    the sum of next sub-matrix

    Another Approach
    1) But in that case also we need to iterate thorugh all
    the submatrices and 
    2) use the previous sum, add the latest row/columns and 
    subtract the rows/columns which is not present in current
    sub-matrix.
    Time Complexity O(B^3)

    Optimized solution =>
    1. first compress the rows "ROWS" => "B"            
    2. After that compress the columns "COLS" => B
    Time complexity O(B^2)

    */
    int N=A.size();
    int M=N-B+1;
    vector <vector <int>> vertical(M,vector<int>(N));
    for(int col=0;col<N;++col){
        int sum=0;
        for(int row=0;row<B;++row){
            sum+=A[row][col];
        }
        vertical[0][col]=sum;
    }
    for(int row=1;row<M;++row){
        for(int col=0;col<N;++col){
            vertical[row][col]=vertical[row-1][col]+A[row+B-1][col]-A[row-1][col];
        }
    }
    int result=INT_MIN;
    vector <vector <int>> horizontal(M,vector<int>(M));
    for(int row=0;row<M;++row){
        int sum_=0;
        for(int col=0;col<B;++col){
            sum_+=vertical[row][col];
        }
        horizontal[row][0]=sum_;
        result=max(result,sum_);
    }
    for(int col=1;col<M;++col){
        for(int row=0;row<M;++row){
            horizontal[row][col]=horizontal[row][col-1]+vertical[row][B-1+col]-vertical[row][col-1];
            result=max(result, horizontal[row][col]);
        }
    }
    return result;

}
