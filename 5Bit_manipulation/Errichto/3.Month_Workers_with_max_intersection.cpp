
// Errichto
// C++ Bitsets in Competitive Programming
// https://www.youtube.com/watch?v=jqJ5s077OKo

#include <bits/stdc++.h>
using namespace std;

/*

Problem => There are N<=5000 workers. Each is available during some days
of this month. Find two Workers with maximum intersection of their schedules

for example: 
INPUT :
    worker1 = {2, 3, 5, 6, 8}  
    (worker1 is available on 2, 3, 5, 6 and 8 day of month)
    worker2 = {2, 4, 5, 8}
    worker3 = {1, 2, 10, 12, 14, 16}
OUTPUT:
    worker1 and worker2


BruteForce approach => for each worker iterate through all the workers and find
the intersection of each pair of workers. 
Time complexity = O(Number of pairs of worker * Find intersection of two workers)
                 = O(N^2 * D)
                 where N is number of worker and D = total number of days (here==30)


Using bitsets =>
    we can use bit mask of length(30==number of days in month) to represent a 
    worker.
    Time complexity = O(N^2)

    for example, we can represent the worker1 = 011011010....0 
    where we have in total 30 bits and bit corresponding to availability of worker1 for that day is active or "1"
    Now to find the intersection of worker we just need to take "bitwise &"
    of bitwise representation of mask which have time complexity = O(1)
    instead of O(D)


    Algorithm => 
    a) first change every set into a binary number
    b) Iterate over all the pair of workers and for each of them
       compute BITWISE AND 
    c) In BITWISE AND we need number of common days or "ones"

    we can get the number of "1" using 
    1) __builtin_popcount(x)
    1) __builtin_popcountll(x)




*/


int main(){


    return 0;
}
