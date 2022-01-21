// https://www.interviewbit.com/problems/maximum-area-of-triangle/

#include <bits/stdc++.h>
using namespace std;

struct cd{
    int x, y;
    cd(int x, int y): x(x), y(y)    {}
};



int solve(vector<string> &A) {
    const int N=A.size(), M=A[0].size();
    // To store the point on the vertical line
    vector<pair<cd,cd>> verticalP;

    // Now first find out the points on the vertical
    int maxDistance = 0;        // to keep track of distance b/w vertical points
    
    for(int col=0;col<M;++col){     // for every column
        for(int i=0;i<N;++i){   // upper point of the vertical line
            for(int j=N-1;j>i;--j){     // lower point of the vertical line

                // Check if both the points on vertical line are different
                if(A[i].substr(col,1)!=A[j].substr(col,1) and j-i>maxDistance){
                    verticalP.push_back({cd(i,col), cd(j,col)});
                    maxDistance = max(maxDistance, j-i);
                }
            }
        }
    }

    int found = 0;
    // Once we find out the points on vertical line
    // find out the point other point
    for(auto &z:verticalP){
        // for every set of points on vertical line 
        // start finding the other point on left or right extreme of the matrix
        for(int col=M-1;col>=0;--col){
            for(int row=0;row<N;++row){
                if(A[row].substr(col,1)!=A[z.first.x].substr(z.first.y,1) and 
                    A[row].substr(col,1)!=A[z.second.x].substr(z.second.y,1)){
                        found = max( (double)found, ceil(0.5* abs(z.second.x - z.first.x+1)* abs(col-z.first.y+1) ) );
                }
            }
            if(found){
                break;
            }
        }
    }
    return found;
}

