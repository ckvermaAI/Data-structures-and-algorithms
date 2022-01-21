
// Binary search tutorial (C++ and python) Errichto
// https://www.youtube.com/watch?v=GU7DpgHINWQ&t=1022s

#include <bits/stdc++.h>
using namespace std;

/*

Given a array of size N and a integer X
find first value in the array >=X or find Lower Bound of X

Solution =>
    1) maintain a variable ans=-1 which store the best possible answer 
    till time t
    2) Use binary search on the array, when we satisfy our condition
       "current_element>= target" update the "ans" to its next best possible 
       answer


Another way to look at this problem is 
A = {2, 3, 5, 6, 8, 10, 12} and X = 4
    {F, F, T, T, T,  T,  T}
    where F is False and T is True and we have to find the such
    first T which satisfy the given condition


Think about binary search problem in terms of prefix and suffix
of true(T) and false(F) according to some given condition

*/

int lowerBound(vector<int>&A, int key){
    // find out first value which is >=key 
    int low=0, high=A.size()-1;
    // stores the best possible answer
    int ans=-1;

    while(low<=high){
        int mid = low+(high-low)/2;
        if(A[mid]>=key){
            // look on left side
            ans=mid;
            high=mid-1;
        }
        else{
            // look on right part
            low = mid+1;
        }
    }
    return ans;
}