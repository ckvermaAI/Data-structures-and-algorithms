// https://www.interviewbit.com/problems/3-sum/

#include <bits/stdc++.h>
using namespace std;

int nTriang(vector<int> &A) {

    // this is similar to finding the 
    // two element A[j]-A[i]=target
    // but here instead of two we have three elements
    // A[i]+A[j]-A[k]>0 where A[i]<=A[j]<=A[k]
    // Once we fixed the ith element we left with 
    // first problem mentioned above

    // Time complexity = O(N^2)

    typedef long long int lld;
    const int N = A.size(), MOD = 1e9+7;
    sort(A.begin(), A.end());

    int res=0;
    for(int i=0;i<N;++i){
        int k=i+2;
        for(int j=i+1;j<N;++j){
            for(;k<N;++k){

                // A[i]<=A[j]<=A[k]
                lld temp = (lld)A[i]+A[j]-A[k];

                if(j!=k and temp>0){
                    // Maximum number of triangle using this 
                    // particular side "k"
                    res = (res%MOD + (k-j)%MOD)%MOD;
                }
                if(temp<=0){
                    // k will increase hence 
                    // temp will decrease
                    break;
                }
            }
        }
    }
    return res;
}
