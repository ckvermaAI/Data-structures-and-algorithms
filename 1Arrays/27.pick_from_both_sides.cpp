// https://www.interviewbit.com/problems/pick-from-both-sides/

#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &A, int B) {
    // we can solve this problem using greedy approach
    // just pick the largest element - No greedy does not work
    // we need to iterate over each of the possible combination
    // can we reduce the repetitive work ( BUD - Bottle neck , unneccessary and duplicated work)
    // yes we can optimize our brtue force approach using by avoiding the duplicated work

    // so start with first B element and store the sum
    int ans = 0;
    for(auto i=0;i<B;++i)   ans+= A[i];         // first iteration
    
    // use two pointers
    int i=B-1, j=A.size()-1, sum=ans;

    // iterate through all the possible combinations
    while(B--){ // we need to do in total B-1 iteration
        sum = sum + A[j] - A[i];
        i--;j--;
        if(sum>ans){
            ans=sum;
        }
    }

    return ans;
}

