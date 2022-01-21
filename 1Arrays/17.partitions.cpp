// https://www.interviewbit.com/problems/partitions/

#include <bits/stdc++.h>
using namespace std;


int solve(int N, vector<int> &A) {
    // use a map to obtain the sum of a interval in O(1) Time complexity
    // to store the {prefix sum, index}
    unordered_map<int,vector<int>> prefix;

    // also find out the prefix sum array
    vector<int> pArr(N);

    pArr[0] = A[0];
    prefix[A[0]].push_back(0);

    for(int i=1;i<N;++i){
        pArr[i] = pArr[i-1] + A[i];
        prefix[pArr[i]].push_back(i);
    }


    int count = 0;
    for(int i=0;i<N-2;++i){     
        // because each interval cannot be empty that's why these range of values
        int first = pArr[i];        // sum of first set
        int pArrj = first + pArr[i];   // possible value of pArr[j]

        // check if this is available in map
        if(prefix.find(pArrj)!=prefix.end()){
            vector<int> jPos = prefix[pArrj];
            for(int &j:jPos){
                if(j>i and j<N-1 and first==pArr[N-1]-pArr[j]){      // valid j
                    count++;
                }
            }
        }

    }

    return count;
}


