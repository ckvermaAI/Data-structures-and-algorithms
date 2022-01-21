// https://www.interviewbit.com/problems/divide-integers/

#include <bits/stdc++.h>
using namespace std;

/*

dividend = quotient*divisor + remainder

what divison indicates
1) Divide the dividend into #divisor== number of chunks
2) each of the chunk is of size "quotient"
3) remaining part is "remainder" 

Now, we can also use point (1) for "quotient"
and point (2) for "divisor"


BRUTE FORCE APPROACH =>
1) remove a chunk of size == "divisor"
2) keep on dividing the number till it is greater than "divisor"
3) number of times we remove the chunk in the process == "quotient"
    and remaining part is "remainder"

time complexity = O(Dividend)

USING BITS =>
we want to find quotient and we can do so by finding each bit of the quotient
1) To determine the most significant bit of quotient we can iterate thorugh all
the bits from most significant to least one.

2) when we encounter a first bit i for which  " divisor<<i <= dividend "
then it is our first bit of quotient

3) Till now we accounted for the part "divisor<<i" of dividend
    so we can store this part in a variable  temp+= divisor<<i;

4) now we keep iterating the less significant bits and for those bits we need to 
    take care of this condition "temp + divisor<<i  <= dividend"

time complexity = O(log(Dividend))

*/

int divide1(int dividend, int divisor) {
    // A = dividend
    // B = divisor

    // division of two number will be only negative when
    // only one of them is negative    
    int sign = ((dividend<0) ^ (divisor<0))?-1:1;

    // use only absolute value of both A and B 
    long long int A = dividend, B = divisor;
    A = abs(A), B = abs(B);

    long long int quotient=0;
    while(A>=B){
        A-= B;
        quotient++;
    }

    if(sign<0)  quotient = (-quotient);

    return (quotient>=INT_MAX or quotient<=INT_MIN)?INT_MAX:quotient;
}


int divide(int dividend, int divisor) {
    // A = dividend
    // B = divisor

    // division of two number will be only negative when
    // only one of them is negative    
    int sign = ((dividend<0) ^ (divisor<0))?-1:1;

    // use only absolute value of both A and B 
    long long int A = dividend, B = divisor;
    A = abs(A), B = abs(B);

    long long int quotient=0, temp=0;

    for(int i=31;i>=0;--i){
        if( temp + (B<<i) <= A ){
            temp += (B<<i);
            quotient |= (1LL<<i);
        }
    }

    if(sign<0)  quotient = (-quotient);

    return (quotient>=INT_MAX or quotient<=INT_MIN)?INT_MAX:quotient;
}

