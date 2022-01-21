// https://www.interviewbit.com/problems/number-of-1-bits/

#include <bits/stdc++.h>
using namespace std;


int numSetBits(unsigned int A) {
    // Iterate through all the
    // bits of unsigned integer
    int ones=0;
    for(int i=31;i>=0;--i){
        if(A & (1<<i)){
            ones++;
        }
    }
    return ones;
}

int numSetBits(unsigned int A) {
    // function that return 
    // the number of 1 in binary rep.
    // of integer

    return __builtin_popcount(A);
}
