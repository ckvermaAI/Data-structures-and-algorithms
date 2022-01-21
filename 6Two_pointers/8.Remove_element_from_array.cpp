// https://www.interviewbit.com/problems/remove-element-from-array/

#include <bits/stdc++.h>
using namespace std;

int removeElement(vector<int> &A, int B) {
    // Use two pointers
    // one will iterate over original array = i
    // one over modified array  = j
    // It is crucial when to increment one pointer

    const int N = A.size();
    int j = 0;
    for(int i=0;i<N;++i){
        if(A[i]==B) continue;
        else{
            A[j]=A[i];
            j++;
        }
    }
    return j;
}
