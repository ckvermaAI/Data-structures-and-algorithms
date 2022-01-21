// https://www.interviewbit.com/problems/colorful-number/
#include <bits/stdc++.h>
using namespace std;

vector<int> lszero(vector<int> &A) {
    /*
    
    Brute Force approach will be to iterate through all the subarray 
    and find the sum of each subset 
    Time complexity = O(N^3)
    Space complexity = O(1)

    Use prefix sum array to find the sum of any subset in O(1)
    Time complexity = O(N^2)
    sum of A[i...j] = prefixArr(j) - prefixArr(i-1)


    Now we want to find the subset having the sum zero
    or  sum of A[i....j] = 0
    or  prefix[j] - prefix[i-1] = 0
    or  prefix[j] = prefix[i-1] where j>=i

    
    Better Solution =>
    1) Iterate through the array and compute the prefix sum array
    2) check if this sum is zero then update the answer (insert this in HashMap)
    3) check if this value is present in HashMap if yes then we can get the sum zero

    Time complexity = O(N)
    Space complexity = O(N)
    
    */

    const int N = A.size();
    // calculate the prefix sum array
    vector<int> prefix(N);
    prefix[0]=A[0];
    for(int i=1;i<N;++i){
        prefix[i] = prefix[i-1]+A[i];
    }

    // HashMap to access the elements in O(1)
    unordered_map<int,int> counter;

    // to store the length
    int start=0, maxLen=0;

    // iterate through the prefix array 
    for(int i=0;i<N;++i){
        int x = prefix[i];
        if(x==0 and i+1>maxLen){
            // sum of elements from A[0....i] = 0
            start = 0;
            maxLen = i+1;
        }
        else{
            // if x is not zero 
            // check if "j" exist such that j<i and
            // sum of elements from A[0....j] = x
            if(counter.find(x)!=counter.end()){
                // sum of elements from A[j....i] = 0
                int j = counter[x];
                if(i-j>maxLen){
                    start = j+1;
                    maxLen = i-j;
                }

            }

        }

        if(counter.find(x)==counter.end()){
            // store the first occurence of the "x"
            // that will result in longest sequence having sum zero
            counter[x]=i;
            // sum of elements from A[0....i] = x
        }
    }

    if(maxLen==0){
        return vector<int>{};
    }

    return vector<int>{A.begin()+start, A.begin()+start+maxLen};

}
