// https://www.interviewbit.com/problems/evaluate-expression/

#include <bits/stdc++.h>
using namespace std;

int evalRPN(vector<string> &A) {
    // the inner most expression will be present in left
    // start iterating from left 
    // insert the operand in stack
    // once we encounter a operator, extract the most two recent
    // element from stack and apply the operator on these elements
    stack<int> nums;

    for(int i=0;i<A.size();++i){
        if(A[i]=="+" or A[i]=="-" or A[i]=="*" or A[i]=="/"){
            int num2 = nums.top();  nums.pop();
            int num1 = nums.top();  nums.pop();
            int res=0;
            if(A[i]=="+")   res += (num1+num2);
            else if(A[i]=="-")   res += (num1-num2);
            else if(A[i]=="*")   res += (num1*num2);
            else if(A[i]=="/")   res += (num1/num2);
            
            nums.push(res);
        }
        else{
            nums.push(stoi(A[i]));
        }
    }
    return nums.top();
}
