// https://www.interviewbit.com/problems/remove-duplicates-from-sorted-array/

#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int> &A) {
    // Use two pointers
    // one will iterate over original array = i
    // one over modified array  = j
    // It is crucial when we want to increment one pointer
    const int N = A.size();

    int j=0;
    for(int i=0;i<N;++i){
        if(i<N-1 and A[i]==A[i+1])   continue;
        else{
            // store the last occurence of a number
            A[j]=A[i];
            j++;
        }
    }
    return j;
}