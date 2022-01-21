// https://www.interviewbit.com/problems/max-min-05542f2f-69aa-4253-9cc7-84eb7bf739c4/
#include <bits/stdc++.h>

using namespace std;

int Solution(vector <int> &A){
    sort(A.begin(),A.end());
    return A[0]+A[A.size()-1];
}   



int main(){
    int n;
    cin>>n;
    vector <int> A(n);
    for(int i=0; i<n;++i)  
        cin>>A[i];

    cout<<Solution(A);

    return 0;
}