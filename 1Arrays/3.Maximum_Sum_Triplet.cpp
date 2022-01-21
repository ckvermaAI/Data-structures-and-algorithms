// https://www.interviewbit.com/problems/maximum-sum-triplet/

#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &A) {
    /*
    
    Now we have to find the three intergers which are in increasing order
    and also we want to find only those pair which have the positions in increasing order also
    
    Solution 1 =>
    so brute force approach will be just use three loops and find the answer
    but this will be a solution with time complexity of O(N^3)

    -> So we can do BUD optimisation 
    -> because of the Duplicated work
    
    Solution 2 =>
    Iterate over the middle element and in second iteration iterate through the whole array and find out the 
    max element smaller than middle element on left side and max element on right side
        Time Complexity = O(N^2)


    Solution 3 / optimize Algorithm
    -> iterate through all the elements - which is our middle element
    -> we can do some preprocessing to get the "last element"
        -> max. suffix array can help you out
    -> now how to find the first element of triplet
        -> use binary search 

        Time complexity = O(N*logN) and space complexity = O(1)
    */
    const int N=A.size();
    int maxSum=0;
    // Base Case 
    if(N<3) return maxSum;

    vector<int> right(N, -1);
    for(int i=N-2;i>=0;--i){
        int temp = max(A[i+1], right[i+1]);
        if(temp>A[i]){
            right[i]=temp;
        }
    }

    set<int> s;
    s.insert(A[0]);

    // Now iterate through middle element
    for(int i=1;i<N-1;++i){     // Middle element cannot be first or last one
        s.insert(A[i]);
        if(right[i]!=-1){   // right element exist 
            auto it = s.find(A[i]);
            if(it!=s.begin()){      // if this is not the smallest element in the set
                // then update the maxSum
                int newSum = *(--it)+A[i]+right[i];
                if(newSum>maxSum){
                    maxSum = newSum;
                }
            }   

        }
    }
    return maxSum;
}
