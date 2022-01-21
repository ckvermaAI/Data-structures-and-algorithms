// https://www.youtube.com/watch?v=xXKL9YBWgCY&list=PLl0KD3g-oDOHpWRyyGBUJ9jmul0lUOD80

#include <bits/stdc++.h>
using namespace std;

void binary_representation_int(int N){
    // iterate through the bits
    for(int i=30;i>=0;--i){
        // start with most significant digit
        if(N & (1 << i ))  cout<<"1";
        else    cout<<"0";
    }

    /*
    
    Now (1<<i) this term will always be integer
    so if we shift the 1 by more than 30 then 
    (1<<i) will overflow
    
    */
}


void binary_representation_long(long long int N){
    // iterate through the bits
    for(int i=62;i>=0;--i){  
        // start with most significant digit
        // long long int data type will have 64 bits and 
        // we are iterating over 63 bits and most significant bit is for
        // whether the number is positive or negative
        if(N & (1L << i ))  cout<<"1";
        else    cout<<"0";
    }

    /*
    
    Now (1<<i) this term will always be integer
    so if we shift the 1 by more than 30 then 
    (1<<i) will overflow
    
    */
}


int main(){



    return 0;
}