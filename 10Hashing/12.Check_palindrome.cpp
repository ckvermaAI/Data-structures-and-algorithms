// https://www.interviewbit.com/problems/check-palindrome/

#include <bits/stdc++.h>
using namespace std;

int solve(string A) {
    
    const int N = A.length();
    
    // to create palindrome each word 
    // should match with same 
    // so we have to count ocurrence of each word
    vector<int> words(26);

    for(int i=0;i<N;++i)    words[A[i]-'a']++;

    int odd_ocurrence=0;
    for(int i=0;i<26;++i){
        if(words[i]%2){
            // odd occurence 
            odd_ocurrence ++;
        }
    }

    // if length of string is odd
    // we can one word which is not matched to other string
    if(N%2 and odd_ocurrence==1){
        return 1;
    }

    // if zero odd occurence
    if(!odd_ocurrence){
        return 1;
    }

    return 0;

}
