// https://www.interviewbit.com/problems/kth-permutation-sequence/
#include <bits/stdc++.h>
using namespace std;

/*

[1,2,3,4]

Here n=4 and k=14

So we have to find 14th permutation of this sequence

Group 1 =>
1 + [2, 3, 4]		3!=6

Group 2 =>
2 + [1, 3, 4]		3!=6

Group 3 =>
3 + [1, 2, 4]		3!=6

Group 4 =>
4 + [1, 2, 3]		3!=6

k=14 n=3
(14-1)/(3!) = 2 (3rd group)   (k-1)/(n-1)!

Hence, 14th permuation will lie in group3 

update k=> k=k-(preGroup)*(n-1)!=14-2*6=12	n=n-1=3


k=2 n=3
1/(2!)=0	k

3 + 1 + [2,4]	2!=2

3 + 1 + [4,2]


*/


typedef long long int lld;

void getFact(vector<lld>& fact, int N){
    // calculate the factorial till N
    fact[0]=1, fact[1]=1;
    for(int i=2;i<=N;++i){
        lld temp = (lld)i*fact[i-1];
        fact[i] = (temp>=INT_MAX or fact[i-1]>=INT_MAX)?INT_MAX:temp;
    }
    return;
}

void kthPerm(vector<lld>& fact, string &res, vector<int> &numbers, int N, int K){
    // find the kth perm
    if(numbers.empty()){
        return;
    }

    int num = (K-1)/fact[N-1];
    
    // add to result
    res += to_string(numbers[num]);

    // erase the added number
    numbers.erase(numbers.begin()+num);
    
    // reset the N and K
    K -= num*fact[N-1]; N--;  

    kthPerm(fact, res, numbers, N, K);

    return;

}

string getPermutation(int N, int K) {
    
    /*
    
    Number of permutation possible using n distinct numbers = n!

    Number of sequences possible with 1 in first position = (n-1)!
    Number of sequences possible with 2 in first position = (n-1)!
    Number of sequences possible with 3 in first position = (n-1)!

    Hence, the number at our first position should be k/(n-1) !
    
    Now, to find the number at second position decrease the number of distinct 
    integers to n-1 and also decrease k = k - (k/(n-1)!)
    
    */
    
    // to store the result
    string res = "";

    // find out the the factorial till N
    vector<lld> fact(N+1);
    getFact(fact, N);

    // create a array to store the numbers available
    vector<int> numbers(N);
    for(int i=0;i<N;++i)    numbers[i]=i+1;

    // find the kth permutation
    kthPerm(fact, res, numbers, N, K);

    return res;

}
