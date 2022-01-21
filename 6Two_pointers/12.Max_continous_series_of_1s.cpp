// https://www.interviewbit.com/problems/max-continuous-series-of-1s/

#include <bits/stdc++.h>
using namespace std;

vector<int> Solution::maxone(vector<int> &A, int B) {
    const int N=A.size();
    // to store the latest answer
    int start_index=0, len=0;
    
    // keep track of ones in subarrays
    int ones=0;
    
    // use two pointers 
    int j=0;
    for(int i=0;i<N;++i){
        ones += A[i];
        for(;j<N;++j){
            int zeros = (i-j+1) - ones;
            if(zeros<=B)    break;
            else    ones-=A[j];
        }
        if(len<(i-j+1)){
            len = i-j+1;
            start_index= j;
        }
    }

    vector<int> res(len);
    for(int i=0;i<len;++i){
        res[i] = start_index+i;
    }

    return res;
}