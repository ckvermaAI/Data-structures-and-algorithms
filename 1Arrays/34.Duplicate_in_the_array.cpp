// https://www.interviewbit.com/problems/find-duplicate-in-array/

#include <bits/stdc++.h>
using namespace std;

int repeatedNumber2(const vector<int> &A) {
    // space complexity = O(N)
    // Time complexity = O(sqrt(N))
    const int N=A.size();
    vector<int> counts(N+1);
    for(int i=0;i<N;++i){
        counts[A[i]]++;
        if(counts[A[i]]>1)
            return A[i];
    }
    return -1;
}

int repeatedNumber1(const vector<int> &A) {
    // space complexity O(1)
    // Time complexity O(N)

    /*
    
    Use two pointers the fast and the slow. The fast one goes forward two steps each time, while the slow one goes only step each time. They must meet the same item when slow==fast. In fact, they meet in a circle, the duplicate number must be the entry point of the circle when visiting the array from nums[0]. 
    
    Next we just need to find the entry point. We use a point(we can use the fast one before) to visit form begining with one step each time, do the same job to slow. When fast==slow, they meet at the entry point of the circle.
    
    */


    int slow = A[0], fast = A[A[0]];
    
    while(slow != fast){
        slow = A[slow];
        fast = A[A[fast]];
    }
    
    fast = 0;
    while(slow != fast){
        slow = A[slow];
        fast = A[fast];
    }
    
    return slow;
}