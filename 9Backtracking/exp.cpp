// https://www.interviewbit.com/problems/combination-sum-ii/

#include <bits/stdc++.h>
using namespace std;

void generate_perm(vector <int> &A, vector <vector<int>>&res, vector <int>&perm
    , map<int, int> &counter, map<int, int> &restrictions, int B){
    // validating
    long long sum_=0;
    for(int &x:perm){
        sum_+=x;
    }   
    if(sum_==B){
        for(auto &x:counter){
            if(x.second>restrictions[x.first]) return;
        }
        res.push_back(perm);
    } 

    // Base conditions
    if(sum_>=B)   return;
    
    // Recursion
    for(int i=0;i<A.size();++i){
        int x=A[i];
        bool constraint=true;
        if(!perm.empty()){
            if(perm.back()>x)   constraint=false;
        }
        if(constraint ){
            counter[x]++;
            perm.push_back(x);
            generate_perm(A,res,perm, counter, restrictions, B);
            perm.pop_back();
            counter[x]--;
        }
    }
}

vector<vector<int>> subsets(vector<int> &A, int B) {
    map<int, int> counter, restrictions;
    set<int> temp;
    for(int &x:A){
    restrictions[x]++;
    temp.insert(x);
    }
    A.clear();
    for(int x:temp) A.push_back(x);
    vector<vector <int>>res;
    vector <int> perm;
    generate_perm(A, res, perm, counter, restrictions,B);
    return res;
}

int main(){
    vector <int> A={10,1,2,7,6,1,5 };
    vector <vector <int>> res=subsets(A,8);
    for(const auto &inner:res){
        for(const auto &num:inner) cout<<num<<" ";
        cout<<"\n";
    }

    return 0;
}