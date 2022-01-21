// https://www.interviewbit.com/problems/rearrange-array/

#include <bits/stdc++.h>
using namespace std;

void arrange(vector<int> &A) {
   /*

   we cannot solve this problem in constant or O(1) space
   we definitely required some extra space

   can we store the information in the same place in the array
   also it is given that N*N does not overflow for a signed integer
   Hence, 
    if we store the previous state as "pre"
    and current state as "curr" then we can store both of them at
    place in the array
    => final num = "pre" + N * "curr"
    and we can extract "pre" using "%N"
    and extract "curr" using "/N" operation
   
    Algorithm =>
    1) traverse the array and upadte current element
    2) "pre" = A[i] and "curr" = A[A[i]]
    3) set A[i] = A[i] + curr*N

   */
    const int N = A.size();
    for(int i=0;i<N;++i){
        int ele = A[A[i]];
        if(ele>=N){
            ele = ele%N;
        }
        A[i] += ele*N;
    }

    for(int i=0;i<N;++i){
        A[i] = (A[i]/N);
    }

}