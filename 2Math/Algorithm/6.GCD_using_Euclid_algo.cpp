// https://www.youtube.com/watch?v=7HCd074v8g8&t=172s

#include <bits/stdc++.h>
using namespace std;

int euclid_GCD2(int a, int b){
    // int dividend = ((a>=b)?a:b);
    // int divisor = ((a<=b)?a:b);

    // instead of setting smaller number equals to divisor
    // we can just set these values and after one iteration
    // smaller value will automatically assigned to divisor
    int dividend = a;
    int divisor = b;
    while(divisor!=0){
        int remainder = dividend%divisor;
        dividend = divisor;
        divisor = remainder;
    }
    return dividend;
}


int euclid_GCD1(int a, int b){
    while(b!=0){
        int remainder = a%b;
        a = b;
        b = remainder;
    }
    return a;
}




int main(){


    return 0;
}