// https://www.interviewbit.com/problems/combination-sum/

#include <bits/stdc++.h>
using namespace std;

void getPerm(vector<vector<int>> &res, vector<int>&A, vector<int>&temp, int B, int sum, int start){
    // if the sum of element in temp exceeds B
    if(sum>B){
        return;
    }

    // if found the target
    if(sum==B){
        res.push_back(temp);
        return;
    }

    for(int i=start;i<A.size();++i){
        temp.push_back(A[i]);
        getPerm(res, A, temp, B, sum+A[i], i);
        temp.pop_back();
    }

}


vector<vector<int> > combinationSum(vector<int> &A, int B) {
    sort(A.begin(), A.end());
    A.erase(unique(A.begin(), A.end()), A.end());
    vector<int> temp;
    vector<vector<int>> res;

    getPerm(res, A, temp, B, 0, 0);

    return res;
}
