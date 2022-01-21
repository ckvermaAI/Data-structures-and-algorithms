// https://www.interviewbit.com/problems/n-max-pair-combinations/
// https://www.interviewbit.com/problems/maximum-sum-combinations/
#include <bits/stdc++.h>
using namespace std;


vector<int> Solution::solve(vector<int> &A, vector<int> &B) {
    
    const int N = A.size();
    vector<int> result;

    // sort the array so that we can find maximum
    // in each array easily
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    // first maximum will be the sum of maximum of 
    // element of both array
    priority_queue<tuple<int,int,int>> pq;
    // {sum, pos in array A, pos in array B}
    pq.push({A[N-1]+ B[N-1], N-1, N-1});

    // use HashSet to store the indices of both array 
    // considered so far for the result
    set<pair<int,int>> indices;
    indices.insert({N-1, N-1});

    // next maximum will be either of A[N-2]+ B[N-1]
    // or A[N-1]+B[N-2]

    // while we not extracted the N elements
    int k=N;
    while(k--){

        int sum, L, R;
        tie(sum, L, R) = pq.top();
        pq.pop();

        result.push_back(sum);

        if(R>0 and L>=0 and indices.find({L, R-1})==indices.end()){
            pq.push({A[L]+B[R-1], L, R-1});
            indices.insert({L, R-1});
        }

        if(R>=0 and L>0 and indices.find({L-1, R})==indices.end()){
            pq.push({A[L-1]+B[R], L-1, R});
            indices.insert({L-1, R});

        }
    }
        

    return result;

}
