// https://www.interviewbit.com/problems/longest-common-prefix/

#include <bits/stdc++.h>
using namespace std;


string longestCommonPrefix(vector<string> &A) {
    const int N = A.size();
    // sort the array
    sort(A.begin(), A.end());

    // pick the distant strings
    string first = A[0], last = A[N-1];
    int M = min(first.size(), last.size());
    int res=0;
    for(int i=0;i<M;++i){
        if(first[i]==last[i])   res++;
        else    break;
    }
    return res;
}
