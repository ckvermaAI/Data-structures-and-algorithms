#include <bits/stdc++.h>
using namespace std;

// https://www.interviewbit.com/problems/single-number/

int singleNumber(const vector<int> &A) {
    // Property of XOR
    // XOR of N^N = 0
    int res = 0;
    for(int i=0;i<A.size();++i){
        res ^= A[i];
    }
    return res;
}


int main(){


    return 0;
}