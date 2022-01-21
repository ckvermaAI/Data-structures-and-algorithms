// https://www.interviewbit.com/problems/gray-code/

#include <bits/stdc++.h>
using namespace std;

/*

Let G(n) represent a gray code of n bits.
Note that reverse of G(n) is also a valid sequence.
Let R(n) denote the reverse of G(n).

Note that we can construct
G(n+1) as the following :
0G(n)
1R(n)

Where 0G(n) means all elements of G(n) prefixed with 0 bit and 1R(n) means all elements of R(n) prefixed with 1.
Note that last element of G(n) and first element of R(n) is same. So the above sequence is valid.

Example G(2) to G(3) :
0 00
0 01
0 11
0 10
1 10
1 11
1 01
1 00

*/

void solve(vector<int> &result, int counter, int N){
    // Base case
    if(counter==N){
        return;
    }

    // create a array which is reversed of original array
    vector<int> revArr = result;
    reverse(revArr.begin(), revArr.end());

    // shift each element of this array to left by one bit
    for(int &x:revArr)  result.push_back(x+pow(2, counter));

    solve(result, counter+1, N);

    return;

}


vector<int> grayCode(int N) {

    vector<int> result = {0,1};
    int counter=1;
    solve(result, counter, N);
    
    return result;
}
