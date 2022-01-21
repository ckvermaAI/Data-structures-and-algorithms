// https://www.geeksforgeeks.org/kth-smallestlargest-element-unsorted-array/
// https://www.interviewbit.com/problems/k-largest-elements/

#include <bits/stdc++.h>
using namespace std;

int partition(vector<int>&A, int low, int high){
    
    // set last element as pivot and moves all elements
    // smaller than pivot to left of it and greater to the right
    int x = A[high];
    int i = low;

    for(int j=low;j<=high-1;++j){
        if(A[j]<=x){
            swap(A[i], A[j]);
            i++;
        }
    }
    swap(A[i], A[high]);
    return i;
}


int kthLargest(vector<int> &A, int low, int high, int k){
    //  If k is smaller than number of element in array
    if(k>0 and k<=high-low+1){
        // partition the array around last element and get the 
        // position of pivot element in sorted array
        int pos = partition(A, low, high);
    
        // If position is same as k
        if(high-pos==k-1){
            return pos;
        }
        // If position is more, recur for right subarray
        else if(high-pos>k-1){
            // when we search on the right k will remain same
            return kthLargest(A, pos+1, high, k);
        }

        else{
            // when we search on left k will changes
            // because now we found k - size of right array 
            // or k - (high-pos+1) elements
            // and we only to find (k - (high-pos+1))th largest 
            // element in left array
            return kthLargest(A, low, pos-1, k-(high-pos+1));
        }
        
    }
    
    return INT_MAX;

}

vector<int> solve(vector<int> &A, int B) {
    int pos = kthLargest(A, 0, A.size()-1, B);
    if(pos!=INT_MAX){

        return vector<int> {A.begin()+pos, A.end()};

    }

    return vector<int>{};
}