// https://www.interviewbit.com/problems/subsets-ii/

#include <bits/stdc++.h>
using namespace std;

void genPerm(set<vector<int>>&res, vector<int>&A, vector<int>&temp, int start){
    
    res.insert(temp);

    // Base case
    if(temp.size()==A.size()){    
        return;
    }

    for(int i=start;i<A.size();++i){
        temp.push_back(A[i]);
        genPerm(res, A, temp, i+1);
        temp.pop_back();
    }

    return;

}

bool compare(vector<int>&A, vector<int>&B){
    int N = min(A.size(), B.size());
    for(int i=0;i<N;++i){
        if(A[i]==B[i])  continue;
        else if(A[i]<B[i])  return true;
        else    return false;
    }
    // if A is smaller
    if(N==A.size()){
        return true;
    }
    return false;
}

vector<vector<int>> subsetsWithDup(vector<int> &A) {
    sort(A.begin(), A.end());
    // to store the result from genPerm
    set<vector<int>> res;

    // auxiliary array
    vector<int> temp;

    genPerm(res, A, temp, 0);

    vector<vector<int>> ans;
    for(auto it=res.begin(); it!=res.end();++it){
        ans.push_back(*it);
    }

    sort(ans.begin()+1, ans.end(), compare);

    return ans;

}
