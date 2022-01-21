// https://www.interviewbit.com/problems/balance-array/

#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &A) {
    /*
    
    if we want to iterate over the deleted element 
    then we need to know the sum of elements at even and odd
    position
    Now, if we delete the current element then 
    on the left of deleted element i,
        even element will remain even and odd will remain odd
    but on the right of deleted element i,
        even => odd and odd=> even
    
    */
    // create two array to calculate the prefix sum
    const int N=A.size();
    vector<int> prefixE(N), prefixO(N);
    vector<int> suffixE(N), suffixO(N);

    for(int i=1;i<N;++i){
        // because we don't want to include the current number 
    
        if((i-1)%2==0){    // if previous number is even 
            prefixE[i] = prefixE[i-1]+A[i-1];
            prefixO[i] = prefixO[i-1];
        }
        else{   // if previous number is odd 
            prefixO[i] = prefixO[i-1]+A[i-1];
            prefixE[i] = prefixE[i-1];
        }
    }

    for(int i=N-2;i>=0;--i){
        // on the right side of current number 
        // the position of number will swap "even <=> odd"

        if((i)%2==0){    // if current number is even 
            suffixE[i] = suffixE[i+1]+A[i+1];
            suffixO[i] = suffixO[i+1];
        }
        else{   // if current number is odd 
            suffixO[i] = suffixO[i+1]+A[i+1];
            suffixE[i] = suffixE[i+1];
        }

    }

    int res=0;
    for(int i=0;i<N;++i){
        if(prefixE[i]+suffixE[i]==prefixO[i]+suffixO[i])
            res++;
    }

    return res;
}