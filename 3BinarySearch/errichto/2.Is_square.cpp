

// Binary search tutorial (C++ and python) Errichto
// https://www.youtube.com/watch?v=GU7DpgHINWQ&t=1022s

#include <bits/stdc++.h>
using namespace std;

/*

Binary search is not only used to find the element in the array
for example, in this problem

Given a number N find out whether it is perfect square of other number.
Also we are forbidden to use sqrt function available in libray
example -> Input: 16    output: 1
           Input: 20    output: 0

Solution =>
Use binary search on [0, N] and check whether x^2 = N exists or not
if it exist then return 1 otherwise 0

*/


