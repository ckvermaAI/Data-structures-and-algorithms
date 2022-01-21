// https://www.interviewbit.com/problems/zigzag-string/

#include <bits/stdc++.h>
using namespace std;


string convert(string A, int ROWS) {
    // Base Case
    if(A.empty())   return "";
    if(ROWS==1)    return A;

    // General Case
    vector<string> res(ROWS, "");
    res[0] += A[0];

    const int N = A.length();
    // start inserting other elements
    int i=1;
    while(i<N){
        // insert the element in ROWS = [2, ROWS]
        int elements = ( ((N-i)>(ROWS-1))?(ROWS-1):(N-i) );
        
        // start from second row and insert the available elements
        // in downward direction
        for(int row=1;row<=elements;++row){
            res[row] += A[i++];
        }

        // insert the element in ROWS = [ROWS-1, 1]
        elements = ( ((N-i)>(ROWS-1))?(ROWS-1):(N-i) );
        
        // start from last second row and insert the available elements
        // in upward direction
        int row = ROWS-2;
        while(elements--){
            res[row--] += A[i++];
        }
     
    }
    string ans="";
    for(auto &x:res){
        ans+=x;
    }    

    return ans;
}
