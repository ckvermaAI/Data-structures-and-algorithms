// My code school
// Infix to Postfix using stack
// https://www.youtube.com/watch?v=vq-nUF0G4fI&list=PL2_aWCzGMAwI3W_JlcBbtYTwiQSsOTa6P&index=21

/*

Convert infix to postfix
for example=>

Algorithm 1 => Use operator precedence and associativity rules
    // parse the expression from left to right
    Infix  =>   A + ( B* C )        // precedence of * is higher 
                A +  ( B C * )      // now convert + expression
                A ( B C * ) +       // get rid of parentheses
    Postfix =>  A B C * +         

    But, implementation of this algorithm is not very efficient and we may have to traverse multiple times through this loop

Algorithm 2 (when there no parentheses) => 

    *** crucial observation = In conversion from infix to postfix expression order of operators may change but the order of operand occurence will stay the same ***

    // parse the expression from left to right
    // Rule 1 - if we encounter a operand add it to the result
    // Rule 2 - append the operator in stack
    // Rule 3 - pop out the operator from stack when either we encounter a  operator of low precedence than element at top of stack or when we reach at the end of traversal

    Infix  =>   A +  B * C  - D * E
        1) 'A' is operand append it to result     // res = A 
        2) add '+' to stack
        3) add 'B' to res                          // res = A B
        4) add '*' to stack
        5) add 'C' to res                          // res = A B C
        6) encounter a '-' which is of lower precedence than stack top operator, we can pop out all elements from stack and add it to res
                                                    // res = A B C * + 
            add current '-' in stack
        7) add 'D' to res                           // res = A B C * + D
        8) add '*' to stack                         
        9) we reach at end of the traversal , now pop out all the elements from stack 
            // res = A B C * + D E* - 


Algorithm 3 (when there are parentheses) => 
    it is very similiar to algorithm 2, but when we introduced parentheses in our expression that means we are explicitly set the order of evaluation in expression. so to account for that there is some addition in rule 2 and rule 3
    
    // rule 2 addition - add the opening parentheses in stack
    // rule 3 addition - as soon as we encounter a open parentheses in the top of stack logically that expression is complete in itself, hence we can stop at that point 

    for example => 

    Case I - when there are no parenthesis
        convert  A * B + C to postFix expression 
        answer = A B * C +

    Case II - when there are parenthesis
        convert  A * (B + C) to postFix expression 
        answer = A B C + *
 
*/

#include <bits/stdc++.h>
using namespace std;

bool higherPrec(char current, char stackTop){
    bool cond1 = (current=='*') or (current=='/');
    bool cond2 = (stackTop=='+') or (stackTop=='-');
    if(cond1 and cond2) return true;
    return false;
}

string InfixtoPostfix(string exp){
    // when expression does not contain parentheses
    
    stack <char> num;
    string res="";
    int start=0;
    while(start<exp.length()){
        char temp=exp[start];
        if(temp=='+' or temp=='-' or temp=='*' or temp=='/'){
            while( !num.empty() and higherPrec(temp, num.top()) ){
                res = res+ num.top();
                num.pop();
            }
            num.push(temp);
        }
        else res=res+temp;
        start++;
    }
    while(!num.empty()){
        res = res + num.top();
        num.pop();
    }

    return res;
}


string InfixtoPostfixParentheses(string exp){
    // when expression contain parentheses
    
    stack <char> num;
    string res="";
    int start=0;
    while(start<exp.length()){
        char temp=exp[start];
        if(temp=='+' or temp=='-' or temp=='*' or temp=='/'){
            while( !num.empty() and higherPrec(temp, num.top()) 
                    and num.top()!='('){
                // pop until we get opening parentheses
                res = res+ num.top();
                num.pop();
            }
            num.push(temp);
        }
        else if(temp=='(')  num.push(temp);
        else if(temp==')'){
            while( !num.empty() and num.top()!='('){
                // pop until we get opening parentheses
                res = res+ num.top();
                num.pop();
            }
            num.pop();  // extra pop() to pop '('
            num.push(temp);
        }
        else res=res+temp;
        start++;
    }
    while(!num.empty()){
        res = res + num.top();
        num.pop();
    }

    return res;
}


int main(){

    return 0;
}