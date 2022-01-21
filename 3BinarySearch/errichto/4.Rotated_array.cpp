
// Binary search tutorial (C++ and python) Errichto
// https://www.youtube.com/watch?v=GU7DpgHINWQ&t=1022s

#include <bits/stdc++.h>
using namespace std;

/*

Problem => 

Given rotated(shifted) a sorted array A. 
Find the smallest element.
or
Find out the position where the rotation
happens(in that case also we need to find
the smallest element)

Input:  A = {6, 7, 9, 15, 19, 2, 3}
output: 2

It is a example where we will use binary search and 
input array is not sorted



condition => number is greater than last number
If this condition satisfy then it is "T" otherwise "F"

Find the first F, sequence of F indicates the boundary 
where the two halves of array are separated

{6, 7, 9, 15, 19, 2, 3}
{T, T, T,  T,  T, F, F}

{2, 3, 6, 7, 9, 15, 19}
{F, F, F, F, F, F,  F}


Think about binary search problem in terms of prefix and suffix
of true(T) and false(F) according to some given condition


Solution =>
we cannot use binary search directly, because currently
we do not have enough information about where we should move
if we are currently at an element "i" . 


*/

int rotatedArray(const vector<int>&A){
    // to store the best possible 
    // answer till now
    int index=0;

    int low=0, high=A.size()-1;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(A[mid]<A[index]){
            // condition satisfy 
            // update the index
            index = mid;
            high = mid-1;
        }
        else{
            // look on the right
            low = mid+1;
        }
    }

    return A[index];
}