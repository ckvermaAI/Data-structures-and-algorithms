#include <bits/stdc++.h>
using namespace std;

vector <int> solve(vector <int> A){
    int N=A.size();
    // other cases
    vector <int> left(N,-1);
    stack <int> num;
    // "left" calculations
    num.push(A[0]);
    for(int i=1;i<N;++i){
        if(num.top()>=A[i]){
            while(!num.empty()){
                if(A[i]<=num.top())   num.pop();
                else break;
            }
        }
        if(!num.empty())    left[i]=num.top();
        num.push(A[i]);
    }
    return left;
}

int main(){
    vector <int> A={4,5,2,10,8},B;
    B=solve(A);
    for(int i=0;i<B.size();++i) cout<<B[i]<<" ";
    return 0;
}