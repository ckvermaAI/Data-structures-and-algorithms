// https://www.interviewbit.com/problems/array-3-pointers/

#include <bits/stdc++.h>
using namespace std;


int minimize(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
    // To store the result
    int ans=INT_MAX;
    
    // Use three pointers
    int i=0, j=0, k=0;
    // {A, B, C} == pointers {i, j, k}

    while(i<A.size() and j<B.size() and k<C.size()){
        int temp_max = max({A[i], B[j], C[k]});
        int temp_min = min({A[i], B[j], C[k]});
        if(ans>temp_max-temp_min){
            ans = temp_max-temp_min;
        }
        // we want this difference to minimize further
        // we can do this by increasing the minimum element
        if(temp_min==A[i])  i++;
        else if(temp_min==B[j])  j++;
        else k++;
    }

    return ans;
}
