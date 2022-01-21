// https://www.interviewbit.com/problems/implement-strstr

#include <bits/stdc++.h>
using namespace std;

vector<int> computePrefix(string &A){
    // function to compute the prefix array for KMP algorithm
    vector<int> prefix(A.size());
    int border=0;
    prefix[0]=border;
    for(int i=1;i<A.size();++i){
        while(border>0 and A[border]!=A[i]){
            border = prefix[border-1];
        }
        if(A[border]==A[i]){
            border = border+1;
        }
        else{
            border=0;
        }
        prefix[i]=border;
    }
    return prefix;
}

int strStr(const string text, const string pattern) {
    // base case
    if(text.empty() or pattern.empty()) return -1;
    if(pattern.size()>text.size())  return -1;

    // Just application of standard KMP
    // Knuth Morris Pratt Algorithm

    string A = pattern+"$"+text;
    // create the prefix array
    vector<int> prefix = computePrefix(A);

    // iterate through the prefix
    for(int i=pattern.size()+1;i<A.size();++i){
        if(prefix[i]==pattern.size()){
            return i-2*pattern.size();
        }
    }
    return -1;

}
