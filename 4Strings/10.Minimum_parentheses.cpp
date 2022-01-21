// https://www.interviewbit.com/problems/minimum-parantheses/

#include <bits/stdc++.h>
using namespace std;

int solve(string A) {
    stack<char> open;
    int res=0;  // violations
    for(int i=0;i<A.size();++i){
        if(A[i]=='(')   open.push('(');
        else{
            if(!open.empty())   open.pop();
            else    res++;
        }
    }
    res += open.size();
    return res;
}