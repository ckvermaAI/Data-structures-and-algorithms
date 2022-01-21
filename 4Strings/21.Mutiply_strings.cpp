// https://www.interviewbit.com/problems/multiply-strings/
#include <bits/stdc++.h>
using namespace std;

string multiplyString(string A, string B){
    int n=A.size(), m=B.size(), sum;
    string ans(m+n,'0');
    for(int i=n-1;i>=0;--i){
        for(int j=m-1;j>=0;--j){
            sum=(A[i]-'0')*(B[j]-'0')+(ans[i+j+1]-'0');
            ans[i+j+1]=(sum%10)+'0';
            ans[i+j]+=(sum/10)+'0';
        }
    }
    for(int i=0;i<m+n;++i){
        if(ans[i]!='0') return ans.substr(i);
    }
    return "0";
}

int main(){


    return 0;
}