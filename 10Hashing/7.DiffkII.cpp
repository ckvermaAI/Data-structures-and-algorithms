// https://www.interviewbit.com/problems/diffk-ii/

#include <bits/stdc++.h>
using namespace std;

int diffPossible(const vector<int> &A, int k) {
    // store the element of array in map
    // so that we can access these element in O(1)
    unordered_map<int,int> HashMap;
    for(int i=0;i<A.size();++i)     HashMap[A[i]]=i;

    // iterate through the array once again
    for(int i=0;i<A.size();++i){
        // consider this element as "A[i]" or "A[j]"
        // then counterpart of this will be "k + A[j]" or "A[i] - k"
        int temp1 = k+A[i], temp2 = A[i]-k;
        if( HashMap.find(temp1)!=HashMap.end() ){
            if(HashMap[temp1]!=i)
                return 1;
        }

        if(HashMap.find(temp2)!=HashMap.end()){
            if(HashMap[temp2]!=i)
                return 1;
        }
    }
    return 0;
}
