// https://www.interviewbit.com/problems/square-root-of-integer/

#include <bits/stdc++.h>
using namespace std;


int sqrt(int A) {
    // Base case
    if(A==0 or A==1)    return A;
    
    // General case
    // Use binary search b/w range [1, A/2]
    int low = 1, high = A/2;
    while(low<=high){
        int mid = low + (high-low)/2;
        if((long long int)mid*mid<=A and A<((long long int)mid+1)*(mid+1) ){
            // because we want the floor(sqrt(A))
            return mid;
        }
        else if((long long int)mid*mid>A){
            // search on left
            high = mid-1;
        }
        else{
            // search on right
            low = mid+1;
        }
    }
    return 1;
}
