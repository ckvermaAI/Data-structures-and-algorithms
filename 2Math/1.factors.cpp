#include <bits/stdc++.h>
using namespace std;

vector <int> Solution(int n){
    vector <int> ans;
    for(int i=1;i<=sqrt(n);++i)if(!(n%i)){
        ans.push_back(i);
        if(i!=n/i) ans.push_back(n/i);
    }
    sort(ans.begin(),ans.end());
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector <int> factors;
    factors=Solution(n);
    for(int i=0;i<factors.size();++i)
        cout<<factors[i]<<" ";
    return 0;
}