// https://www.interviewbit.com/problems/combination-sum-ii/

#include <bits/stdc++.h>
using namespace std;

void getPerm(set<vector<int>> &res, vector<int>&A, vector<int>&temp, int B, int sum, int start){
    // if the sum of element in temp exceeds B
    if(sum>B){
        return;
    }

    // if found the target
    if(sum==B){
        res.insert(temp);
        return;
    }

    for(int i=start;i<A.size();++i){
        temp.push_back(A[i]);
        getPerm(res, A, temp, B, sum+A[i], i+1);
        temp.pop_back();
    }

}


vector<vector<int>> combinationSum(vector<int> &A, int B) {
    sort(A.begin(), A.end());
    vector<int> temp;
    set<vector<int>> res;

    getPerm(res, A, temp, B, 0, 0);

    vector<vector<int>> ans;
    for(auto it=res.begin(); it!=res.end();++it){
        ans.push_back(*it);
    }

    return ans;
}
