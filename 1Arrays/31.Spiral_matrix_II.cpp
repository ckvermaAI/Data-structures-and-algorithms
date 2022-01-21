// https://www.interviewbit.com/problems/spiral-order-matrix-ii/
#include <bits/stdc++.h>
using namespace std;


vector<vector<int> > generateMatrix(int N) {

    vector<vector<int>> A(N, vector<int>(N));

    int len, counter=1;
    int start=0, end=N-1, level=0;

    for(len=N-1; len>0; len-=2){
        // Topmost row
        for(int i=start+level;i<start+len+level;++i){
            A[level][i]=counter++;
            // cout<<"i and j "<<i<<" "<<j<<" counter "<<counter<<"\n";
        }
        // rightMost col
        for(int j=start+level;j<start+level+len;++j){
            A[j][end-level] = counter++;
        }
        // bottomMost row
        int ele=0;
        for(int i=end-level;ele<len;--i, ++ele){
            A[end-level][i] = counter++;
        }

        ele=0;
        for(int j=end-level;ele<len;--j, ++ele){
            A[j][level] = counter++;
        }
        level++;
    }
    if(len==0){
        A[N/2][N/2] = counter;
    }

    return A;
}