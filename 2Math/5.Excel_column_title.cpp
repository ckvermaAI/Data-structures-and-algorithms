#include <bits/stdc++.h>
using namespace std;

string convertToTitle(int A) {
    string s;
    while(A){
        s=char('A'+(A-1)%26)+s;
        A=(A-1)/26;
    }
    return s;
}

int main(){
    int n;
    cin>>n;
    string s=convertToTitle(n);
    for(int i=0;i<s.size();++i)
        cout<<s[i]<<" ";
}