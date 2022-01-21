#include <bits/stdc++.h>
using namespace std;

/*

Every number that occurs thrice will either contribute 3 ‘1’s or 3 ‘0’s to the position.

The number that occurs once X will contribute exactly one 0 or 1 to the position depending on whether it has 0 or 1 in that position.

If X has 1 in that position, we will have (3x+1) number of 1s in that position.
If X has 0 in that position, we will have (3x+1) number of 0s in that position.

*/

int singleNumber(const vector<int> &A) {
    const int N = A.size();
    int res=0;
    for(int bit=30;bit>=0;--bit){
        int ones=0;
        for(int i=0;i<N;++i){
            if(A[i] & (1<<bit)){
                ones++;
            }
        }
        if(ones%3){
            res |= (1<<bit);
        }
    }

    return res;
}
