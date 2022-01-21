// https://www.interviewbit.com/problems/distinct-numbers-in-window/

#include <bits/stdc++.h>
using namespace std;

vector<int> dNums(vector<int> &A, int B) {
    const int N = A.size();
    vector<int> result;

    // Base case
    if(B>N)     return result;

    // use HashMap to keep the count 
    // of the element in window of size B
    unordered_map<int,int> HashMap;
    // {element, count}

    for(int i=0;i<B;++i){
        HashMap[A[i]]++;
    }

    // insert the unique element in first window
    result.push_back(HashMap.size());

    // i indicates the element included in window
    // j indicates element which we want to remove from window
    for(int i=B,j=0;i<N;++i,++j){
        // include ith element
        HashMap[A[i]]++;
        // exclude the jth element 
        HashMap[A[j]]--;
        if(HashMap[A[j]]==0){
            HashMap.erase(A[j]);
        }
        result.push_back(HashMap.size());
    }

    return result;
    
}
