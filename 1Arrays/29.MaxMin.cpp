// https://www.interviewbit.com/problems/max-min-05542f2f-69aa-4253-9cc7-84eb7bf739c4/

#include <bits/stdc++.h>
using namespace std;

pair<int,int> maxMin(vector<int>&A, int start, int end){
    if(start>end){
        return {INT_MAX, INT_MIN};
    }
    else if(start==end){
        // if size is 1 
        // then there is no need to compare the elements
        return {A[start], A[end]};
    }
    else if(start==end+1){
        // if size is 2 then we only have to make one comparison
        int maxE = A[start];
        int minE = A[end];
        if(minE>maxE)   swap(maxE, minE);
        return {minE, maxE};
    }
    else{
        // size if greater than 2
        int mid = start + (end-start)/2;
        pair<int,int> left = maxMin(A, start, mid);
        pair<int,int> right = maxMin(A, mid+1, end);
        int minE = max(left.first, right.first);
        int maxE = max(left.second, right.second);
        return {minE, maxE};
    }
    return pair<int,int> {};
}


int solve(vector<int> &A) {
    /*
    Brute Force approach will be iterate through the whole array
    and find out the maxE and minE and in this way the time complexity
    will be O(N) and number of comparisons made are = 2N

    and now if we use divide and conquer technique then 
    if we obtain the max and min of two array then to obtain the 
    max and min for the whole array we just need to make two comparisons

    Number of comparisons made
    T(N) = T(floor(N/2)) + T(ceil(N/2)) + 2
    T(2) = 1 and T(1) = 0

    if N is power of 2 then we can write 
    T(N) = 2T(N/2) + 2
    
    After solving the above recursion we get
    T(N) = 3N/2 - 2
    
    */
    pair<int,int> res = maxMin(A, 0, A.size()-1);
    return res.first+res.second;
}
