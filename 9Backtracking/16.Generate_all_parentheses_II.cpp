// https://www.interviewbit.com/problems/generate-all-parentheses-ii/
#include <bits/stdc++.h>
using namespace std;

bool isBalanced(string &A){
    stack<char> braces;
    for(int i=0;i<A.length();++i){
        char temp = A[i];
        if(temp=='(')   braces.push('(');
        else{
            if(braces.empty())  return false;
            braces.pop();
        }
    }
    return braces.empty();
}

void genPerm(vector<string> &res, int &A, string &temp,
        int open, int close, vector<char>&braces){
    // Base case
    if(temp.length()==2*A){
        if(isBalanced(temp))
            res.push_back(temp);
        return;
    }

    // at each position we have the two option {"(", ")"}
    for(int i=0;i<2;++i){
        if(i==0)       open++;          // opening braces
        else           close++;         // closing braces
        if(open<=A and close<=A){
            // if number of opening and closing braces are less than
            temp += braces[i];
            genPerm(res, A, temp, open, close, braces);
            temp.pop_back();
        }
        if(i==0)       open--;          // opening braces
        else           close--;         // closing braces
    }   

}


vector<string> generateParenthesis(int A) {

    // to store result
    vector<string> res;

    // auxiliary string
    string temp="";  

    // to store the possible braces
    vector<char> braces = {'(', ')'};

    // generate the permutation
    genPerm(res, A, temp, 0, 0, braces);


    return res;

}