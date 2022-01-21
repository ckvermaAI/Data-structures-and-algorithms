// https://www.interviewbit.com/problems/palindrome-partitioning/

#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string &A){
    int i=0, j=A.length()-1;
    while(i<j){
        if(A[i]!=A[j]){
            return false;
        }
        i++;j--;
    }
    return true;
}


void genPerm(vector<vector<string>>&res, vector<string> &temp, string&A, int start, int sum){

    // Base case
    if(sum==A.length()){
        res.push_back(temp);
        return;
    }

    for(int i=start;i<A.length();++i){
        for(int j=i;j<A.length();++j){
            // {i, j} == substring of A
            string subString = A.substr(i, j-i+1);
            if(isPalindrome(subString)){
                temp.push_back(subString);
                genPerm(res, temp, A, j+1, sum+subString.length());
                temp.pop_back();
            }
        }
    }
}


vector<vector<string>> partition(string A) {
    
    // to store the result
    vector<vector<string>> res;

    // auxiliary string
    vector<string> temp;

    // generating permutations
    genPerm(res, temp, A, 0, 0);
    
    return res;
}

