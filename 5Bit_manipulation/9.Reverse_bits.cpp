// https://www.interviewbit.com/problems/reverse-bits/

#include <bits/stdc++.h>
using namespace std;

unsigned int reverse(unsigned int A) {
    // start from most significant digit
    // and update the num least significant digit
    unsigned int num=0;
    for(int i=31;i>=0;--i){
        if(A & (1<<i)){
            // If this bit is active in current num
            // update the corresponding bit in "num"
            num += (1<<(31-i));
        }
    }
    return num;
}
