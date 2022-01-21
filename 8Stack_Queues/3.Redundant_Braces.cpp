// https://www.interviewbit.com/problems/redundant-braces/

#include <bits/stdc++.h>
using namespace std;

int braces(string A) {
    /*

    we can use stack for this problem
    It is given that "A" is valid expression

    A pair of braces will be redudant if there is only 
    another set of braces inside this set of braces
    and 
    if this braces does not contain a expression i.e.
    it only contains some value
    
    */

    const int N = A.length();
    stack<char> exp;

    for(int i=0;i<N;++i){
        char temp = A[i];

        // if we have closing braces 
        // extract all of expression corresponding to 
        // this closing braces
        if(temp==')' and exp.top()=='('){
            // this will take care of cases like "((a+b))""
            return 1;
        }
        else if(temp==')'){
            bool sign=false;
            // extract the whole expression
            while(exp.top()!='('){
                if(exp.top()=='+' or exp.top()=='-' or exp.top()=='*' or exp.top()=='/'){
                    sign=true;
                }
                exp.pop();
            }
            // if expression contains only value then 
            // there are redundant braces
            // this will take care of cases like "(a)"
            if(!sign)   return 1;

            // to pop '(' braces
            exp.pop();

        }
        else    exp.push(temp);

    }

    return 0;

}
