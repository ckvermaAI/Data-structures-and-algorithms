// https://www.interviewbit.com/problems/largest-coprime-divisor/

#include <bits/stdc++.h>
using namespace std;


int gcd(int A, int B){
    while(B){
        int rem = A%B;
        A = B;
        B = rem;
    }
    return A;
}

int cpFact(int A, int B) {
    int X = A;
    // iterate through all possible X starting from A -> 1
    while(true){
        int gcd_ = gcd(X, B);
        if(A%X==0 and gcd_==1){
            // If this condition satisfy 
            // then return X
            return X;
        }
        // Otherwise remove the common factor
        // because that will only ensure that GCD is 1
        X /= gcd_;
    }
}
