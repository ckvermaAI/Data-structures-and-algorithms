#include <bits/stdc++.h>
using namespace std;

void show(vector <vector<int>>&A){
    int n=A.size();
    for(int i=0;i<n;++i){
        int m=A[i].size();
        for(int j=0;j<m;++j)
            cout<<A[i][j]<<" ";
        cout<<"\n";
    }
}

vector<vector<int> > diagonal(vector<vector<int> > &A) {
    int n=A.size();
    vector <vector<int>>result(2*n-1);
    for(int i=0; i<n;++i){
        for(int j=0; j<n;++j){
            result[i+j].push_back(A[i][j]);
        }
    }
    return result;
}

int main(){
    int n;
    cin>>n;
    vector <vector<int>>A(n, vector<int>(n,0));
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j)
            cin>>A[i][j];
    }
    show(A);
    vector <vector<int>>result=diagonal(A);
    show(result);


}