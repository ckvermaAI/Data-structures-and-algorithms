
#include <bits/stdc++.h>
using namespace std;


int solve(int A, int B) {
    // to find out the total position bishop can visit in one move
    // is to count the number of diagonals and off diagonals
    // the property of diagonals element is that the diff of position
    // will remain same while for off-diagonal the summation of all
    // position will remain same
    int count=0;
    for(int i=1;i<=8;++i){
        for(int j=1;j<=8;++j){
            if( (i-j)==(A-B) or (i+j)==(A+B) ){
                count++;
            }
        }
    }
    return count-1;
}
