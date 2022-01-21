// https://www.interviewbit.com/problems/pair-with-given-difference/

#include <bits/stdc++.h>
using namespace std;


// Approach 1 - Two pointers
// Time Complexity = O(Nlog(N))
// Space Complexity = O(1)

int solve(vector<int> &A, int B) {
    /*
    
    Sort the array A, now to find the 
    whether the pair exist for which the difference is B
    we can use two pointers techinque
    
    One thing that matters in two pointers questions is how
    should we traverse the pointers and will depends on
    1) what is our input (sorted in ascending order, descending order)
    2) what is our query

    In this question we want to find a pair havind difference of "B"
    If we have sorted array in ascending order and if we want to traverse
    all the pair (i, j) with i<j  then we can do this by 

        for(int i=0;i<A.size();++i){
            for(int j=i+1;j<A.size();++j){
                if(A[j]-A[i]==B)    return 1;
                else if(A[j]-A[i]>B)    break;
            }
        }

        A[j] - A[i] < B
        then A[j] - A[i+1] < B  because A[i+1]>A[i]
        
        It means if we have tried the J for i then we only need to try j>J for
        >=i+1

    */
    
    const int N = A.size();
    sort(A.begin(), A.end());

    int j=1;
    for(int i=0;i<N;++i){
        for(;j<N;++j){
            if(A[j]-A[i]==B and i!=j)   return 1;
            else if(A[j]-A[i]>B){
                // Because we are increasing the j
                break;
            }    
        }
    }
    return 0;
}


// Approach 2
// Iteration1 - Use unordered Map to store all the values of array
// Iteration2 - each element A[i] of array check A[i]+B exist in "map"

// Time complexity = O(N)
// Space complexity = O(N)
