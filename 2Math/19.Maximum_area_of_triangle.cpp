#include <bits/stdc++.h>
using namespace std;

int area(int col, int x1, int x2, int right, int left) {
    if(x1 == -1 || col == -1 || x2 == -1 || right == -1 || left == -1) return 0;
    if(x1 >= x2 || right <= col && left >= col) return 0;
    return max(ceil(0.5 * (x2 - x1 + 1) * (right - col + 1)), ceil(0.5 * (x2 - x1 + 1) * (col - left + 1)));
}
int solve(vector<string> &A) {
    int n = A.size(), m = A[0].size(), i, j, k;
    // r = 0, g = 1, b = 2
    string color = "rgb";
    // first / last occurence of color[i] in column j
    // leftmost / rightmost occurence of color[i] in matrix
    int first[3][m], last[3][m], right[3] = {-1, -1, -1}, left[3] = {-1, -1, -1};
    
    for(i=0;i<3;i++) for(j=0;j<m;++j) 
        first[i][j] = last[i][j] = -1;
    for(j=0;j<m;++j) for(i=0;i<n;++i) for(k=0;k<3;k++) {
        if(A[i][j] == color[k] && first[k][j] == -1) first[k][j] = i;
        if(A[i][j] == color[k] && left[k] == -1) left[k] = j;
    }
    for(j=m-1;j>=0;--j) for(i=n-1;i>=0;--i) for(k=0;k<3;k++) {
        if(A[i][j] == color[k] && last[k][j] == -1) last[k][j] = i;
        if(A[i][j] == color[k] && right[k] == -1) right[k] = j;
    }
    
    int ans = 0;
    for(j=0;j<m;++j)  for(k=0;k<3;++k) 
        ans = max({ ans, 
                    area(j, first[k][j], last[(k+1)%3][j], right[(k+2)%3], left[(k+2)%3]),
                    area(j, first[k][j], last[(k+2)%3][j], right[(k+1)%3], left[(k+1)%3])
                 });

    return ans;
}


int main(){
    int N,M;
    cin>>N>>M;
    vector <string>A(N);
    for(int i=0;i<N;++i){
        cin>>A[i];
    }
    cout<<solve(A);
    // cout<<"\n";
    // show(A);
    // cout<<"\n";
    // cout<<area_of_triangle(cd(0,0), cd(1,4), cd(3,0) );


    return 0;
}