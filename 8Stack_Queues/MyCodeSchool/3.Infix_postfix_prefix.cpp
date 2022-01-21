// My Code School

// Infix, Prefix and Postfix
// https://www.youtube.com/watch?v=jos1Flt21is&list=PL2_aWCzGMAwI3W_JlcBbtYTwiQSsOTa6P&index=19

/*

Infix Expression => <operand> <operator> <operand>
for example =>  8 * 2 , 8 * ( 8 - 3 ) 


*/


/*

Order of operation =>
( operator precedence )
1) Parentheses ( ) { } [ ]
2) Exponents  ( right to left )     
    2^3^2 => 2 ^ 9 => 512
3) Multiplication and division  ( left to right )
4) Addition and subtraction     ( left to right )

This (right to left) or (left to right) rule for operators with same precedence are termed as "operator associativity". So, in case of operator with equal precedence we go from left to right then we say operator are "left associative" similiarly for operators with same precedence if we evaluate the expression from right to left we termed this as "right associative"


there are two other ways of writing the expression which are parentheses free and can be parse without ambiguity / without requiring take care of any operator precedence/ associativity rules
These two rules are prefix & postfix.

*/


/*

Prefix Notation (Polish Notation) =>
    <operator> <operand> <operand>


Postfix Notation (Reverse Polish Notation) =>
    <operand> <operand> <operator>


Infix expression is good for readablity for humans but prefix and postfix expression are easily parsable and saves memory ( because we need no require to save parentheses for the expression )


*/