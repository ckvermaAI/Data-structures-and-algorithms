// https://www.interviewbit.com/problems/permutations/
// https://stackoverflow.com/questions/46653414/printing-a-list-of-lists-c-stl-list

#include <bits/stdc++.h>
using namespace std;

void get_permutations(vector<int> A, vector<int> &perm, vector<vector<int>> &res){
    // Base case
    if(perm.size()==A.size()){
        res.push_back(perm);
        return;
    }
    // else generate
    for(int i=0;i<A.size();++i){
        if(find(perm.begin(), perm.end(), A[i])==perm.end() ){
            perm.push_back(A[i]);
            get_permutations(A, perm, res);
            perm.pop_back();
        }
    }

}

int main(){
    vector <int> A={1,2,3}, perm;
    vector<vector<int>> result;
    get_permutations(A,perm, result);
    for(const auto &inner:result){
        for(const auto &item:inner){
            cout<<item<<" ";
        }
        cout<<"\n";
    }


    return 0;
}