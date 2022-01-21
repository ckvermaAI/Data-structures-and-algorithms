// https://www.interviewbit.com/problems/ways-to-form-max-heap/
// https://www.geeksforgeeks.org/number-ways-form-heap-n-distinct-integers/
// https://www.bookofproofs.org/branches/recursive-formula-for-binomial-coefficients/

#include <bits/stdc++.h>
using namespace std;


const int MOD = 1e9+7;
typedef long long int lld;

void precomputeC(vector<vector<lld>>&C, int &A){
    // precompute the combinations
    for(int i=0;i<A;++i){
        for(int j=0;j<=i;++j){
            // Base case
            if(i==j or j==0){
                C[i][j]=1;
            }
            // otherwise
            else{
                C[i][j] = (C[i-1][j-1]+C[i-1][j])%MOD;
            }
        }
    }
}


pair<lld,lld> NumberofNodesLR(int N){
    // returns number of nodes in left and right subtree
    
    // height of tree
    int h = log2(N);
    
    // TotalNodes excluding the last level 
    // 2^h - 1
    lld nodes = pow(2, h) - 1;

    // nodes at last level
    lld lastNodes = N - nodes;

    // max nodes possible at last level
    lld maxNodes = pow(2,h);



    lld leftNodes;

    // case 1 - when last level in left subtree is filled completely
    if(lastNodes>=maxNodes/2){

        // number of nodes in height of tree "h-1"
        leftNodes = nodes;
    }

    // case 2 - when last level in left subtree is not filled completely
    else{
        leftNodes = nodes;

        // now decrease/subtract the nodes not present at last level
        leftNodes -= (maxNodes/2 - lastNodes);
    }

    lld rightNodes = N - 1 - leftNodes;

    return {leftNodes, rightNodes};

}


int solve(int A) {

    // precompute the combinations
    vector<vector<lld>> C(A, vector<lld>(A));
    precomputeC(C, A);
    

    // use dynamic programming to find the different possible
    // ways to create max heap
    vector<lld> res(A+1);

    res[0]=1, res[1]=1;
    
    for(int i=2;i<=A;++i){
        // find nodes in left and right subtree
        pair<lld,lld> p = NumberofNodesLR(i);

        // ans = N-1CL * ways(L) * ways(R)
        res[i] = C[i-1][p.first];
        res[i] = (res[i] * res[p.first])%MOD;
        res[i] = (res[i] * res[p.second])%MOD;

    }

    return res[A];

}
