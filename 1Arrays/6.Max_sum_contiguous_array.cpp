// https://www.interviewbit.com/problems/max-sum-contiguous-subarray/

#include <bits/stdc++.h>
using namespace std;

int maxSubArray(const vector<int> &A) {
    // Basic use case of kadane's algorithm
    int ans=INT_MIN, till=0;
    for(auto x:A){
        till+=x;
        ans=max(ans, till);
        till = max(till, 0);
    }
    return ans;
}
