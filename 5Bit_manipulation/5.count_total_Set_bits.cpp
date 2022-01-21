// https://www.interviewbit.com/problems/count-total-set-bits/

#include <bits/stdc++.h>
using namespace std;

/*

BRUTE FORCE APPROACH =>
Iterate through all the numbers (from 0 to A) and count 
all the bits which are 1

Time complexity = O(A* 32 (==bits)) = O(A*log(A))


FAST SOLUTION =>

000 =   0
001 =   1
010 =   2
011 =   3
100 =   4
101 =   5
110 =   6

starting from zero we can see that there is pattern in a way that
1) for last bit(least significant bit), bits flipped after 2^0 number
2) for third last bit, bits flipped after 2^2 number

So, for the ith bit starting from least significant bit the window of size
2^(i+1) appear which contains 2^i zeros then 2^i ones and this pattern continue

If we use this idea to find the answer then the Timecomplexity = O(bits) = O(log(A))

*/


int solve(int A) {
    // Base case
    if(A<=1)    return A;

    const int MOD = 1e9+7;
    int nBit=0;
    // find the Most significant bit which is active
    for(int i=30;i>=0;--i){
        if(A & (1<<i)){
            nBit = i;
            break;
        }
    }

    int total_bits=0;
    // Iterate through all the bits
    for(int i=nBit;i>=0;--i){
        int windowSize = (1<<(i+1));
        
        // How many times this window appear for number [0,A]
        long long int freq = (A+1)/windowSize;

        total_bits = (total_bits + (freq*(windowSize/2)%MOD)%MOD) %MOD;

        // It may happens that a partial window exist in last
        long long remain = (A+1)%windowSize;
        if(remain>windowSize/2){
            total_bits = (total_bits + (remain-windowSize/2)%MOD) %MOD;
        }


    }
    return total_bits;
}

