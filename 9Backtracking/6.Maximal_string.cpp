// https://www.interviewbit.com/problems/maximal-string/

#include <bits/stdc++.h>
using namespace std;

void MaximalString(string &A, int B, string &ans){
    // if there are no swaps left
    if(B==0){
        ans = max(ans, A);
        return;
    }

    // swap
    for(int i=0;i<A.size();++i){
        for(int j=0;j<A.size();++j){
            string temp = A;
            swap(A[i], A[j]);
            if(A>temp){
                MaximalString(A, B-1, ans);
            }
        }
    }


}


string solve(string A, int B) {
    string ans = A;
    MaximalString(A, B, ans);
    return ans;
}
