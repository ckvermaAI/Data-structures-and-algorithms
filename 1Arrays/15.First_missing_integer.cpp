// https://www.interviewbit.com/problems/first-missing-integer/

#include <bits/stdc++.h>
using namespace std;

int firstMissingPositive(vector<int> &A) {
    /*
    
    Brute Force approach =>
        1) Sort the array
        2) start iterating through the array
        3) find the first missing positive integer
        Time Complexity O(N*log(N))   
    
    Another approach =>
        As the size of the array is N, hence
        we do not want to consider the elements A[i]<=0 and A[i]>N
        
        The answer will be N+1 only if all of the elements of the array 
        are exact one occurence [1, N]

        If using extra space was an option, creating buckets would have 
        been an easy solution
        Creating an array of size N initilized 0, for every value A[i] which
        lies in range [1, N] we would have incremented its count in the array.
        Consequently, we would traverse the array to find the first array 
        position with value 0

        do this in place
    */
    const int N=A.size();
    for(int i=0;i<N;++i){
        if(A[i]>0 and A[i]<=N){
            int pos = A[i]-1;
            if(A[i]!=A[pos]){
                swap(A[i], A[pos]);
                i--;
            }
        }
    }

    for(int i=0;i<N;++i){
        if(A[i]!=i+1){
            return i+1;
        }
    }

    return N+1;
}

