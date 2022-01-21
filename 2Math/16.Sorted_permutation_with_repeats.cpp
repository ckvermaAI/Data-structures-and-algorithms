// https://www.interviewbit.com/problems/sorted-permutation-rank-with-repeats/

#include <bits/stdc++.h>
using namespace std;

void fillFact(vector<int> &A, const int &MOD){
    A[0]=1;
    A[1]=1;
    for(int i=2;i<A.size();++i){
        A[i] = (int)((long long int)i*A[i-1]%1000003);
    }
}

long long int powInv(long long int &a, int exp, const int &MOD){
    long long int ans = 1;
    while(exp){
        if(exp & 1)
            ans = (ans*a)%MOD;
        a = (a*a)%MOD;
        exp>>=1;
    }
    return ans;
}

int findRank(string A) {
    const int N = A.length(), MOD = 1000003;
    // precompute the factorials
    vector<int> factorial(N);
    fillFact(factorial, MOD);

    long long int ans = 1;
    for(int i=0;i<N;++i){
        
        // count the number of repetitions corresponding to each character
        // inclusive current
        vector<int> temp('z'-'A'+1);
        for(int j=i;j<N;++j){
            temp[A[j]-'A']++;
        }

        long long int divMul = 1;
        for(auto &x:temp){
            if(x>1){
                divMul = (divMul* factorial[x])%MOD;
            }
        }

        // calculate divisor inverse A^(-1) = A^(MOD-2);
        long long int divInv = powInv(divMul, MOD-2, MOD);

        // find out the number of elements greater than current 
        int count = 0;
        for(int j=i+1;j<N;++j){
            if(A[i]>A[j])   count++;
        }

        ans = ( ans +  (((count*factorial[N-i-1])%MOD)*divInv)%MOD )%MOD;
    }

    return ans%MOD;
}
