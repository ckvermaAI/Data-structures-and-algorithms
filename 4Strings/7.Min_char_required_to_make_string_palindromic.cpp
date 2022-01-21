// https://www.interviewbit.com/problems/minimum-characters-required-to-make-a-string-palindromic/

#include <bits/stdc++.h>
using namespace std;

int solve(string A) {
    /*
    In problems related to palindrome always check 
    what happens when we also use the reversed string

    In this problem also, 
    we have to insert the characters in the left(or Begining)
    of the string, now we have to extract the part of string
    which is not palindrome (then we can easily add the elements
    on the left to make it palindrome
    
    */
    // store the original string
    string original = A;
    
    // reverse the current string
    reverse(A.begin(), A.end());

    // modifiy the string A
    // This order of appending the strings matters
    // Because current appending "original then A"
    // indicates that all the character are matched and unmatched
    // characters can be inserted at begining of original string
    A = original+"$"+A;

    // find the prefix array
    vector<int> prefix(A.size());
    int border=0;
    prefix[0] = border;

    // compute the prefix array
    for(int i=1;i<A.size();++i){
        while(border>0 and A[border]!=A[i]){
            border = prefix[border-1];
        }
        if(A[i]==A[border]){
            border++;
        }
        else border=0;
        
        prefix[i] = border;
    }

    return original.size()-prefix.back();
}
