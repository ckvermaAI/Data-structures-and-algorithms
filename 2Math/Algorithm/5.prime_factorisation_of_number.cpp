// https://www.youtube.com/watch?v=6PDtgHhpCHo&list=PL2_aWCzGMAwLL-mEB4ef20f3iqWMGWa25&index=6

#include <bits/stdc++.h>
using namespace std;

/*

different Factorization of N = 24
24 = 2 * 12
24 = 3 * 8
24 = 2 * 3 * 4
24 = 2* 2* 2* 3     => all factors are prime

There is only one prime factorisation possible for a number N

How to find all prime factors of a number N =>
1) keep on dividing the number with smallest prime number
2) once quotient is not divisible by current prime number 
   move to next prime number

*/

void PrimeFactorisation(int N){
    // to store the frequency of "i" in prime factorisation 
    // of number N

    for(int i=2;i*i<=N and N>1;++i){
        // if current number divides 
        if(N%i==0){
            int count = 0;
            while(N%i==0){
                N = N/i;
                count++;
            }
            cout<<"Num is "<<i<<" and freq is "<<count<<"\n";
        }
    }
    // once we come out of this loop either N = 1 or primeNum
    if(N!=1){
        cout<<"Num is "<<N<<" and freq is 1\n";
    }

 
    /*
    One obvious quesion can be : we are iterating through all
    the numbers from [2, limit] didn't we include the composite 
    number in this way (because we are not making sure i is prime)
    But this case wil not be possible

    lets say if 6 divides N then factors(other than 1) of 6 = {2, 3}
    already divides the number N
    
    */

}


int main(){

    return 0;
}