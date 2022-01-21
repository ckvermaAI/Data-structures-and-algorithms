// https://www.youtube.com/watch?v=umt7t1_X8Rc

#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &A){
    // Kadane algorithm
    // O(N) time complexity and O(1) space complexity
    int ans=INT_MIN, a=0;
    for(int &x:A){
        a +=x;
        ans=max(a, ans);
        a=max(a, 0);
    }
    return ans;
}


int main(){


    return 0;
}