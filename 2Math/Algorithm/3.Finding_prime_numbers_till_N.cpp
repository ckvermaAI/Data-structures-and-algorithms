// https://www.youtube.com/watch?v=eKp56OLhoQs&list=PL2_aWCzGMAwLL-mEB4ef20f3iqWMGWa25&index=4
// https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes

#include <bits/stdc++.h>
using namespace std;

/*

Brute Force approach =>
    for all prime numbers from [2,N] check if each number is prime or not. 
    Time complexity will be O(N^(3/2))

Sieve of Eratosthenes =>
    Efficient algorithm to find all the prime numbers till N
    Key idea => If x is prime number then multiple of x are not prime
                so we need not to iterate over these numbers



*/

vector<int> findAllPrimes(int N){
    // Base case
    if(N<2) return vector<int> {};
    
    // initially all numbers can be prime
    vector<bool> possiblePrimes(true);
    possiblePrimes[0]=false; possiblePrimes[1]=false;

    vector<int> res;

    // Now, we need not to run the outer loop 
    // for till N times we just need to iterate till
    // sqrt(N), because if N is Prime number then it is 
    // sufficient to check till sqrt(N)

    // after the optimized sqrt(N) algorithm we need to 
    // reiterate over the possiblePrimes array to find 
    // all the prime numbers
    for(int i=2;i<=N;++i){
        // if current number is "true" in
        // possiblePrime then add this to result
        if(possiblePrimes[i]){
            res.push_back(i);
            // and set all the multiple of current
            // number to false
            for(int temp=2*i;temp<=N;temp+=i){
                possiblePrimes[temp] = false;
            }
        }
    }

    // Time complexity = O(N* log(log(N)))
    /*
    O(loglog(N)) ==
    N/2 + N/3 + N/5........
    */

    return res;
}

int main(){

    return 0;
}