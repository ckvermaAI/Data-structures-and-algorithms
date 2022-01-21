// https://www.interviewbit.com/problems/subarrays-with-distinct-integers/

#include <bits/stdc++.h>
using namespace std;

int atMost(vector<int> &A, int B){
    const int N = A.size();
    int ans=0;

    // To store the count of all element
    unordered_map<int,int> count;

    // i point to right part of sub-array
    // j point to left part of sub-array

    int j=0;
    for(int i=0;i<N;++i){
        count[A[i]]++;
        for(;j<N;++j){
            // we need to expand the space i.e increase the i
            if(count.size()<=B)     break;
            
            // reduce the space i.e increase the j
            else    count[A[j]]--;

            if(count[A[j]]==0)  count.erase(A[j]);
        }
        ans += (i-j+1);
    }

    return ans;
}


int solve(vector<int> &A, int B) {
    /*
    
    To directly count the subarrays with exactly B different integers is hard but to find the count of subarrays with at most B different integers is easy.
    So think how will you find the number of subarray with at most B distinct integers and try to find a solution to the problem.

    
    */

    return atMost(A, B) - atMost(A, B-1);
}
