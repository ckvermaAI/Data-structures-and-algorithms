// https://www.youtube.com/watch?v=4vNlt_EDw1Q&list=PL2_aWCzGMAwLL-mEB4ef20f3iqWMGWa25&index=2
// My code school

#include <bits/stdc++.h>
using namespace std;

/*

Given a integer number,
How do we find the digits of the number in decimal number

N       Quotient(N/10)    remainder(N%10)
125     12                  5               -> least significant digit
12      1                   2
1       0                   1               -> Most significant digit

If we reverse the remainder sequence we'll get the 
digits of the number


Similarly to find out the representation of number 
in binary form

N        Quotient(N/2)       remainder(N%2)
125       62                  1             0
62        31                  0             2
31        15                  1             4
15         7                  1             8
7          3                  1             16
3          1                  1             32
1          2                  1             64


*/

vector<int> DecimalToBinary(int N, int base){
    // Base case
    if(N==0){
        return vector<int> {0};
    }

    vector<int> res;
    while(N>0){
        int rem = N%base;
        res.push_back(rem);
        N = N/base;
    }
    reverse(res.begin(), res.end());
}



int main(){


    return 0;
}