// https://www.interviewbit.com/problems/numbers-of-length-n-and-value-less-than-k/
#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &A, int B, int C) {
    /*
    This question is very similar to finding the rank of 
    the digits (in a sorted permutations)

    special digit "0"
    so we cannot allow "0" to be at first place
    in a number of length greater than 1, on this basis
    we can create two cases 
    1) Base case - where the length of number is 1
        If B ==1 then count how many digits are smaller than C
    2) General case - length of number is greater than 1
        A) if B is not equal to number of digits(C)
            then all of the "B" length numbers is answer
        B) otherwise find the "Rank" of the digit in sorted permutation 
            of number each having length "B"
    
    */
    const int N = A.size();
    int res=0;

    // Base case when there are no digits available
    if(N==0)    return res;

    // Base case when we have to find out digits of length == 1
    if(B==1){
        return (lower_bound(A.begin(), A.end(), C) - A.begin());
    }

    // extract digits
    stack<int> digits;
    int temp=C;
    while(temp){
        digits.push(temp%10);
        temp /= 10;
    }


    // General case 
    
    // Case-I  "B>digits.size()"
    // no number are possible 
    if(B>digits.size()) return 0;
  
    // Case-II  "B<digits.size()"
    // return all possible number of length "B"
    if(B<digits.size()){
        // count number of possibilities for most significant place
        res = pow(N, B);
        if(A[0]==0)
            res-= pow(N, B-1);
        return res;
    }

    // Case-III "B==digits"
    // Find the rank of number in sorted permutation of number of length "B"
    int i=0;
    while( !digits.empty() and binary_search(A.begin(), A.end(), digits.top()) ){
        // current element is present then keep on finding the possible combination
        res += (lower_bound(A.begin(), A.end(), digits.top())-A.begin())*pow(N, B-1-i);
        digits.pop();
        i++;
    } 
    if(!digits.empty())
        // current element is not present in array "A" and digits are available
        // then find out the possible combination less than current digits
        // after that no further combination are possible
        res += (lower_bound(A.begin(),A.end(),digits.top())-A.begin())*(pow(N,B-i-1));
    if(A[0]==0)
        res -= pow(N, B-1);
    
    return res;
    
}