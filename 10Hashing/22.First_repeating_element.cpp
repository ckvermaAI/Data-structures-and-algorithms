// https://www.interviewbit.com/problems/first-repeating-element/

#include <bits/stdc++.h>
using namespace std;


int solve(vector<int> &A) {
    // Size of the array
    const int N = A.size();
    
    // use HashMap to store the found/discovered elements
    unordered_map<int,int> HashMap;

    for(int i=0;i<N;++i)    HashMap[A[i]]++;
    
    for(int i=0;i<N;++i){
        if(HashMap[A[i]]>1){
            return A[i];
        }
    }
    
    return -1;
    
}
