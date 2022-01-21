// https://www.interviewbit.com/problems/prime-sum/
// GoldBach conjecture == https://en.wikipedia.org/wiki/Goldbach%27s_conjecture

#include <bits/stdc++.h>
using namespace std;

// SieveOfEratosthenes
int primenum(int A){
    int flag=1;
    for(int i=2;i<=sqrt(A);++i)if(!(A%i)){
            flag=0;
            break;
    }
    return flag;
}

map <int,bool> SieveOfEratothenes(int A){
    vector <bool> ans(A+1, true);
    // vector <int> result;
    map <int, bool> result;
    for(int i=2;i*i<=A;++i){
        if(ans[i]){
            // result.insert(make_pair(i,ans[i]));
            for(int j=i*i;j<=A; j+=i)
                ans[j]=false;
        }
    }
    for(int i=2;i<=A;++i){
        if(ans[i]){
            result.insert(make_pair(i,ans[i]));}
    }
    return result;
}

vector<int> primesum(int A) {
    map <int, bool> primes =SieveOfEratothenes(A);
    vector <int> ans;
    for(auto it=primes.begin();it!=primes.end();++it){
        if(primes.find(A-it->first)!=primes.end()){
            ans.push_back(it->first);
            ans.push_back(A-it->first);
            primes.clear();
            break;
        }
    }
    
    return ans;
}


int main(){
    int n;
    cin>>n;
    vector <int> A=primesum(n);
    // map <int,bool> A=SieveOfEratothenes(n);
    cout<<A[0]<<" "<<A[1]<<"\n";
    // for(auto it=A.begin();it!=A.end();++it)
        // cout<<it->first<<" ";

    return 0;
}