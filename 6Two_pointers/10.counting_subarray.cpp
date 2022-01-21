// https://www.interviewbit.com/problems/counting-subarrays/

#include <bits/stdc++.h>
using namespace std;


int solve(vector<int> &A, int B) {
    /*
    
    Brute force approach is to iterate over all the subarray and 
    find the sum in each subarray
    Time complexity = O(N^3)
    Space complexity = O(1)

    using some preprocessing =>
    calculate the prefix sum array to find the sum of element in
    constant time 
    Time complexity = O(N^2)
    Space complexity = O(N)


    Two pointers =>
    Time complexity = O(N)
    Space complexity = O(1)
    
    */
    const int N = A.size();

    // To store the sum of subarray
    int sum=0;
    // To store the res - number of subarray
    int res=0;

    // Two pointers
    int j=0;
    for(int i=0;i<N;++i){
        sum += A[i];
        for(;j<N;++j){
            
            // if sum is greater than B
            if(sum>=B){
                sum -= A[j];
            }
            
            else    break;
        }
        // This will include all the subarray with l = A[j]
        // where subarray is [l,r]
        res += (i-j+1);
    }

    return res;
}