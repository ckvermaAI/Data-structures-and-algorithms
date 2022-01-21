// https://www.interviewbit.com/problems/equal/
#include <bits/stdc++.h>
using namespace std;

bool compare(vector<int>A, vector<int> B){
    // comparing two vectors
    int N=A.size();
    for(int i=0;i<N;++i){
        if(A[i]==B[i])  continue;
        else if(A[i]<B[i])  return true;
        else return false;
    }
    return true;
}

vector<int> equal(vector<int> &A) {
    int N=A.size();
    vector<int> res(4,INT_MAX);
    unordered_map<int,pair<int,int>> num;
    // storing first occurence of "A[i]+A[j]" in num
    for(int i=0;i<N;++i){
        for(int j=i+1;j<N;++j){
            int sum=A[i]+A[j];
            // store the first occurence of the sum
            if(num.find(sum)==num.end())
                num[sum]={i,j};
        }
    }
    // re-iterating over the pair of numbers to acheive goal
    for(int i=0;i<N;++i){
        for(int j=i+1;j<N;++j){
            int current_sum=A[i]+A[j];
            if(num.find(current_sum)!=num.end()){
                pair<int,int> start=num[current_sum];
                if(start.first<i and start.second!=j and start.second!=i){
                    vector<int> temp={start.first,start.second,i,j};
                    if(compare(temp,res))   res=temp;
                }
            }
        }
    }
    if(res[0]==INT_MAX)   return vector <int>{};
    return res;
}


