#include <bits/stdc++.h>
using namespace std;

/*

Take Care =>

    what i think most of the people are taking modulo while calculating the product however in the question it is just asked to print ans%mod ,if we take modulo while calculating the product we ourself may change the original product and therefore getting a wrong answer specially when value of our products is goes larger than mod

    Yes, a little bit of expansion for this ->

    lets assume for an index you get (left_index * right_index) = mod+1 //showing that its greater than mod

    then if we store in ans = (left_index * right_index) % mod  --> then we will store 1

    for another case if left_index * right_index = 5

    then we store ans = max(1,5) = 5 which is very wrong

    so take mod at last in this way we return ans%mod (which is equal to 1)

*/


int maxSpecialProduct(vector<int> &A) {
    /*
    
    Brute Force approach is iterate through all the elements
    and find the leftSpecialValue and RightSpecialValue
    Time complexity = O(N^2)
    Space complexity = O(1)

    One thing we can do is to find the leftSpecialValue and 
    rightSpecialValue beforehand and while iterating through
    the array we can access these value in constant time

    How should we calculate leftSpecialValue and rightSpecialValue
    for each element in array may be in O(N) or O(N*log(N)) Time complexity
    
    => BottleNeck is repeated work - for each element when we find the leftSpecialValue
    or rightSpecialValue we are iterating over the same elements again

    1) use prefix or suffix array => 
        This will not work in this case, because the state of any 
        element depends on itself ( generally it will works when we want to
        find the MIN, MAX, SUM of elements,..etc )

        But here the state of element depends on current element itself ( thus we just
        cannot rely on previous state to get the current state )

    2) use stack =>
        If we just maintain the elements in the strictly descending order in stack

        When processing the ith element remove all the elements from the stack 
        which have less value less than or equal to ith element.
        Now whatever element will remain at the top of index will give the index 
        corresponding to LeftSpecialValue. If no element is at top then take it as 0.
        Push ith element in stack now.

        Lets say if next element is smaller than ith element then leftSpecial value = top of stack
        if value greater than ith element then definitely value exist in stack (because it is not remove due 
        to ith element)
    
    
    */
    const int N = A.size(), MOD=1e9+7;
    // To store the leftSpecialValue and rightSpecialValue
    vector<int> left(N), right(N);

    stack<int> num;
    
    // leftSpecialValue calculation
    num.push(0);
    for(int i=1;i<N;++i){
        if(A[num.top()]<=A[i]){
            while(!num.empty() and A[num.top()]<=A[i]){
                num.pop();
            }
            if(!num.empty())    left[i]=num.top();
        }
        
        else    left[i] = num.top();
        
        num.push(i);
    }

    while(!num.empty())     num.pop();

    // rightSpecialValue calculation
    num.push(N-1);
    for(int i=N-2;i>=0;--i){
        if(A[num.top()]<=A[i]){
            while(!num.empty() and A[num.top()]<=A[i]){
                num.pop();
            }
            if(!num.empty())    right[i]=num.top();
        }
        
        else    right[i] = num.top();
        
        num.push(i);
    }

    long long int ans=0;
    for(int i=0;i<N;++i){
        long long int temp = (long long int)left[i]*right[i];
        if(temp>ans){
            ans = temp;
        }
    }
    return ans%MOD;
}
