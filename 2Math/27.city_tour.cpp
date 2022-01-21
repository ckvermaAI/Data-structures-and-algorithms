// https://www.interviewbit.com/problems/city-tour/

#include <bits/stdc++.h>
using namespace std;

#define MOD 1000'000'007

void computeFact(vector<long long int>&fact){
    fact[0]=1;
    fact[1]=1;
    for(int i=2;i<fact.size();++i){
        fact[i] = ((fact[i-1]%MOD)*i)%MOD;
    }   
}


long long int modPow(long long int a, long long int N){
    // a is base 
    // N is exponent
    if(N<=0)    return 1;
    if(N==1)    return a;

    long long int res = modPow(a, N/2)%MOD;
    res = (res*res)%MOD;

    if(N & 1){
        res = (a*res)%MOD;
    }
    return res;
}


void calculateGaps(vector<int>&temp, vector<int> &B, int A){
    temp.push_back(B[0]-1);
    for(int i=1;i<B.size();++i){
        temp.push_back(B[i]-B[i-1]-1);
    }
    temp.push_back(A-B.back());
}

int solve(int A, vector<int> &B) {
    /*
    
    for example:
        A = 15 and B = {4, 9, 12}

        1  2  3  "4"  5  6  7  8  "9" 10  11  "12"  13  14  15

        Now, cities "4" and "11" are visited and we can only visit the other
        cities in certain order - visit the neighbours of visited cities

        a) There is only one order for the element to the leftmost visited cities
            we can only visit {1, 2, 3} in 3 -> 2 -> 1
            similarly, for the element which are on the right of righmost visited city
            we can only visit {13, 14, 15} in 13 -> 14 -> 15

        b) remaining cities (which are unvisited) are sandwiched b/w two visited cities
            set1 = {5, 6, 7, 8} and set2 = {10, 11}
            Now, to visit the cities in each set we have 2 possibilities at each time
            we visit next city
            for example -> in starting when we want to visit the set1 we can either 
            visit 5 or 8, after that (if we choose 5) we have 2 option either we can choose
            6 or 8 and so on.
            so total possibilites are 2^(Setsize-1)

        c) finally we have total "A - B.size()" cities unvisited. So we in total we have
            (A-B.size())! possibilities or "12!"
            But, to handle case (a) we have to do some reduction or "(12!)/(3! * 3! )"
            and for case (b)  "((12!)/(3! * 3! * 4! * 2!))*(2^3 * 2^1)"

    */
    sort(B.begin(), B.end());
    // total number of unvisited cities
    int N = A-B.size();

    // Calculate the number of unvisited in each set
    /*
    for example in the above example we have 4 sets
    set1 = {1, 2, 3}, set2 = {5, 6, 7, 8}, set3 = {10, 11}
    set4 = {13, 14, 15}
    */
    vector<int> temp;
    calculateGaps(temp, B, A);

    // calculate factorial
    vector<long long int> fact(N+5);
    computeFact(fact);

    // Stores the N! factorial
    long long int ans = fact[N];
    // now for each first and last interval 
    // compute the (intervalsize!)^(-1) or (intervalSize)^(MOD-2)
    for(int i=0;i<temp.size();++i){
        ans = ((ans%MOD) * ( modPow( fact[temp[i]], MOD-2)%MOD ))%MOD ;
        if(i!=0 and i!=temp.size()-1){
            ans = ((ans%MOD) * ( modPow(2, temp[i]-1))%MOD)%MOD ;
        }
    }
    
    return ans%MOD;

}
