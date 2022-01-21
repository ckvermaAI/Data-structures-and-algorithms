// https://www.interviewbit.com/problems/remove-consecutive-characters/
#include <bits/stdc++.h>
using namespace std;

string solve(string A, int B) {
    const int N = A.length();
    string res = "";
    int index = 0, count = 1;
    for(int i=1;i<N;++i){
        if(A[i]==A[index]){
            count++;
        }
        else{
            // add the last chunk 
            if(count!=B){
                res += string(count, A[index]);
            }
            // reset the index and count
            index = i;
            count=1;
        }
    }
    if(count!=B){
        res += string(count, A[index]);
    }
    return res;
}
