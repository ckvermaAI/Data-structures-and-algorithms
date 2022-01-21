// https://www.interviewbit.com/problems/maximum-absolute-difference/

#include <bits/stdc++.h>
using namespace std;

int maxArr(vector<int> &A) {
    /*
    
    Brute force approach will be to iterate through all the elements twice
    for each i iterate through all j 
    time comeplexity will be O(N^2)

    optimize way == simplify and generalize

    expand the expression and we can find out that we have 4 cases 
    
    */
    const int N=A.size();
    int maxSum = INT_MIN, minSum = INT_MAX;
    int maxDiff = INT_MIN, minDiff = INT_MAX;
    for(int i=0;i<N;++i){
        maxSum = max(maxSum, A[i]+i );
        minSum = min(minSum, A[i]+i );

        maxDiff = max(maxDiff, A[i]-i );
        minDiff = min(minDiff, A[i]-i );
    }

    return max({maxSum-minSum, maxDiff-minDiff});
}

