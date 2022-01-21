// https://www.interviewbit.com/problems/longest-subarray-length/

#include <bits/stdc++.h>
using namespace std;


int solve(vector<int> &A) {
    /*
    
    BruteForce approach is to iterate through each subarray and find the
    whether current subarray is eligible or not
    Time complexity = O(N^3)

    Use prefix sum array and check the number of ones and zeros in a
    subarray in O(1) time 
    
    Better approach =>
    1) maintain "sum" variable and treat 0 as "-1" while adding to "sum"
    2) iterate through the prefix sum array and check if current subarray
        A[0...i] satisfy the condition, if yes update the result
        ( add this to HashMap )
    3)  If current subarray does not satisfy the condition check if we remove
        start elements (we can check that by using HashMap)
    
    */
    
    const int N = A.size();
    
    // to store the sum of previously visited subarray 
    // A[0...i]
    unordered_map<int,int> HashMap;

    // sum to store the sum till now 
    // and maxLen to store the result
    int sum=0, maxLen=0;

    for(int i=0;i<N;++i){
        sum+= (A[i]?1:-1);

        // if current subarray satisfy the condition
        if(sum==1 and i+1>maxLen){
            maxLen = i+1;
        }

        // if current subarray does not satisfy the condition check
        // if "sum-1" exist in the "HashMap"
        else {

            if(HashMap.find(sum-1)!=HashMap.end()){
                // condition satisfied in A[j....i]
                int j = HashMap[sum-1];
                if(i-j>maxLen){
                    maxLen=i-j;
                }
            }

        }

        if(HashMap.find(sum)==HashMap.end()){
            // if value does not exist in Map
            HashMap[sum]=i;
        }
    }

    return maxLen;
    
}
