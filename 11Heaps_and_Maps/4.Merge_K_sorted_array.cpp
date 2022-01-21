// https://www.interviewbit.com/problems/merge-k-sorted-arrays/

#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<vector<int> > &A) {
    // Base cases
    if(A.empty())   return vector<int>{};

    if(A[0].empty())    return vector<int>{};

    // idea is simple use N pointers for N array find the minimum
    // out of these N positions and add it to result
    // move that pointer to next 

    typedef tuple<int,int,int> tu;

    priority_queue<tu, vector<tu>, greater<tu>> pq;

    // insert first N elements in pq
    for(int i=0;i<A.size();++i){
        pq.push({A[i][0], i, 0});
    }

    vector<int> result;
    // now extarct the maximum element
    while(!pq.empty()){

        int element, row, col;
        tie(element, row, col) = pq.top();
        pq.pop();

        result.push_back(element);

        if(col<A[0].size()-1){
            pq.push({A[row][col+1], row, col+1});
        }
        
    }

    return result;

}
