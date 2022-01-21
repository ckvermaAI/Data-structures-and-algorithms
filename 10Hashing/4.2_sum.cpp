// https://www.interviewbit.com/problems/2-sum/
#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(const vector<int> &A, int B) {
    const int N = A.size();
    // we can use HashMap to get the array elements in O(1)
    unordered_map<int,int> HashMap;

    // store the element of array in HashMap
    for(int i=0;i<N;++i){
        // HashMap will store the index1
        if(HashMap.find(A[i])==HashMap.end())
            HashMap[A[i]]=i;
    }

    int ind1=INT_MAX, ind2=INT_MAX;
    // iterate through the index2
    for(int i=0;i<N;++i){
        int temp = B - A[i];
        if(HashMap.find(temp)!=HashMap.end()){
            int index1 = HashMap[temp];
            if(index1<i  and (i<ind2 or (i==ind2 and index1<ind1)) ){
                ind1 = index1;
                ind2 = i;                
            }
        }
    }
    if(ind1==INT_MAX)
        return vector<int> {};

    return vector<int> {ind1+1, ind2+1};
}
