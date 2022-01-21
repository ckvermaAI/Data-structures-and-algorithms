// https://www.interviewbit.com/problems/sort-by-color/

#include <bits/stdc++.h>
using namespace std;

void sortColors(vector<int> &A) {

    const int N=A.size();
    // Use count sort to sort the elements
    // count the occurence of each color
    vector<int> count(3);    

    // count number of occurence of each colot
    for(int i=0;i<N;++i){
        count[A[i]]++;
    }

    // find the end position of each color
    for(int i=1;i<3;++i){
        count[i] += count[i-1];
    }

    // j will re-write the array
    int j=0;
    for(int i=0;i<3;++i){
        while(j<count[i]){
            A[j++]=i;
        }
    }
    
    return;

}