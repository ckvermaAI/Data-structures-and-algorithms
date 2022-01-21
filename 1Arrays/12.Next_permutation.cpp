#include <bits/stdc++.h>
using namespace std;

int binary_index(vector<int>&A, int low, int key){
    int high = A.size()-1;
    while(low<=high){
        int mid = low+ (high-low)/2;
        // if found the key
        if(A[mid]==key)     return mid;
        else if(A[mid]>key){
            high = mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return low;
}

vector<int> nextPermutation(vector<int> &A) {
    /*
    
    Different permutations of A = [1, 2, 3]

    1   2   3  
    1   3   2   
    
    2   1   3
    2   3   1

    3   1   2
    3   2   1

    Iterate from the last element and check 
    if the property A[i]<A[i-1]  satisfy then continue
    (current element is smaller than next element)

    otherwise, sort the right half
    swap next element A[i-1] with next element A[i....N-1] (using binary search)
    
    
    */
    const int N=A.size();
    if(N<=1)    return A;

    bool found = false;
    for(int i=N-1;i>=1;--i){
        // current element is i
        // next element is i-1
        if(A[i]<=A[i-1])    continue;
        else{
            // if property does not satisfy 
            partial_sort(A.begin()+i, A.end(), A.end());
            // find next element A[i-1] in right half
            int index = binary_index(A, i, A[i-1]);
            swap(A[i-1], A[index]);
            
            found = true;
            break;
        }
    }
    if(!found){
        reverse(A.begin(), A.end());
    }

    return A;
}