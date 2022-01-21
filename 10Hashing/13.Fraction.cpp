// https://www.interviewbit.com/problems/fraction/
// https://www.geeksforgeeks.org/represent-the-fraction-of-two-numbers-in-the-string-format/

#include <bits/stdc++.h>
using namespace std;

/*
Lets simulate the process of converting fraction to decimal. Lets look at the part where we have already figured out the integer part which is floor(numerator / denominator).
Now you are left with ( remainder = numerator%denominator ) / denominator.
If you remember the process of converting to decimal, at each step you do the following :

1) multiply the remainder by 10,
2) append remainder / denominator to your decimals
3) remainder = remainder % denominator.

At any moment, if your remainder becomes 0, you are done.
*/

string Solution::fractionToDecimal(int A, int B) {
    // Base case
    if(A==0) return "0";

    // to store the result and calculation for fraction
    string res="";

    // check the sign of resulting number
    int sign = ( ((A<0)^(B<0))?-1:1 );
    if(sign==-1)    res+='-';

    // get the absolute value 
    long long int X = abs((long long int)A), Y = abs((long long int)B);

    // find the integer part of fraction
    long long int integerP = X/Y;
    long long int remainder = X%Y;

    res += to_string(integerP);

    // if there is zero remainder
    if(remainder==0)    return res;
    
    // add the decimal
    res += '.';

    unordered_map<long long int, long long int> HashMap;
    int index, repeating=0;

    // if there is remainder
    while(remainder){

        // if we previously encountered this remainder
        if(HashMap.find(remainder)!=HashMap.end()){
            index = HashMap[remainder];
            repeating=1;
            break;
        }
        else  HashMap[remainder]=res.size();

        remainder *= 10;
        
        // calculate the quotient, append it to result
        res += to_string(remainder/Y);
        remainder = remainder%Y;

    }

    // if repeating fraction exists, insert parentheses
    if(repeating){
        res += ')';
        res.insert(index, "(");
    }

    return res;

}
