// https://www.interviewbit.com/problems/amazing-subarrays/

#include <bits/stdc++.h>
using namespace std;


int solve(string A) {
    // transform all the lowercase to uppercase letters
    transform(A.begin(), A.end(), A.begin(), ::toupper);
    const int N = A.length(), MOD = 10003;
    int res=0;

    for(int i=0;i<N;++i){
        if(A[i]=='A' or A[i]=='E' or A[i]=='I' or A[i]=='O' or A[i]=='U'){
            res = (res%MOD + (N-i)%MOD)%MOD;
        }
    }
    return res;
}
