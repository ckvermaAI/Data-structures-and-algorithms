// https://www.interviewbit.com/problems/pairs-with-given-xor

#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &A, int B) {
    /*
    Based on this property =>
    A ^ B = C 
    B ^ C = A 
    A ^ C = B
    */

    // store all the element in the HashMap
    unordered_map<int, int> HashMap;

    // insert all the elements in the HashMap
    for(int i=0;i<A.size();++i)     HashMap[A[i]]=i;

    int count=0;
    // reiterate through the array
    for(int i=0;i<A.size();++i){
        int temp = A[i]^B;
        if(HashMap.find(temp)!=HashMap.end()){
            if(HashMap[temp]!=i){
                count++;
            }
        }
    }
    return count/2;
}
