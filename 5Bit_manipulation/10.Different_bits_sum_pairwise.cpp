// https://www.interviewbit.com/problems/different-bits-sum-pairwise/

#include <bits/stdc++.h>
using namespace std;

int cntBits(vector<int> &A) {
    // for each bit of all numbers 
    // if we found the number of ones 
    // and zero then the total number of 
    // pair having different bits is (zeros*ones)
    const int MOD = 1e9+7;
    long long int res = 0;
    
    for(int bit=30;bit>=0;--bit){
        int ones = 0;
        for(int i=0;i<A.size();++i){
            if(A[i] & (1<<bit)){
                ones++;
            }
        }
        res = (res + ((long long int)ones*(A.size()-ones))%MOD)%MOD;
    }
    return (2*res)%MOD;
}