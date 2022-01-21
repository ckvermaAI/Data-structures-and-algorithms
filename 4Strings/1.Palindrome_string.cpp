// https://www.interviewbit.com/problems/palindrome-string/

#include <bits/stdc++.h>
using namespace std;


bool isValid(char c){
    // return whether a character is alphanumeric
    if((c>='A' and c<='Z') or (c>='a' and c<='z') or (c>='0' and c<='9') ){
        return true;
    }
    return false;
}

string cleanString(string &A){
    transform(A.begin(), A.end(), A.begin(), ::toupper);
    string B = "";
    for(char &x:A){
        if(isValid(x)){
            B += x;
        }
    }
    return B;
}

int isPalindrome(string A) {
    // start iterating through the elements of array
    A = cleanString(A);
    const int N = A.length();
    for(int i=0;i<N/2;++i){
        if(A[i]!=A[N-i-1]){
            return 0;
        }
    }
    return 1;
}