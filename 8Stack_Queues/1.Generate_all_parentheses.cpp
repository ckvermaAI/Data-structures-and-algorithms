// https://www.interviewbit.com/problems/generate-all-parentheses/

#include <bits/stdc++.h>
using namespace std;

int isValid(string A) {
    /*
    we can use stack to do this task
    when we encounter a opening braces insert in the stack

    and when we encounter a closing braces match it with the most
    recent opening parentheses (most recent opening braces = stack.top() )
    a) if closing parentheses does not match with most recent opening parentheses
        then it it not valid

    b) if opening parentheses left unmatches or closing parentheses left unmatched
    
    */
    stack <char> braces;
    int start=0;
    while(start<A.length()){
        char temp = A[start];
        if(temp=='{' or temp=='(' or temp=='[')     braces.push(temp);
        else{
            // no opening braces left
            if(braces.empty())  return 0;

            // opening and closing braces doesn't match
            if ((temp==')' and braces.top()!='(') or (temp=='}' and braces.top()!='{') or (temp==']' and braces.top()!='['))  
                return 0;
            
            braces.pop();
        }
        start++;
    }

    if(!braces.empty())     return 0;

    return 1;

}