// https://www.interviewbit.com/problems/perfect-peak-of-array/

#include <bits/stdc++.h>
using namespace std;


int perfectPeak(vector<int> &A) {
    const int N=A.size();
    vector<int> prefix(N), suffix(N, INT_MAX);
    
    for(int i=1;i<N;++i){
        prefix[i] = max(prefix[i-1], A[i-1]);
    }

    for(int i=N-2;i>=0;--i){
        suffix[i] = min(suffix[i+1], A[i+1]);
    }

    for(int i=1;i<N-1;++i){
        if(A[i]>prefix[i] and A[i]<suffix[i]){
            return 1;
        }
    }
    return 0;
}
