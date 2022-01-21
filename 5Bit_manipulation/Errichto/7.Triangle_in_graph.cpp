// errichto
// C++ Bitsets in Competitive Programming
// https://www.youtube.com/watch?v=jqJ5s077OKo


#include <bits/stdc++.h>
using namespace std;

/*

Triangles in a graph
Given a graph with N<=2000 verticesm count triangle (a, b, c)

for example:
INPUT =>
    neighbours of 1st vertex = {2, 4, 5}
    neighbours of 2nd vertex = {1, 3, 4, 6}
    neighbours of 3rd vertex = {2}
    ....
    neighbours of 6th vertex = {2, 4, 5}



Brute Force approach => 
Iterate through all the vertices, Time Complexity = O(N^3)


Using Bitset =>
convert the adjacency list of each vertex in binary representation,
for each pair compute the intersection (using BITWISE AND operation)
if there is intersection then compute the intersection of those two vertices
and add there popcount of ones to the answer.
But we need to divide the final answer by 3, because for each vertex of 
triangle we are counting the triangle 3 times


*/