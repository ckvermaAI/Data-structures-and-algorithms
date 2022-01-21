// https://www.interviewbit.com/problems/longest-substring-without-repeat/

#include <bits/stdc++.h>
using namespace std;

// Solution is similiar to "19.window_string.cpp"

int lengthOfLongestSubstring(string A) {
    // to store the result
    int maxLen=0;

    // to store the char occurence in string A
    unordered_map<char,int> HashMap;

    // use two pointers to iterate through the array
    int start=0, end=0;

    // variable to keep track of repeated elements
    int counter=0;

    while(end<A.length()){

        HashMap[A[end]]++;

        // if repeated element
        if(HashMap[A[end]]>1)   counter++;

        end++;

        if(counter==0){
            maxLen = max(maxLen, end-start);
        }
        while(counter){
            if(HashMap[A[start]]>1)     counter--;

            HashMap[A[start]]--;

            start++;
        }

    }

    return maxLen;

}
