// https://www.youtube.com/watch?v=dolcMgiJ7I0&list=PL2_aWCzGMAwLL-mEB4ef20f3iqWMGWa25&index=5

#include <bits/stdc++.h>
using namespace std;

/*

Brute Force approach =>
    Iterate over all numbers from 1 till N
    and find out all the factors
    Time complexity = O(N)

Key observation => 
    given N = 36
    write all the factors of N 
    {1, 36}, {2, 18}, {3, 12}, {4, 9}       Case 1
    {9, 9}                                  case 2
    {9, 4}, {12, 3}, {18, 2}, {36, 1}       Case 3

    factors of a number exist in form of co-factors
    so, if we iterate through case 1 and case 2 then 
    case 3 is automatically covered just permutation of 
    {a, b} differs


Efficient approach =>
    Iterate through all the number  "<=sqrt(N)"
    and for each such "a" which is factor of N
    then N/a will also be factor of N
    Time complexity = O(sqrt(N))

*/


int main(){


    return 0;
}