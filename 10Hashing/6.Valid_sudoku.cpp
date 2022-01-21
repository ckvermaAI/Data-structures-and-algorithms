#include <bits/stdc++.h>
using namespace std;

int isValidSudoku(const vector<string> &A) {
    
    const int ROWS = 9, COLS= 9;
    // HashMap to count the occurence of elements
    unordered_map<char,int> HashMap;

    // check horizontally
    for(int row=0;row<ROWS;++row){
        HashMap.clear();
        for(int col=0;col<COLS;++col){
            char temp = A[row][col];
            if(temp!='.'){
                HashMap[temp]++;
                if(HashMap[temp]>1) return 0;
            }
        }
    }

    // check vertically
    for(int col=0;col<COLS;++col){
        HashMap.clear();
        for(int row=0;row<ROWS;++row){
            char temp = A[row][col];
            if(temp!='.'){
                HashMap[temp]++;
                if(HashMap[temp]>1) return 0;
            }
        }
    }

    // check in box of 3 X 3
    // (r, c) to iterate over the large 3 X 3 boxes
    for(int r=0;r<3;++r){
        for(int c=0;c<3;++c){
            // inside a large box
            // (r,c) = indicates the starting element of 3 X 3 box
            HashMap.clear();
            for(int i=3*r; i<3*r+3; ++i){
                for(int j=3*c; j<3*c+3; ++j){
                    char temp = A[i][j];
                    if(temp!='.'){
                        HashMap[temp]++;
                        if(HashMap[temp]>1) return 0;
                    }
                }
            }
        }
    }

    return 1;
    
}