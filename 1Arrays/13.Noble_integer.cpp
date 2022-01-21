// https://www.interviewbit.com/problems/noble-integer/

#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &A) {
    /*
    
    Brute Force solution => For each element iterate through 
    all the elements and find the noble integer
    Time complexity = O(N^2)

    Use sorting to sort the element and element greater than current 
    will always will be on right
    Time complexity = O(N*log(N))
    
    */
        
    const int N=A.size();
    // sort the array
    sort(A.begin(), A.end());

    for(int i=0;i<N-1;++i){
        if(A[i+1]>A[i] and A[i]==N-i-1){
            // Next element is greater than current element
            // and number of elements greater than current element 
            return 1;
        }
    }
    if(A[N-1]==0){
        return 1;
    }

    return -1;
}