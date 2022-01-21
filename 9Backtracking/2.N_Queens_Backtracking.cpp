// https://www.interviewbit.com/problems/nqueens/

#include <bits/stdc++.h>
using namespace std;

vector<string> preetyPrint(vector<int>&temp, int &A){
    
    // create a matrix containing only "."
    vector<string> res(A, string(A, '.'));

    // {row, col} = {temp[i], i}
    // fill Q at these positions
    for(int i=0;i<A;++i){
        res[temp[i]][i] = 'Q';
    }
    
    return res;

}


void genPerm(vector<vector<string>>&res, vector<int>&temp, vector<int>&counter, 
            set<int> &diagonal, set<int> &offdiagonal, int &A){
    
    // Base case
    if(temp.size()==A){
        // for(auto it=diagonal.begin();it!=diagonal.end();++it){
            // cout<<it->first<<" "<<it->second;
        // }
        cout<<"set size "<<diagonal.size(); 
        res.push_back(preetyPrint(temp, A));
        return;
    }

    for(int i=0;i<A;++i){

        temp.push_back(i);
        counter[i]++;
        

        if(counter[i]==1){

            // {row, col} = {temp[i], i}
            int row = temp.back();
            int col = temp.size()-1;

            int diag = row+col;
            int offdiag = row-col;

            if( diagonal.find(diag)==diagonal.end() and 
                offdiagonal.find(offdiag)==offdiagonal.end()){

                diagonal.insert(diag);
                offdiagonal.insert(offdiag);
                genPerm(res, temp, counter, diagonal, offdiagonal ,A);
                
                diagonal.erase(diag);
                offdiagonal.erase(offdiag);
            }

        }

        // reset the counter and temp
        counter[i]--;
        temp.pop_back();
    }

}


vector<vector<string>> solveNQueens(int A) {

    // to store the result
    vector<vector<string>> res;

    // we represent the Queens in chessBoard using the array
    // indices of the array indicates the columns of the chessboard
    // and value in the arary indicates the row of the chessboard
    vector<int> temp;


    // To place the queens such that no queens attack each other
    // we have to ensure that there is only one queen in each row
    // and one queen in each column
    // we can handle this requirement by only using unique value in the
    // array representing the chess board

    // to store the number of queens in a row
    // there should be only queen in a row
    vector<int> counter(A);


    // now we only have to ensure that no queens attack each other diagonally
    // each diagonal and off-diagonal are unique in the sense that
    // if queen is present at {row, col} then sum of indices of all elements on diagonal
    // will be row+col and difference of indices of indices on off-diagonal element will remain
    // same, hence to ensure no attack in diagonal direction
    set<int> diagonal, offdiagonal;

    genPerm(res, temp, counter, diagonal, offdiagonal, A);

    
    return res;

}


int main(){

    int N = 3;

    vector<vector<string>> res;
    res = solveNQueens(N);

    for(auto &x:res){
        cout<<"solution: \n";
        for(auto &y:x)  cout<<y<<"\n";
        cout<<"\n";
    }

}