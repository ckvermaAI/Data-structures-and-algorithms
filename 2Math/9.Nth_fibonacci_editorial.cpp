#include <bits/stdc++.h>
using namespace std;

int md = 1e9+7;
map<int, long long int> m;

long long int calc(int n)
{
    if(m.find(n)!=m.end())
        return m[n];
    int t = n/2;
    if(n%2)     // n is odd
        m[n] = (((calc(t+1)*calc(t))%md) + ((calc(t)*calc(t-1))%md))%md;
    else        // n is even
        m[n]= (((calc(t)*calc(t))%md) + ((calc(t-1)*calc(t-1))%md))%md;
    return m[n];
}

int solve(int n) 
{
    m.clear();
    m[0]=1; m[1]=1;
    return calc(n-1);
}


int main(){
    cout<<solve(3);
    return 0;
}
