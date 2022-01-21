// https://www.youtube.com/watch?v=7VPA-HjjUmU&list=PL2_aWCzGMAwLL-mEB4ef20f3iqWMGWa25&index=3
// My code school

#include <bits/stdc++.h>
using namespace std;

/*

Check whether N is prime or not
Brute Force approach will be to iterate over all possible 
number b/w [2, N-1]

Key observations =>
b = N/a or a*b = N
all the factors of N always exist in pair, so if N =36
then all pair of factors of 36 are 
{1, 36}, {2, 18}, {3, 12}, {4, 9}, {6, 6}
{9, 4}, {12, 3}, {18, 2}, {36, 1}

so there are 3 possible cases
1) if a==b => a^2 = N      a = sqrt(N)
2) if a<b  => a< sqrt(N) and b >sqrt(N)
3) if a>b  => a> sqrt(N) and b <sqrt(N)

if we see the above factors according to these three cases
we can see that first we encounter case 2) then case 1) and 
at last case 3) - which is repetition of case 2)

Hence, checking till numbers sqrt(N) is sufficient

*/

bool isPrime(int N){
    // to check whether N is prime or not
    // N is positive integer

    if(N<=1){
        return false;
    }

    for(int i=2;i*i<=N;++i){
        if(N%i==0){
            return false;
        }
    }
    return true;
}


int main(){


    return 0;
}