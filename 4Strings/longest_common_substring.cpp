// https://www.geeksforgeeks.org/longest-common-substring-dp-29/
#include <bits/stdc++.h>
using namespace std;

int longest_common_substring(char *X, char *Y, int m, int n){
    int LCsuffix[m+1][n+1];
    int result =0;

    for(int i=0;i<=m;++i){
        for(int j=0;j<=n;++j){
            if(i==0||j==0)  LCsuffix[i][j]=0;
            else if(X[i-1]==Y[j-1]){
                LCsuffix[i][j]=LCsuffix[i-1][j-1]+1;
                result=max(result,LCsuffix[i][j]);
            }
            else LCsuffix[i][j]=0;
        }
    }
    for(int i=0;i<=m;++i){
        for(int j=0;j<=n;++j){
            cout<<LCsuffix[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
    return result;
}


int main(){
    char X[] = "ABFGBA";
    char Y[] = "ABGFBA";
    int m = strlen(X);
    int n = strlen(Y);
    cout<<longest_common_substring(X,Y,m,n);
    return 0;
}