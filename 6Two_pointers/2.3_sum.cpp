// https://www.interviewbit.com/problems/3-sum/

#include <bits/stdc++.h>
using namespace std;

int threeSumClosest(vector<int> &A, int B) {
    /*
    
    Naive appraoch is to iterate over all three elements 
    and check if the sum is equal to B or not
    Time Complexity = O(N^3)


    How we can get rid of one of the loops?
        Use Unordered_map or map, now iterate over array twice 
        to fix the first two elements and check if "target - sum_of_first_2_elements"
        exist in map.
        Time complexity = O(N^2)   if we use unordered_map
        space complexity = O(N)

    
    Can we get rid of extra space which we are using in form of "map" ?
        Lets say if we sort the array can we use the sorted elements to find 
        the whether a pair exist with sum equal to "target - sum_of_first_elements"
        Yes, we can use two pointers technique.
        
        Time Complexity = O(N^2)
        Space complexity = O(1)

    */
    typedef long long int lld;
    const int N = A.size();
    sort(A.begin(), A.end());

    lld diff=INT_MAX;   // to store the difference b/w  abs(res-B)
    lld res = INT_MAX;  // to store the three numbers

    for(int i=0;i<N;++i){
        // fix the first element
        // Use two pointers for finding the next two elements
        int k = N-1;
        for(int j=i+1;j<N;++j){
            for(;k>=0;--k){
                lld temp_res  = (lld)A[i]+A[j]+A[k];
                if(i!=j and j!=k){
                    lld temp_diff = abs(temp_res-B);
                    if(temp_diff<diff){
                        diff = temp_diff;
                        res = temp_res;
                    }
                }
                // because we are decreasing k
                else if(temp_res<B)     break;
            }
        }
    }

    return res;
}