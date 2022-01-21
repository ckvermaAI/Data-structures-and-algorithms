// https://www.interviewbit.com/problems/nearest-smaller-element/
#include <bits/stdc++.h>
using namespace std;

vector<int> prevSmaller(vector<int> &A) {
    const int N = A.size();
    vector<int> left(N, -1);
    stack<int> num;
    num.push(0);

    for(int i=1;i<N;++i){
        if(A[num.top()]>=A[i]){
            while(!num.empty() and A[num.top()]>=A[i]){
                num.pop();
            }
        }
        if(!num.empty())    left[i]=A[num.top()];
        num.push(i);
    }
    return left;
}
