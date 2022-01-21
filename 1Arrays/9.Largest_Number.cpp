// https://www.interviewbit.com/problems/largest-number/

#include <bits/stdc++.h>
using namespace std;

bool sCompare(string A, string B){
    string AB = A.append(B);
    string BA = B.append(A);
    return (AB.compare(BA)> 0)?1:0 ;
}

string largestNumber(const vector<int> &s) {
    const int N=s.size();
    vector<string> A(N);

    for(int i=0;i<N;++i){
        A[i] = s[i]+"0";
    }

    // sort the array
    sort(A.begin(), A.end(), sCompare);

    string res="";
    for(auto &x:A)  res+=x;

    return res;
}

