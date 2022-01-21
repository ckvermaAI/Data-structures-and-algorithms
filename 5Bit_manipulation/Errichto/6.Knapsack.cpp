// errichto
// C++ Bitsets in Competitive Programming
// https://www.youtube.com/watch?v=jqJ5s077OKo


#include <bits/stdc++.h>
using namespace std;


/*

KNAPSACK PROBLEM
you are given N<1000, each with some weight w[i]. Is there a subset with
total weight exactly W?     W<=10^6


Standard DP solution =>
Time complexity = O(N.W)

create a boolean array of size "W+1" initially dp[0] = true, then we iterate
through all possible weight and check if that weight is possible or not


BITSET SOLUTION =>
We can consider the state of DP as bit mask and when we encounter 
that next state is also possible we can use "BITWISE OR" operation
Time Complexity = O(N* (W/32) )

*/

// standard DP solution
const int MAX_W=10;
// bool can[MAX_W];

// int main(){
//     int n, W;
//     cin>>n>>W;
//     can[0] = true;
//     for(int id=0;id<n;++id){
//         int x;
//         cin>>x;
//         for(int i=W;i>=x;--i){
//             if(can[i-x])    can[i] = true;
//         }
//     }
//     puts(can[W]?"YES":"NO");
// }


// Bitset solution
bitset<MAX_W> can;
int main(){
    int n, W;
    cin>>n>>W;
    can[0] = true;
    for(int id=0;id<n;++id){
        int x;
        cin>>x;
        can = can | (can<<x);   // or just:  can |= (can<<x);
    }
    puts(can[W]?"YES":"NO");
}