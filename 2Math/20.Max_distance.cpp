// https://www.interviewbit.com/problems/max-distance/

#include <bits/stdc++.h>
using namespace std;


int maximumGap(const vector<int> &A) {
    int n=A.size();
    int diff=numeric_limits<int>::min();
    vector <pair<int,int>> A_index(n);
    for(int i=0;i<n;++i)
        A_index[i]=make_pair(A[i],i);
    sort(A_index.begin(),A_index.end());
    vector <int> suffix(n);
    suffix[n-1]=A_index[n-1].second;
    for(int i=n-2;i>=0;--i)
        suffix[i]=max(suffix[i+1], A_index[i].second);

    for(int i=0; i<n;++i)
        diff=max(diff, suffix[i]-A_index[i].second);
        
    return diff;
}

int main(){
    
}