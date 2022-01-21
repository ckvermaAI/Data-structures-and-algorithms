// https://www.interviewbit.com/problems/vowel-and-consonant-substrings/

#include <bits/stdc++.h>
using namespace std;


int solve(string A) {
    /*
    BruteForce Approach => Generate all substring and check
    whether it starts with vowel and ene with consonants or
    vice-versa
    Time - Complexity = O(N^2)

    
    Optimised approach => We do not want the all of the sub-string
    we only want start and end points of a substring.

    If we find out how many vowels and consonants are there on right
    of the current character we can find out how many such special
    string can be formed with current element as starting element

    Algorithm =>
    compute the total number of vowels and consonant and each step
    decrease the count
    and we are left with number of vowels or consonant on right

    */
    const int N = A.length(), MOD = 1e9+7;
    int vowels = 0 , consonants = 0;
    for(char &x:A){
        if(x=='a' or x=='e' or x=='i' or x=='o' or x=='u'){
            vowels++;
        }
        else    consonants++;
    }

    int ans= 0;
    for(char &x:A){
        if(x=='a' or x=='e' or x=='i' or x=='o' or x=='u'){
            vowels--;
            ans = (ans + consonants)%MOD;
        }
        else{
            consonants--;
            ans = (ans + vowels)%MOD;
        }    
    }

    return ans;
    
}
