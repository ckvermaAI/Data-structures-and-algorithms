// https://www.interviewbit.com/problems/3-sum/
#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > threeSum(vector<int> &A) {
    /*
    
    Brute Force approach is to iterate over three elements
    hence we need to iterate the array thrice 
    Time Complexity = O(N^3)
    Space Complexity = O(1)

    Use Map/HashMap
    store all the elements in the Map and iterate over 2 elements
    i.e. iterate the array twice and check if  a = -(b+c) exist in 
    map
    Time complexity = O(N^2)
    Space Complexity = O(N)

    
    Two Pointers
    sort the array, fix the first element and use two pointers to 
    find the next two elements
    Time complexity = O(N^2)
    Space complexity = O(1)
    
    */
    sort(A.begin(), A.end());
    vector<vector<int>> res;

    const int N = A.size();
    for(int i=0;i<N;++i){
        int k = N-1;
        for(int j=i+1;j<N;++j){
            for(;k>j;--k){
                long long int temp = (long long int)A[i] + A[j] + A[k];
                if(temp==0 and A[i]<=A[j] and A[j]<=A[k]){
                    res.push_back({A[i], A[j], A[k]});
                }
                else if(temp<0){
                    // Because we are decreasing k
                    break;
                }
            }
        }
    }

    sort(res.begin(), res.end());
    res.erase(unique(res.begin(), res.end()), res.end());
    return res;

}
