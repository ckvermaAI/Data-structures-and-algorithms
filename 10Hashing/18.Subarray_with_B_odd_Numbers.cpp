// https://www.interviewbit.com/problems/subarray-with-b-odd-numbers/
#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &A, int B) {
    int res=0;
    int odd=0;      // keep track of number of odds
    unordered_map<int,int> HashMap;

    for(int i=0; i<A.size();++i){
        odd += ( (A[i]%2)?1:0 );

        if(odd==B)  res++;
        
        if(odd>=B){
            int complimentary = odd-B;
            if(HashMap.find(complimentary)!=HashMap.end()){
                res+= HashMap[complimentary];
            }

        }
        HashMap[odd]++;
    }

    return res;

}