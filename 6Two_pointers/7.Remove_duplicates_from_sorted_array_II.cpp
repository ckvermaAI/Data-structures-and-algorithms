// https://www.interviewbit.com/problems/remove-duplicates-from-sorted-array-ii/

#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int> &A) {
    // Use two pointers
    // one will iterate over original array = i
    // one over modified array  = j
    // It is crucial when we want to increment one pointer
    const int N = A.size();
    if(N==1)    return N;
    
    int j=0;
    for(int i=0;i<N;++i){
        if(i<N-2 and A[i]==A[i+1] and A[i]==A[i+2]){
            // If count of a num>2 then this relation
            // will violates only 2 times 
            continue;
        }
        else{
            A[j]=A[i];
            j++;
        }
    }

    return j;
}