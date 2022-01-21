// https://www.interviewbit.com/problems/rain-water-trapped/
#include <bits/stdc++.h>
using namespace std;


int trap(const vector<int> &A) {
    int N=A.size(), res=0;
    vector <int> left(N,0), right(N,0);
    stack <int> num;
    // left array calculation
    num.push(A[0]);
    for(int i=1;i<N;++i){
        left[i]=num.top();
        if(A[i]>num.top())  num.push(A[i]);
    }
    while(!num.empty()) num.pop();

    // right array calculation
    num.push(A[N-1]);
    for(int i=N-2;i>=0;--i){
        right[i]=num.top();
        if(A[i]>num.top())  num.push(A[i]);
    }
    // final calculation
    for(int i=0;i<N;++i){
        int diff=min(left[i], right[i])-A[i];
        res+=max(0,diff);
    }
    return res;
}


int main(){
    vector <int> A={0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout<<trap(A);


    return 0;
}