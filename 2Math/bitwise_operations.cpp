// Bitwise Operations tutorial #1 | XOR, Shift, Subsets
// https://www.youtube.com/watch?v=xXKL9YBWgCY&list=PLl0KD3g-oDOHpWRyyGBUJ9jmul0lUOD80

#include <bits/stdc++.h>
using namespace std;

void binary_representation(int n){
    // risk of overflow when shifting 1 to right by more than 30 places
    // in that case we want to map this to long long or unsigned long long integer
    for(int i=30;i>=0;--i){
        if( n & (1<<i) )    cout<<"1";
        else cout<<"0";
    }
}

void binary_representation_v2(int n){
    // here we are not in the risk of integer overflow due to shifting to the left
    string s="";
    for(int i=0;i<=30;++i){
        if( n>>i & 1 )    s=s+"1";
        else s=s+"0";
    }
    reverse(s.begin(),s.end());
    cout<<s;
}


int main(){
    int n;
    cin>>n;
    binary_representation(n);
    cout<<"\n";
    binary_representation_v2(n);

    return 0;
}