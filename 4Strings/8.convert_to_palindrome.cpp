// https://www.interviewbit.com/problems/convert-to-palindrome/

#include <bits/stdc++.h>
using namespace std;

int solve(string A) {
    int N = A.size(), mismatch=0;
    int i=0, j = N-1;
    while(i<=j){
        if(A[i]==A[j]){
            i++;j--;
        }
        else{
            // If there is mismatch we have two options
            mismatch++;
            // skip the left char
            if(A[i+1]==A[j])    i++;
            // skip the right char
            else if(A[i]==A[j-1])   j--;
            // otherwise
            else return 0;
        }
    }
    // if mismatch ==1 then it is okay
    // if mismatch ==0 string is palindrome
    // and if we remove the character from palindrome it is still a palindrome
    return (mismatch<=1)?1:0;
}
