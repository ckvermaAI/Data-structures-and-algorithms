// https://www.interviewbit.com/problems/modular-expression/

#include <bits/stdc++.h>
using namespace std;


int powMod(int base, int exponent, int MOD){
    // base case
    if(base==0)     return base;

    long long int ans=1;
    long long int y = base;

    while(exponent){
        if(exponent & 1){
            ans = (ans*y)%MOD;
        }
        y = (y*y)%MOD;
        exponent>>=1;
    }
    if(ans>=0)  return ans;
    else    return ans+MOD;

}


int Mod(int A, int B, int C) {
    return powMod(A, B, C);
}
