#include <bits/stdc++.h>
using namespace std;

void show(vector<vector<int>>A){
    int M=A.size();
    int N=A[0].size();
    for(int i=0;i<M;++i){
        for(int j=0;j<N;++j){
            cout<<A[i][j]<<" ";
        }
        cout<<"\n";
    }
}
void setZeroes(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int M=A.size();
    int N=A[0].size();
    unordered_set <int> row_zero;
    unordered_set <int> col_zero;
    for(int row=0;row<M;++row){
        for(int col=0;col<N;++col){
            if(A[row][col]==0){
                row_zero.insert(row);
                col_zero.insert(col);
            }
         }
    }
    for(auto row=row_zero.begin();row!=row_zero.end();++row)
        A[*row]=vector<int>(M,0);
    for(auto col=col_zero.begin();col!=col_zero.end();++col){
        for(int row=0;row<M;++row){
            A[row][*col]=0;
        }
    }
    

}

int main(){
    int M, N;
    cin>>M>>N;
    vector <vector<int>> A(M,vector<int>(N,0));
    for(int i=0;i<M;++i){
        for(int j=0;j<N;++j){
            cin>>A[i][j];
        }
    }
    show(A);
    setZeroes(A);
    show(A);

    return 0;
}