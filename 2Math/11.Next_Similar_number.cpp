// https://www.interviewbit.com/problems/next-similar-number/

#include <bits/stdc++.h>
using namespace std;

int binaryIndex(string&A, int low, char key){
    int high = A.size()-1;
    key++;
    while(low<=high){
        int mid = low+(high-low)/2;
        if(A[mid]==key){
            return mid;
        }
        else if(A[mid]>key){
            high = mid-1;
        }
        else{
            low= mid+1;
        }
    }

    return low;
}

string solve(string A) {
    // Now we have to find out point 
    // where the policy break starting from last point
    // policy = next element is larger than current
    const int N = A.length();
    for(int i=N-1;i>=1;--i){
        // current element is i
        // next element is i-1
        if(A[i]<=A[i-1]) continue;
        else{
            // when policy breaks
            // partially sort the array
            partial_sort(A.begin()+i, A.end(), A.end());
            // find out the next element (element greater than 
            // A[i-1])
            int index = binaryIndex(A, i, A[i-1]);
            swap(A[i-1], A[index]);
            return A;
        }
    }
    return "-1";
}
