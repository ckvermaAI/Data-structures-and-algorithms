// https://www.interviewbit.com/problems/merge-two-sorted-lists-ii/

#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &A, vector<int> &B) {
    // Use two pointers 
    // both pointing to first element of the array
    if(A.empty()){
        A = B;
        return;
    }
    if(B.empty())   return;

    const int N=A.size(), M=B.size();
    vector<int> res(N+M);

    int i=0, j=0, k=0;   
    // i points to A and j points to B 
    // k points to resulting array

    while(i<N and j<M){
        // element pointing by i is smaller
        if(A[i]<B[j]){
            res[k] = A[i];
            k++;i++;
        }
        // element pointing by j is smaller equal to i
        else{
            res[k] = B[j];
            k++;j++;
        }
    }

    // Now fill the remaining element of A or B
    while(i<N){
        res[k]=A[i];
        k++;i++;
    }

    while(j<M){
        res[k]=B[j];
        k++;j++;
    }

    A = res;

}
