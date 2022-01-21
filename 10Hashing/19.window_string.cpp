// https://www.interviewbit.com/problems/window-string/
// https://leetcode.com/problems/minimum-window-substring/discuss/26808/Here-is-a-10-line-template-that-can-solve-most-'substring'-problems
#include <bits/stdc++.h>
using namespace std;

string minWindow(string A, string B) {

    // use HashMap to store the ocurrence of each word 
    // present in string B
    unordered_map<char,int> HashMap;

    for(char &x:B) HashMap[x]++;

    // use to save the best result so far
    int s=0, maxLen=INT_MAX;

    // two pointers to iterate through the array
    int start=0, end=0;

    // use variable to keep how many character of string
    // B are left unmatched 
    int counter = B.length();

    while(end<A.length()){

        // decrease the count of current word in HashMap
        // count of element present in string B will be greater > 0 
        if(HashMap[A[end]]>0)   counter--;
        
        HashMap[A[end]]--;

        end++;

        while(counter==0){
            // when we found all char update the answer
            if(end-start<maxLen){
                s=start;
                maxLen = end-start;
            }
            // when we found all char of string B move "start" pointer

            HashMap[A[start]]++;
            
            if(HashMap[A[start]]>0)     counter++;

            start++;
        }

    }

    if(maxLen==INT_MAX)   return "";

    return A.substr(s, maxLen);

}
