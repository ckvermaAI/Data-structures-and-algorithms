// https://www.interviewbit.com/problems/maximum-unsorted-subarray/

#include <bits/stdc++.h>
using namespace std;

vector<int> subUnsort(vector<int> &A) {
    /*
    
    Brute Force Approach =>
        Make a copy of current array and compare 
        elements with original elements
        use two pointers to obtain this

        Time complexity = O(N*log(N))

    Another approach =>
        Lets say if the array is A then we have to find 
        unsorted Subarray A[l...r] then,
        max( A[l...r] ) < min( A[r+1,....])
        min( A[l...r])  > max( A[0....l-1] )

        For this we just have to find the violation points
        from the left and right side of the array
    
    */

    // Brute Force Approach
    // const int N=Org.size();
    // vector<int> A(N);
    // for(int i=0;i<N;++i)    A[i]=Org[i];

    // sort(A.begin(), A.end());

    // int l=0, r=N-1;
    // while(l<=r){
    //     if(A[l]=Org[l]){
    //         l++;
    //     }
    //     else if(A[r]==Org[r]){
    //         r--;
    //     }
    // }

    // if(l>r) return vector<int>{-1};
    
    // return vector<int> {l,r};

    
    // Another approach
    const int N=A.size();
    int leftMax = A[0], rightMin=A[N-1];
    int leftIndex = 0, rightIndex = N-1;

    // get the leftIndex - indicates the index 
    // where the property last violates A[i]<A[i+1]
    for(int i=1;i<N;++i){
        // to store the max element till previous index "i-1" (on the left)
        leftMax = max(leftMax, A[i-1]);
        if(leftMax>A[i]){
            // if property violates
            leftIndex=i;
        }
    }

    // get the rightIndex - indicates the index
    // where the property first violates A[i]<A[i+1]
    for(int i=N-2;i>=0;--i){
        // to store the max element till previous index "i+1" (on the right)
        rightMin = min(rightMin, A[i+1]);
        if(rightMin<A[i]){
            rightIndex = i;
        }
    }

    if(leftIndex==0 or rightIndex==N-1) return vector<int> {-1};

    return vector<int> {rightIndex, leftIndex};
}
