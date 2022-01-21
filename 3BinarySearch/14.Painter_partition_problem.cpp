// https://www.interviewbit.com/problems/painters-partition-problem/
// Problem is similiar to "Allocate Books" Problem

#include <bits/stdc++.h>
using namespace std;


#define MOD 10000003

int Nworkers(vector<int>&A, long long int maxTime){
    int worker=1;
    long long int Ttime = 0;
    for(int &x:A){
        Ttime = (Ttime + (long long int)x)%MOD;
        if(Ttime>maxTime){
            worker++;
            Ttime = x;
        }
    }
    return worker;
}

int paint(int A, int B, vector<int> &C) {
    const int N = C.size();
    long long int low = INT_MIN, high=0;
    // Lower Bound = When we have N == A
    // number of painters == number of boards

    // upper bound = when we have only painter
    // then the time will be maximum
    
    for(int &x:C){
        low = max(low, (long long int)x);
        high = (high+x)%MOD;
    }

    long long int ans = low;
    while(low<=high){
        long long int mid = low + (high-low)/2;
        // for time == mid
        // find out how many worker do we need
        int workers = Nworkers(C, mid);
        if(workers<=A){
            ans = mid;
            // increase the workers
            // or decrease the time
            high = mid -1;
        }
        else{
            low = mid+1;
        }
    }

    return (ans%MOD)*((long long int)B%MOD)%MOD;
}
