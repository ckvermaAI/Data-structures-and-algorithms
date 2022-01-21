// https://www.interviewbit.com/problems/sum-of-pairwise-hamming-distance/

#include <bits/stdc++.h>
using namespace std;

int hammingDistance(const vector<int> &A) {
    const int N=A.size(),  MOD = 1'000'000'007;;
    int res=0;
    for(int bit=0;bit<31;++bit){
        int ones=0;
        for(int i=0;i<N;++i){
            if( (1<<bit) & A[i]){
                ones++;
            }
        }
        res += ((2LL * ones * (N-ones)) % MOD);
        if(res>=MOD)    res-=MOD;
    }
    return res;
}
