// https://www.interviewbit.com/problems/subset/

#include <bits/stdc++.h>
using namespace std;

void genPerm(vector<int> &A, vector<vector<int>>&res, vector<int>& temp, int start){
    
    // add the temp to res
    res.push_back(temp);
    
    // Base case 
    if(temp.size()==A.size()){
        return;
    }


    for(int i=start;i<A.size();++i){
        temp.push_back(A[i]);
        genPerm(A, res, temp, i+1);
        temp.pop_back();
    }
}


vector<vector<int>> subsets(vector<int> &A) {
    sort(A.begin(), A.end());
    vector<vector<int>> res;
    vector<int> temp;
    genPerm(A, res, temp, 0);
    return res;
}
