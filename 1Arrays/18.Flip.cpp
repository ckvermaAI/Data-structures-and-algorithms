// https://www.interviewbit.com/problems/flip/

#include <bits/stdc++.h>
using namespace std;

vector<int> flip(string s) {
    
    /*

    Brute force approach will be iterate through each subarray
    and find out if this interval can be flipped
    Time complexity = O(N^3)
        -> O(N^2) for two loops
        -> and for each interval find out the total ones
    
    we can optimize the last part by using prefix sum array
    hence time complexity will O(N^2)

    But, we look at the problem 
    -> we want to find a interval such that if we flip that contents of interval
       that results in maximum "1" count of the array
    -> because we can flip the elements of a particular interval 
        1 -> 0  ( penalty )     -1
        0 -> 1   ( reward )     +1

    so if we create a array with -1 (where we have "1" in string
        and when we flip that will result in "0")    
    and 1 where we have "0"

    Use a kadane algorithm on resulting array
    
    */

    const int N = s.length();
    int ones = 0;
    for(int i=0;i<N;++i){
        if(s[i]=='1'){
            ones++;
        }   
    }

    if(ones==N)     return vector<int> {};


    int L, R;       // finally where we will store the answer
    int l=0, r=0, v=0;   // temp start and end of the interval
    int ans=0, till=0;
    // use kadane algorithm on array A
    for(int i=0;i<N;++i){
        int temp = till+((s[i]=='0')?1:-1);
        if(temp>=0){
            r = i;       // expand the current interval
            till = temp;
        }
        else if(temp<0){
            l=i+1;        // reset the interval start and end points
            r=i+1;
            till = 0;
        }

        if(till>ans){
            ans=till;
            L=l;
            R=r;
        }
    }

    return vector<int>{L+1, R+1};
   
}

int main(){
    string A;
    cin>>A;
    vector <int> result;
    result=flip(A);
    for(int i=0;i<result.size();++i)
        cout<<result[i]<<" ";

}