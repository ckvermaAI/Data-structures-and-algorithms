#include <bits/stdc++.h>
using namespace std;

typedef long double lld;

vector<int> repeatedNumber(const vector<int> &vec) {
    /*
    
    we can same approach so for "First missing integer" problem 
    https://www.interviewbit.com/problems/first-missing-integer/

    approach =>
    as we only have limited number [1, N]
    where the size of array is N
    hence we can create buckets in-place in the given array
    and find out the "first missing integer" or any other
    similar requirement
    
    we have given read only we cannot use the above approach
    Another way to use sum of first N natural numbers

    1+2+3 .... . . .+ N = N*(N+1)/2

    now, A appear twice and B is not present
    hence 

    (1+2+....N) + A - B = ( N*(N+1)/2 )  + A - B
    sum of all elements of array = ( N*(N+1)/2 ) + A - B


    Similarly use sum of square of elements 
    sum of square of all elements of array = ( N*(N+1)*(2*N+1)/6 ) + A^2 - B^2

    TAKE CARE OF OVERFLOWS!!
    
    */
    const int N=vec.size();
    long long X = (long long) ceil( (lld)(N) * ( (lld)(N+1)/2 ) );
    long long Y = (long long) ceil( (lld)(X) * ( (lld)(2*N+1 )/3) );

    for(int i=0;i<N;++i){
        X-=((long long)vec[i]);
        Y-=((long long)vec[i]*vec[i]);
    }

    long long Z = Y/X;
    // B - A = X and B^2 - A^2 = Y
    // B + A = Z
    long long B = Z + (X-Z)/2;
    long long A = B - X;

    return vector<int>{(int)A, (int)B};
}
