// errichto
// C++ Bitsets in Competitive Programming
// https://www.youtube.com/watch?v=jqJ5s077OKo


#include <bits/stdc++.h>
using namespace std;


/*

Problem => You are given N<=10^7 numbers, each b/w 0 and 10^9.
How many different values appear in sequence? Each number is integer.

Solution1 =>
we can simply use set, insert every integer in a set and check the size of
set at end. 
Time complexity = O(N*log(N)), it will be too slow given N<=10^7

Unordered_set is also quiet slow given that it is O(N) expected.


Solution2 =>

a) Create a boolean array visited
   "bool vis[10^9 + 1]"
   But each boolean value takes one byte and we are storing 1 billon bytes
   or 1Giga Bytes

b) Create a bitset of instead of boolean array
    It will consume 10^9 bits or 8 times less memory than boolean array
    It will use 128MB of memory.
    
    "bitset<10^9+1> vis"

    Time complexity is linear and time to create the bitset is very fast


This will not work for general case when the range of number [1, 10^18]
because in that case we cannot create that big "BITSET"

*/

int main(){

    const int MAX_N = 1e9+1;
    bitset<MAX_N> visited;

    int N=10;    
    for(int i=0;i<N;++i){
        int x;
        cin>>x;
        visited[x]=true;
    }

    cout<<visited.count();

    return 0;
}