// https://www.interviewbit.com/problems/reverse-integer/

#include <bits/stdc++.h>
using namespace std;

int reverse(int A) {
    // store the sign of integer
    int sign = ((A<0)?-1:1);

    long long int B = A;
    // remove the negative sign if it is there
    B = sign*A;

    // extract the digits of the number
    vector<int> digits;
    while(B){
        digits.push_back(B%10);
        B /= 10;
    }

    long long int res = 0;
    for(int i=digits.size()-1;i>=0;--i){
        res += ( digits[i]*pow(10, digits.size()-1-i) );
    }
    res = sign*res;
    if(res>INT_MAX or res<INT_MIN){
        return 0;
    }
    return res;
}
