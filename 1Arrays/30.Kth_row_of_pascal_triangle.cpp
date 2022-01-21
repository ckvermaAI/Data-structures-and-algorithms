// https://www.interviewbit.com/problems/kth-row-of-pascals-triangle/

#include <bits/stdc++.h>
using namespace std;

vector<int> getRow(int A) {
    // Base case
    if(A==0)    return vector<int> {1};

    // other wise start from 
    vector<int> res = {1,1};
    while(A>=1){
        vector<int> temp(res.size()+1, 1);
        for(int i=1;i<res.size();++i){
            temp[i]=res[i-1]+res[i];
        }
        res=temp;
        A--;    
    }
    return res;
}