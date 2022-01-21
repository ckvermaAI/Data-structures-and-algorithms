// Blog for bitwise mask
// https://codeforces.com/blog/entry/73490
// Problem 1
// https://codeforces.com/problemset/problem/1097/B

#include <bits/stdc++.h>
using namespace std;

void bitwise_mask(vector <int> a){
    int n=30, m=a.size();
    long long total_sum= accumulate(a.begin(),a.end(),0);
    if(total_sum%360==0){ cout<<"YES"; return;}
    for(int mask=1;mask<=180;mask++){
        long long sum_of_this_subset=0;
        for(int i=0;i<n;++i){
            if(mask & (1<<i))   sum_of_this_subset+=a[i];
        }
        if(sum_of_this_subset%360==(total_sum-sum_of_this_subset)%360){
            cout<<"YES"; return ;
        }
    }
    cout<<"NO";
    return;
}


int main(){
    int n;
    cin>>n;
    vector <int> A(n);
    for(int i=0;i<n;++i)
        cin>>A[i];

    bitwise_mask(A);

    return 0;
}