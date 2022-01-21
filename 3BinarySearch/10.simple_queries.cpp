// https://www.interviewbit.com/problems/simple-queries/
// do you know product of divisors of a number can be written as N^D/2, where N is number and D is number of divisors of N.

#include <bits/stdc++.h>
using namespace std;

#define ll long long int
const int mn = 1e5 + 5;
const ll mod = 1e9 + 7;
ll power(ll a, ll g) {ll ag = 1; while(g){if(g&1) ag = (ag%mod * a%mod)%mod; a = (a%mod * a%mod)%mod; g >>= 1;} return ag;}

ll p[mn];

void pre_compute_product_of_divisors() {
    p[0] = 0; p[1] = 1;
    if(p[2] != 0) return;
    for(ll i = 2; i < mn; i += 1) {
        if(p[i] == 0) {
            p[i] = 2;
            for(ll j = i+i; j < mn; j += i) {
                if(p[j] == 0) p[j] = 1;
                ll tmp = j;
                ll cnt = 0;
                while(tmp % i == 0) {
                    cnt += 1;
                    tmp /= i;
                }
                p[j] *= (cnt + 1);
            }
        }
    }
    for(int i = 2; i < mn; i += 1) {
        p[i] = (power(i, p[i]/2)%mod * (p[i]&1 ? (ll)sqrt(i) : 1)%mod)%mod;
    }
}

bool compare(int a, int b) {
    return a>b;    
}

int binary_index(vector<int> &A, int B){
    int low=0,high=A.size()-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(A[mid]==B)   return mid;
        else if(A[mid]>B)   high=mid-1;
        else if(A[mid]<B)   low=mid+1;
    }
    return -1;
}

vector <int> solve(vector <int>&A, vector <int> &B){
    pre_compute_product_of_divisors();

    int n=A.size();
    int temp;
    vector <int> subarray;
    for(int i=0;i<n;++i){
        for(int j=i;j<n;++j){
            // cout<<"temp "<<temp;
            temp=*max_element(A.begin()+i, A.begin()+j+1);
            subarray.push_back(temp);
        }
    }

    for(int i=0;i<subarray.size();++i)
        subarray[i]=p[subarray[i]];
    
    sort(subarray.begin(),subarray.end(), compare);

    int m=B.size();
    vector <int> result(m);
    for(int i=0;i<m;++i)
        result[i]=subarray[B[i]-1];
    return result;
}


int main(){
    int n, m;
    cin>>n;
    vector <int> A(n);
    for(int i=0;i<n;++i)
        cin>>A[i];
    cin>>m;
    vector <int> B(m);
    for(int i=0;i<m;++i)
        cin>>B[i];

    vector <int> res;
    res = solve(A,B);
    for(int i=0;i<m;++i)
        cout<<res[i]<<" ";

    return 0;
}

