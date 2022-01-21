// https://www.interviewbit.com/problems/min-steps-in-infinite-grid/

#include <bits/stdc++.h>
using namespace std;


int coverPoints(vector<int> &A, vector<int> &B) {
    // solve this problem by "optimize DIY (Do it yourself)"
    // we can see that minimum number of steps required will be the 
    // maximum of number of steps in either of two direction
    
    const int N=A.size();
    int steps=0;
    for(int i=1;i<N;++i){
        steps += max( abs(A[i]-A[i-1]), abs(B[i]-B[i-1]) );
    }
    return steps;
}
