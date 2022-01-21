// https://www.interviewbit.com/problems/count-and-say/

#include <bits/stdc++.h>
using namespace std;

string nextNum(string A){
    string res ="";

    int index=0, count=1;
    for(int i=1;i<A.size();++i){
        if(A[i]==A[index])  count++;
        else{
            // add the last chunk
            res += to_string(count);
            res += A[index];
            
            // update index and count
            index = i;
            count = 1;
        }
    }
    // add the last chunk
    res += to_string(count);
    res += A[index];

    return res;
}

string countAndSay(int A) {
    string prev = "1";  A--;
    while(A--){
        prev = nextNum(prev);
    }
    return prev;
}
