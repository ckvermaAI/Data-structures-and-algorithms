// https://www.interviewbit.com/problems/city-tour/

#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

long long power_mod(long long base_, long long pow_){
    long long ans=1;
    while(pow_){
        if(pow_ & 1)
            ans=ans*base_%MOD;
        base_=base_*base_%MOD;
        pow_>>=1;
    }
    return ans;
}

void computeFactorial(long long *fact, int n){
    fact[0]=1;fact[1]=1;
    for(int i=2;i<=n;++i)
        fact[i]=(long long)(fact[i-1]*i)%MOD;
}

void calculateGaps(vector <int> &gaps, vector <int>&B, int n, int A){
    gaps.push_back(B[0]-1);
    for(int i=0;i<n;++i)
        gaps.push_back(B[i]-B[i-1]-1);
    gaps.push_back(A-B[n-1]);
}

int solve(int A, vector<int> &B) {
    int visited_cities=B.size();
    int nonvisited_cities = A-visited_cities;
    long long fact[1001];
    computeFactorial(fact,1000);

    vector <int> gaps;
    sort(B.begin(),B.end());
    calculateGaps(gaps,B, visited_cities, A);
    long long ans=fact[nonvisited_cities];
    for(int i=0;i<gaps.size();++i){ 
        if(gaps[i]>1){
            ans= (ans*power_mod(fact[gaps[i]],MOD-2))%MOD;
            if(i!=0 && i!=gaps.size()-1){
                ans = (ans*power_mod(2,gaps[i]-1))%MOD;
            }
        }
    }
    return ans;
}


int main(){
    int m,n;
    cin>>m>>n;
    // cout<<power_mod(2,n);
    vector <int> A(n);
    for(int i=0;i<n;++i)
        cin>>A[i];

    cout<<solve(m, A);

    return 0;
}