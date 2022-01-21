// My Code School
// Evaluation of Prefix and Postfix expressions using stack
// https://www.youtube.com/watch?v=MeRb_1bddWg&list=PL2_aWCzGMAwI3W_JlcBbtYTwiQSsOTa6P&index=20


/*

Given an Infix expression => A * B + C * D - E
convert this to postfix expression.

step1 - create/place implicit parentheses on the basis of operator precedence
    ( ( A * B ) + ( C * D )  ) - E

step2 - start with the inner most expression and convert that to postfix expression
    (  ( A B * ) +  ( C D * )  ) - E

    (  ( A B * )  ( C D * ) +  ) - E

    (  ( A B * )  ( C D * ) +  )  E  -

step3 - remove the parentheses
    A B * C D * + E -

we can create a program to mimic these steps.



How to evaluate a postFIX expression =>

given a postFix expression evaluate the expression. 
for this task we can scan/traverse through the expression from left to right. 

(because innermost expression in corresponding infix expression will be present in the leftmost part of the postfix expression and thus we can evaluate the postfix expression by traversing from left to right) 

*/

#include <bits/stdc++.h>
using namespace std;

int EvaluatePostFix(string exp){
    stack<int> res;
    int start=0;
    while(start<exp.length()){
        char temp=exp[start];
        if(temp=='+' or temp=='-' or temp=='*' or temp=='/'){
            int num2=res.top();
            res.pop();
            int num1=res.top();
            res.pop();
            if(temp=='+') res.push(num1+num2);
            else if(temp=='-') res.push(num1-num2);
            else if(temp=='*') res.push(num1*num2);
            else if(temp=='/') res.push(num1/num2);

        }
        else{
            res.push(temp-'0');
        }
        start++;
    }
    return res.top();
}


int main(){


    return 0;
}