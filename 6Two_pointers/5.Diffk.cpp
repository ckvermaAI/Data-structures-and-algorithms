// https://www.interviewbit.com/problems/diffk/

#include <bits/stdc++.h>
using namespace std;

int diffPossible(vector<int> &A, int B) {
    const int N = A.size();
    // use two pointers
    int j=1;
    for(int i=0;i<N;++i){
        for(;j<N;++j){
            int temp = A[j]-A[i];
            if(temp==B and i!=j) return 1;
            else if(temp>B){
                // because we are increasing j
                break;
            }
            
        }
    }
    return 0;
}
