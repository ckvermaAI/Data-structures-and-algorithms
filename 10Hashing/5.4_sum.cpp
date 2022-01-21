// https://www.interviewbit.com/problems/4-sum/
// https://www.geeksforgeeks.org/find-four-numbers-with-sum-equal-to-given-sum/
// https://www.geeksforgeeks.org/find-four-elements-that-sum-to-a-given-value-set-2/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > fourSum(vector<int> &A, int B) {
    /*
    
    Brute Force approach is to iterate through array for 
    a, b, c and d to find the valid quadruplets
    Time complexity = O(N^4)

    Better approach =>
    Iterate through the array for a, b and c and check if 
    Target - (a+b+c) or d exist in array, to check if element exist in 
    the array we can use HashMap
    Time complexity = O(N^3)
    Space complexity = O(N)

    
    we can extend the above approach to store the sum of "c" and "d" 
    in the HashMap and iterate through the array for "a" and "b"
    Time complexity = O(N^2)
    Space complexity = O(N^2)
    
    */
    const int N = A.size();

    unordered_map<int, vector<pair<int,int>>> HashMap;
    vector<vector<int>> res;

    for(int i=0;i<N;++i){
        for(int j=i+1;j<N;++j){
            int sum = A[i] + A[j];
            int req = B - sum;

            if(HashMap.find(req)!=HashMap.end()){

                vector<pair<int,int>> vec = HashMap[req];
                for(int k=0;k<vec.size();++k){
                    
                    if(i!=vec[k].first and j!=vec[k].first and i!=vec[k].second and j!=vec[k].second){
                        vector<int> temp = {A[i], A[j], A[vec[k].first], A[vec[k].second] };
                        sort(temp.begin(), temp.end());
                        res.push_back(temp);
                    }
                }

            }

            HashMap[sum].push_back({i,j});

        }
    }

    // sort the final array
    sort(res.begin(), res.end());

    // remove the repeated element
    res.erase(unique(res.begin(), res.end()), res.end());

    return res;

}
