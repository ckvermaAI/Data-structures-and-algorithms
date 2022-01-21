#include <bits/stdc++.h>
using namespace std;

/*

with respect to a single string the total number of bits rotated after N operations 1+2+3+...+N which is N*(N+1)/2

we get back the original string only when the total number of rotated bits is a multiple of length of string S(LEN)

This can be done in O(N) time for each string by finding all N*(N+1)/2 where N starts from 1 and goes upto (2*LEN - 1)

But there is catch, this wont always give the minimum number of operations. Its possible that during rotation, we can get the original string before the number of bits rotated is multiple of LEN.

Example: S => 100100
Here in 2 operations, we get the original string back. This takes palce because the string is made up of recurring substrings

Length of recurring substring can easily be found out using KMP algorithm in O(N) time complexity for each string.

Find the minimum number of operations for each string, and take the LCM of all these values to get the answer.


*/



void fact(int n, map<int, int> &m){
    int i=2,j=n;
    while(i*i<=n){
        if(n%i==0){
            int pw=0;
            while(n%i==0){
                pw++;
                n/=i;
            }
            m[i]=max(m[i],pw);
        }
        i++;
    }
    if(n>1){
        m[n]=max(m[n],1);
    }
}

int kmp(string s){
    int N=s.length(),border=0,t;
    vector <int> prefix(N);
    prefix[0]=border;
    for(int i=1;i<N;++i){
        while(border>0 && s[i]!=s[border]){
            border=prefix[border-1];
        }
        if(s[i]==s[border]) border++;
        else border=0;
        prefix[i]=border;
    }
    t=N-prefix.back();
    if(N%t==0)  N=t;
    long long int sum=0;
    for(int time=1;;++time){
        sum+=time;
        if(sum%N==0)    return time;
    }
    return N;
}

int solve(vector <string> &A){
    const int MOD=1e9+7;
    map<int,int>mp;
    for(int i=0;i<A.size();++i){
        fact(kmp(A[i]),mp);
    }
    long long res=1;
    for(auto &it:mp){
        while(it.second--){
            res=(res*it.first)%MOD;
        }
    }
    return res%MOD;
}



int main(){
    int n;
    cin>>n;
    vector <string> A(n);
    for(int i=0;i<n;++i)    cin>>A[i];
    cout<<solve(A);

    return 0;
}