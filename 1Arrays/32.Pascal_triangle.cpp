// https://www.interviewbit.com/problems/pascal-triangle/
#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > solve(int N) {
    vector<vector<int>> A;
    // empty A for N=0
    if(N==0)    return A;
    
    // A with only one element N=1
    A.push_back(vector<int>{1});
    if(N==1)    return A;
    
    // A with two element N=2
    A.push_back(vector<int>{1});
    if(N==2)    return A;

    while(N>2){
        vector<int> &pr = A.back();
        vector<int> cur(pr.size()+1, 1);

        for(int i=1;i<pr.size();++i){
            cur[i] = pr[i]+pr[i-1];
        }

        A.push_back(cur);
        N--;
    }
    return A;
}
