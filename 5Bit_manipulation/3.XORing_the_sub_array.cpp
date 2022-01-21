// https://www.interviewbit.com/problems/xor-ing-the-subarrays/

#include <bits/stdc++.h>
using namespace std;

/*

BruteForce Approach => Iterate through all the sub-arrays and find the 
XOR of each subarray and take XOR of all sub-array
Time complexity = O(N^2)

Observations => XOR of one number with itself is 0
so, if we take XOR of the array 2^N times then it will be 0
and if it is something like 2^N+1 times then it will be number itself


Now, we have to find out the number of ocurrence of each element in the array
Example - A = [1, 2, 3, 4]
         Subarray of A :
            1
            1 2
            1 2 3
            1 2 3 4
            
            2 
            2 3 
            2 3 4
            
            3 
            3 4

            4

        Occurence of ith element is (i+1)*(N-i)

*/


int solve(vector<int> &A) {
    const int N = A.size();
    int res = 0;
    for(int i=0;i<N;++i){
        long long int occurence = ((long long int)N-i)*(i+1);
        if(occurence%2){
            // If there are odd number of occurences
            res ^= A[i];
        }
    }
    return res;
}
