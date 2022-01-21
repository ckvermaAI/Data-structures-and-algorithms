// By errichto
// Bitwise Operations tutorial #1 | XOR, Shift, Subsets 
// https://www.youtube.com/watch?v=xXKL9YBWgCY


#include <bits/stdc++.h>
using namespace std;

/*

Subset Sum =>

    Problem statement
    You are given N number. check if there is a subset of them with
    sum equal to target value S.
    N<=20

    
    Recursion => for each we have two options either choose the number or 
    drop (do not use the number). Hence, the recusion tree will be like
    for each element either we choose that element or do not choose that 
    element
    Time complexity = O(2^N)

    
    Idea =>
    For each number we have two option so we can represent the absence or 
    presence of each number using bits.
    and for the set of number we can represent this using multiple bits
    
    Example => for the above problem, we can use 20 bits to represent the
    absence and presence of each bits. If any of the bit is "1" it indicates
    that corresponding element is present
    
    0000...001  this represent that element at 0th index is present
                because the least significant digit correspondes to index 0
    
    The representation of number of set using bits is called "bit mask"


    
    Iterative version => 
    Using the above idea, we can represent a particular subset using 
    "Bit mask" and we will iterate over all possible bitmask (2^N)
    and check whether that subset of array will provide us the target 
    sum

    Time Complexity = O(2^N * N)

    We can reduce the time complexity further by using dynamic programmming
    use shorter mask to find the answer for larger mask
    Time complexity = O(2^N * N)

*/

void solve(vector<int> &A, int Target){
    // Time Complexity = O(2^N * N)
    const int N = A.size();

    for(int mask=0; mask<(1<<N); ++mask){
        // to store the sum of this subset
        long long sum_of_this_subset = 0;

        // Iterate through all the bits
        for(int i=0;i<N;++i){
            if( mask & (1<<i) ){
                sum_of_this_subset +=  A[i];
            }
        }

        // If found the subset having sum == 
        if(sum_of_this_subset==Target){
            puts("YES");
            return;
        }
    }
    puts("NO");
}





int main(){


    return 0;
}