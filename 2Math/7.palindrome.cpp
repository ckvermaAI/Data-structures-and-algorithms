// https://www.interviewbit.com/problems/palindrome-integer/

#include <bits/stdc++.h>
using namespace std;

int isPalindrome(int A) {
    if(A<0) return 0;
    vector<int> digits;
    while(A){
        digits.push_back(A%10);
        A/=10;
    }

    int N= digits.size();
    if(N==1)    return 1;

    for(int i=0;i<N/2;++i){
        if(digits[i]!=digits[N-i-1])
            return 0;
    }
    return 1;
}

