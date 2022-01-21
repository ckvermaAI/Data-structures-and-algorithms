// https://www.interviewbit.com/problems/add-one-to-number/

#include <bits/stdc++.h>
using namespace std;

vector<int> plusOne(vector<int> &A) {
    // trim the first zeros
    // to do this basically find out the first non-zero number
    const int N = A.size();
    int startIndex =0;
    for(int i=0;i<N;++i){       // starting from the most significant digit 
        if(A[i]!=0){            // find out the first non-zero digit
            startIndex = i;
            break;
        }
    }
    
    // Just simply add one the last digit
    // and propagate the carry towards the most significant digit
    int currentValue = A[N-1] + 1;
    A[N-1] = currentValue%10;
    int carry = currentValue/10;
    
    for(int i=N-2;i>=startIndex and carry;--i){
        currentValue = A[i] + carry;
        A[i] = currentValue%10;
        carry = currentValue/10;
    }

    if(carry){      // carry can only be of 1 digit 
        A.insert(A.begin()+startIndex, carry);
    }

    return vector<int>(A.begin()+startIndex, A.end());
}

