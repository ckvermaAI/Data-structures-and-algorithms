// https://www.interviewbit.com/problems/min-xor-value/

#include <bits/stdc++.h>
using namespace std;

/*

0000    =  0
0001    =  1
0010    =  2
0011    =  3
0100    =  4
0101    =  5
0110    =  6
0111    =  7
0111    =  8

1) Maximum XOR value exists b/w (1<<i) and (1<<i)-1

2) XOR operation of two bits will be 1 only when both are different bits
    A^B   ==  A!=B

3) The Minimum XOR value will exist b/w two closest number

so if we sort the array and find the XOR values b/w two consecutive numbers
of the array then it will be sufficient to find the minimum XOR value

*/

int findMinXor(vector<int> &A) {
    int res=INT_MAX;
    sort(A.begin(), A.end());
    for(int i=1;i<A.size();++i){
        int temp= A[i]^A[i-1];
        res = min(res, temp);
    }
    return res;
}
