// https://www.interviewbit.com/problems/length-of-last-word/

#include <bits/stdc++.h>
using namespace std;

int lengthOfLastWord(const string A) {
    /*

    so the greedy solution will be to iterate through the 
    string from backwards
    and track the first alphabet - which will be the end point of last word
    and continue till we hit a empty space or end of string
    this index will indicate the - start of last word

    Time complexity = O(N)
    Space complexity = O(1)

    */

    const int N = A.length();
    // initially the indices point to null values
    int low=-1, high=-1;    

    // find the end of string
    for(int i=N-1;i>=0;--i){
        if(A[i]!=' '){
            high=i;
            break;
        }
    }
    
    // if there is no word in string
    if(high==-1)    return 0;
    
    // find the starting point of string
    for(int i=high-1;i>=0;--i){
        if(A[i]==' '){
            low = i+1;
            break;
        }
    }

    if(low==-1)     low=0;


    // Otherwise
    return (high-low+1);
}
