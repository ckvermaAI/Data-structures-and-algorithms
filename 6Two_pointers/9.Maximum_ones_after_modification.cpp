// https://www.interviewbit.com/problems/maximum-ones-after-modification/

#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &A, int B) {
    /*
    
    Brute Force Approach:
    Generate/Iterate through all the subarray and find 
    If that subarray satisfy the condition then add this 
    to our result.
    Time complexity = O(N^2)
    space complexity = O(1)

    Use Two pointers:
    use two pointers to iterate over all the subarray
    and each valid subarray should contain atmost
    B zeros   
    Time complexity = O(N)
    
    */

    const int N = A.size();
    // two pointers to iterate over [i,j] subarray
    // Now we want that valid subarray contains atmost B zeros
    // int zeros = 0;
    int ones=0;
    // to store the result
    int res=0;
    
    int j=0;
    for(int i=0;i<N;++i){
        for(;j<N;++j){
            // zeros += (A[j]==0);
            ones += A[j];
            // cout<<"zeros direct "<<zeros<<" zeros from ones "<<(j-i+1)-ones<<"\n";
            // If zeros are atmost B update the len
            if((j-i+1)-ones<=B){
                // cout<<"i and j "<<i<<" "<<j<<"\n";
                res = max(res, (j-i+1));
            }
            // If zeros exceed valid limit then move pointer i
            else if((j-i+1)-ones>B){
                break;
            }
        }
        // zeros -= (A[i]==0);
        ones -= A[i];
    }

    return res;

}


int main(){

    vector <int> A  = { 0, 0, 0, 0, 0, 1, 1, 1, 1, 1 };
    cout<<solve(A, 2);

}