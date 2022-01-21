#include <bits/stdc++.h>
using namespace std;

int Solution::maxArea(vector<int> &A) {
    // To maximize the area = B*H
    // we need to max(B) and max(H)
    // to maximize B we can start with 2 pointers
    // one pointing to start and one pointing to end
    
    // How do we move the pointers?
    // we want to maximize the area hence we want to shift
    // to a maximum height

    // to store the ans
    int ans=0;

    const int N = A.size();
    // Two pointers
    int i=0, j=N-1;
    while(i<j){
        // Updating the area
        int Height = min(A[i], A[j]);
        ans = max(ans, Height*(j-i));

        // moving the pointers
        // We want to keep the maximum height with us
        if(A[i]>A[j])   j--;
        else i++;

    }
    return ans;
}

