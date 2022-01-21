// https://www.interviewbit.com/problems/add-binary-strings/
#include <bits/stdc++.h>
using namespace std;

// Since sizes of two strings may be different, we first make the size of smaller string equal to that of bigger string by adding leading 0s for simplicity
// Note that you can handle the addition without adding zeroes as well by adding a few if statements.
// After making sizes same, one by one, we add bits from rightmost bit to leftmost bit.
// In every iteration, we need to sum 3 bits: 2 bits of 2 given strings and carry.

// The sum bit will be 1 if, either all of the 3 bits are set or one of them is set.
// So we can add all the bits and then take remainder with 2 to get the current bit in the answer.

// How to find carry?

// Carry will be 1 if any of the two bits is set. So we can find carry by adding the bits and dividing the result by 2.

// Following is a step by step algorithm:

//     Make them equal sized by adding 0s at the begining of smaller string.

//     Perform bit addition

// Boolean expression for adding 3 bits a, b, c

// Sum = (a + b + c) % 2
// Carry = (a + b + c ) / 2



string addBinary(string A, string B) {
    // first pad zeros to the smaller number
    // assuming A is smaller
    if(A.length()>B.length())   return addBinary(B, A);

    // now A is smaller pad zeros
    A = string(B.length()-A.length(), '0') + A;

    // Now both the strings are of equal length
    string res = "";
    int carry=0;
    for(int i=A.length()-1; i>=0;--i){
        int sum = carry + (A[i]-'0') + (B[i]-'0');
        res = to_string(sum%2) + res;
        carry = (sum/2);
    }
    if(carry){
        res = "1"+res;
    }

    return res;
}
