#include <bits/stdc++.h>
using namespace std;

int solve(int A) {
    if(A<=2)
        return 1;
    if(A>2)
        return (solve(A-1)+solve(A-2))%(1000000007);
    return 0;
}

int solve_iterative(int A){
    if(A<=2)
        return 1;
    if(A>2){
        int first=1;
        int second=1;
        int counter=A-2;
        int temp;
        while(counter){
            temp=first;
            first=second;
            second=(second+temp)%(1000000007);
            counter--;
        }
        return second%(1000000007);
    }
    return 0;
}

vector <vector <int>> multiply_matrix(vector <vector <int>>&A, vector <vector <int>>&B){
    vector <vector <int>> result(2,vector<int>(2,0));
    for(int i=0;i<2;++i){
        for(int j=0;j<2;++j){
            int sum_=0;
            for(int k=0;k<2;++k){
                sum_= int(((long long int)sum_+((long long int)A[i][k]*B[j][k])%1000000007)%1000000007);
            }
            result[i][j]=sum_;
        }
    }
    return result;
}

void show(vector <vector <int>>A){
    for(int i=0;i<2;++i){
        for(int j=0;j<2;++j){
            cout<<A[i][j]<<" ";
        }
        cout<<"\n";
    }
}

int solve_logn(int n){
    int A=n-1;
    if(A<=2)
        return 1;
    if(A>2){
    vector <vector <int>> M{{1,1},{1,0}};
    vector <vector <vector <int>>> Master;
    Master.push_back(M);
    Master.push_back(M);
    int step=log(A)/log(2);
    for(int i=1;i<=step;++i){
        vector <vector <int>> last_element = multiply_matrix(Master[Master.size()-1], Master[Master.size()-1]);
        Master.push_back(last_element);
    }
    vector <vector <int>> result=Master[Master.size()-1];
    int diff = A-pow(2,step);
    while(diff){
        int position=log(diff)/log(2);
        result=multiply_matrix(result,Master[position+1]);
        diff-=pow(2,position);
        
    }
    return result[0][0]%1000000007;
    
    }
    return 0;
}


int main(){
    int n;
    cin>>n;
    // cout<<solve_iterative(n)<<"\n";
    cout<<solve_logn(n);
    return 0;
}
