// errichto
// C++ Bitsets in Competitive Programming
// https://www.youtube.com/watch?v=jqJ5s077OKo


#include <bits/stdc++.h>
using namespace std;

/*

Problem => There are N<=5000 workers. Each is available during some days
of this YEAR. Find two Workers with maximum intersection of their schedules

for example: 
INPUT :
    worker1 = {2, 3, 5, 6, 8}  
    (worker1 is available on 2, 3, 5, 6 and 8 day of month)
    worker2 = {2, 4, 5, 8}
    worker3 = {1, 2, 10, 12, 14, 16}
OUTPUT:
    worker1 and worker2


We can use the solution of the previous problem 
"3.Month_Workers_with_max_intersection.cpp"

Problem =>
    But single "int" is not able to store the "365 BITS"

Solution 1 =>
    Create separate Bitmask for each month because 30 bits
    will fit in single integer, for a year we have 12 such
    number.
    Time complexity = O(N^2 * (D/64)) or O(N^2 * (D/32))


Solution 2 =>
    Using BITSET, we can simply create a binary representation
    of set using bitset

    #Number of bits = constant (should be known before compiling)
    syntax ==   bitset<#Number of bits> X
    (underhood bitset is just a array of unsigned long long so we need
    to pass a constant size of the array )

    It handles bitwise operations and shifts (we need not to split
    the given bits in group of 32 or 64 bits )

    Different opeartions on BITSET
    a.count()   # count the number of "1"s
    a & b       # bitwise OR
    a>>k        # right shift by k


    Time complexity = O(N^2 * (D/32)) or O(N^2 * (D/w))
    where w is word size usually 32 or 64

*/


// SOLUTION 1
const int MAX_D = 365;    // Number of days
const int MAX_N = 10;      // Number of workers
const int K = MAX_D/64 + 1;

unsigned long long x[MAX_N][K];
int intersection1(int i, int j){
    int total=0;
    for(int z=0;z<K;++z){
        total += __builtin_popcountll(x[i][z] & x[j][z]);
    }
    return total;
}



// SOLUTION 2
bitset<MAX_D> y[MAX_N];
int intersection(int i, int j){
    return (y[i] & y[j]).count();
}
