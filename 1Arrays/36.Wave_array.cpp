// https://www.interviewbit.com/problems/wave-array/

#include <bits/stdc++.h>
using namespace std;


vector<int> wave(vector<int> &A) {
    /*
    
    General observation:
    Input = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}

    Output = {2, 1, 4, 3, 6, 5, 8, 7, 10, 9};

    Elements at even position shift to odd position 
    and elements at odd position shift to even position    
    */
    const int N=A.size();

    // sort the array such that we Input in above format
    sort(A.begin(), A.end());
    vector<int> res(N);

    for(int i=0;i<N-1;i+=2){   // Iterate through the even position
        // put these values in odd position in resulting array
        res[i+1] = A[i];
    }

    for(int i=1;i<N;i+=2){  // Iterate through the odd position
        // put these values in even position in resulting array
        res[i-1] = A[i];
    }

    if(N%2){
        res[N-1]=A[N-1];
    }
    
    return res;
}

