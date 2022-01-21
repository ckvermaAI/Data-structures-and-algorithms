// https://www.interviewbit.com/problems/trailing-zeroes/

#include <bits/stdc++.h>
using namespace std;

int solve(int A) {
    // start from least significant bit
    // count number of zeros until we encounter "1"
    int count =0;
    for(int i=0;i<=30;++i){
        if(A & (1<<i))  break;
        else{
            count++;
        }
    }
    return count;
}
