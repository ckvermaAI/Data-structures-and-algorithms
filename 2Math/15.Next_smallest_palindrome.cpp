// https://www.interviewbit.com/problems/next-smallest-palindrome/
#include <bits/stdc++.h>
using namespace std;

void incrementD(string &A){
    // increase the middle digit by 1
    // and propagate the carry towards left
    const int N = A.length();
    vector<int> numbers(N);
    for(int i=0;i<N;++i){
        numbers[i] = ( A[i] - '0' );
    }
    
    int i=((N+1)/2)-1;
    int carry = (numbers[i] + 1)/10;
    numbers[i] = (numbers[i]+1)%10;
    i--;
    while(carry){
        int temp=carry;
        carry = (numbers[i] + carry)/10;
        numbers[i] = (numbers[i] + temp) %10;
        i--;
    }

    for(int i=0;i<(N+1)/2;++i){
        A[i] = '0' + numbers[i];
        A[N-i-1] = A[i];
    }
    
}


string solve(string A) {
    /*
    There can be 3 different types of inputs that needs to be handled
    separately.
    1. Input number is palindrome and has all 9s. For example "999" output is "1001"
    2. Input number is not palindrome. for example "1234" output is "1331"
    3. input number is palindrome. For example "1221" output is "1331"
   
    How can we handle these cases
    1. Simply increase the number of digits by 1 and set first and last digit to "1" and "0" others
    2. increase the middle digit by 1 and propagate any carry left 
    3. copy the left part of number to right part 
        A) if that is sufficient - we are done
        B) Otherwise increase the middle digit by 1

    */
    const int N=A.length();
    bool allMax = true;
    for(int i=0;i<N;++i){
        if(A[i]!='9'){
            allMax = false;
            break;
        }
    }

    // Case1 - if all digits are '9' then
    if(allMax){
        string res(N+1, '0');
        res[0]='1', res[N]='1';
        return res;
    }

    // Case2 and 3 - Make the palindrome
    // copy left half to right half
    string B = A;
    for(int i=0;i<N/2;++i){
        B[N-1-i] = B[i];
    }

    // case 3A - If resultant string is larger 
    // then return this
    if(B>A){
        return B;
    }

    // case 2, 3B - Increment the middle digit
    incrementD(B);

    return B;
}