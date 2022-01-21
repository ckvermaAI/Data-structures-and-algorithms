// https://www.interviewbit.com/problems/sorted-permutation-rank/

#include <bits/stdc++.h>
using namespace std;

int fact(int N){
    if(N<=1)    
        return N;
    return (int)((long long int)N*fact(N-1)%1000003);
}


int findRank(string A) {
    const int N = A.length();

    // at any position i the only available character we can use are
    // which are present on the right (because elements on the left are used)

    // so we need to find out the number of elements that are smaller 
    // than current elements 
    vector<int> position(N);
    for(int i=0;i<N;++i){
        int count=0;
        for(int j=i+1;j<N;++j){
            if(A[i]>A[j]){
                count++;
            }
        }
        position[i]=count;
    }

    // Now just count the number number of position possible before
    // current element
    long long int res=0;
    for(int i=0;i<N;++i){
        res += (int)((long long int)position[i]*fact(N-i-1)%1000003);
    }

    return (res+1)%1000003;
}