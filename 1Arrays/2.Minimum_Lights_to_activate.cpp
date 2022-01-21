// https://www.interviewbit.com/problems/minimum-lights-to-activate/

#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &A, int B) {
    // every bulb has the same power, so if we greedily start from the left 
    // and arrive at a position and pick the rightmost light to cover that
    // position, we will end up getting the minimum number of lights required
    // to cover the whole corridor
    int ans=0;
    int R = B-1;        // right most position for any position
    for(int i=0;i<A.size();++i){
        // for each position explore all the bulb in the neighbourhood 
        // of it 
        bool found = false;
        for(int j=i+R; j>=i-R and j>=0; --j){
            if(A[j]==1){
                found = true;
                ans++;
                i = j+B;    // move B steps forward where current bulb have no light
                break;
            }
        }
        if(!found)  return -1;

    }


    return ans;
}
