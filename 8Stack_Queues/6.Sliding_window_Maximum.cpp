// https://www.interviewbit.com/problems/sliding-window-maximum/
// https://www.geeksforgeeks.org/sliding-window-maximum-maximum-of-all-subarrays-of-size-k/

#include <bits/stdc++.h>
using namespace std;

/*

Algorithm =>

1. Create a deque to store k elements.
2. Run a loop and insert first k elements in the deque. Before inserting the element, check if the element at the back of the queue is smaller than the current element, if it is so remove the element from the back of the deque, until all elements left in the deque are greater than the current element. Then insert the current element, at the back of the deque.
3. Now, run a loop from k to end of the array.
4. Print the front element of the deque.
5. Remove the element from the front of the queue if they are out of the current window.
6. Insert the next element in the deque. Before inserting the element, check if the element at the back of the queue is smaller than the current element, if it is so remove the element from the back of the deque, until all elements left in the deque are greater than the current element. Then insert the current element, at the back of the deque.
7. Print the maximum element of the last window.

*/


vector<int> Solution::slidingMaximum(const vector<int> &A, int B) {
    const int N = A.size();

    // Base case 
    // window size >= array size
    if(B>=N)    return vector<int> {*max_element(A.begin(), A.end())};
    // when window size is 1
    if(B==1)    return A;

    // General case B = [2, A.size()-1]
    // to store the result
    vector<int> res;
    // use double ended queue to extract MAX and maintain next possible MAX
    // maintain element in decreasing order 
    // MAX element at front and MIN element at back
    deque<int> nums;
    
    // first window
    nums.push_back(A[0]);
    for(int i=1;i<B;++i){
        if(nums.back()>A[i]){
            nums.push_back(A[i]);
        }
        else{
            while(!nums.empty() and nums.back()<A[i]){
                nums.pop_back();
            }
            nums.push_back(A[i]);
        }
    }
    res.push_back(nums.front());

    // other windows
    // i - to iterate through the array
    // j - indicates to last element which is not present in current window
    for(int i=B,j=0; i<A.size(); ++i, ++j){
        // remove the last element not present in current window
        if(A[j]==nums.front())  nums.pop_front();

        if(nums.back()>A[i]){
            nums.push_back(A[i]);
        }
        else{
            while(!nums.empty() and nums.back()<A[i]){
                nums.pop_back();
            }
            nums.push_back(A[i]);
        }        
        res.push_back(nums.front());
    }

    return res;
}
