#include <bits/stdc++.h>
using namespace std;

vector <bool> all_prime(int A){
    vector <bool> prime(A, true);
    for(int p=2;p*p<=A;++p){
        if(prime[p]){
            for(int i=p*p;i<=A;i+=p)
                prime[i]=false;
        }
    }
    return prime;
}

int isPower(int A) {
    int n=A;
    int power_;
    vector <bool> prime = all_prime(A);
    map <int, int> factors;
    for(int i=2;n>1;i++){
        int count=0;
        while(prime[i] && n%i==0){
            n/=i;
            count++;
        }
        if(count>0)
            factors.insert(make_pair(i,count));
        if(count>1)
            power_=count;
    }

    for(auto it=factors.begin(); it!=factors.end();++it){
        if(power_!=it->second)
                return 0;
    }
    return 1;
}

int isPowerFast(int A){
    if(A==1)
        return A;
    for(int i=2;i*i<=A;++i){
        int p=log(A)/log(i);
        if(pow(i,p)==A)
            return 1;
    }
    return 0;
}


int main(){
    int n;
    cin>>n;
    // cout<<isPower(n);
    cout<<isPowerFast(n);
    return 0;
}
