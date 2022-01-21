// https://www.interviewbit.com/problems/intersection-of-sorted-arrays/

#include <bits/stdc++.h>
using namespace std;

vector<int> intersect(const vector<int> &A, const vector<int> &B) {
    // To store the results
    vector<int> res;

    const int N=A.size(), M=B.size();
    // i points to A and j points to B
    int i=0, j=0;
    while(i<N and j<M){
        if(A[i]==B[j]){
            // add to the result
            res.push_back(A[i]);
            // if both elements are equal move both pointers
            i++;j++;
        }
        else if(A[i]<B[j]){
            i++;
        }
        else if(A[i]>B[j]){
            j++;
        }
    }

    return res;
}
