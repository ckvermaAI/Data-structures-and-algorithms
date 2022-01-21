// https://www.interviewbit.com/problems/subarray-with-given-xor/
// https://www.geeksforgeeks.org/count-number-subarrays-given-xor/
#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &A, int B) {
    int N=A.size(), res=0;
    // prefix_XOR array calculation
    vector <int> prefix_XOR(N);
    prefix_XOR[0]=A[0];
    for(int i=1;i<N;++i)    prefix_XOR[i]=prefix_XOR[i-1]^A[i];
    // Hash table to store the previously occured subarray
    unordered_map<int,int> num;
    // final iteration
    for(int i=0;i<N;++i){
        int complement= prefix_XOR[i] ^ B;
        // if a complement exist in previously visited subarray
        res+=(num[complement]);

        // check if the current subarray XOR sum is B
        if(prefix_XOR[i]==B)    res++;

        // Insert current subarray in Map
        num[prefix_XOR[i]]++;
    }
    return res;
}

int main(){


    return 0;
}
