// https://www.interviewbit.com/problems/sort-array-with-squares/

#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> &A) {
    /*
    
    take square each element and 
    use sorting to sort the elements and this is our answer
    Time complexity = O(N*Log(N))
    Space complexity = O(1)

    general observations => If we have only positive elements
    then there is no need of sorting and if there are negative elements

    
    */
    // Take square of each element
    for(int &x:A)   x=x*x;

    // find out the minimum element
    int minpos = 0;
    for(int i=1;i<A.size();++i){
        if(A[i]<A[minpos])  minpos=i;
    }

    // if minimum element is at "0"th position then all elements are positive
    if(minpos==0)   return A;

    // there are some negative element 
    vector<int> res(A.size());
    int i=0, j=minpos, k=minpos;

    res[i] = A[minpos];
    i++, j--, k++;      // j moves toward left and k towards right

    while(j>=0 and k<A.size()){  // fill "res" array
        if(A[j]>A[k]){
            res[i] = A[k++];   // insert smaller element
        }
        else    res[i] = A[j--];
        i++;
    }

    // fill all the remaining left part
    while(j>=0){
        res[i++]=A[j--];
    }
    // fill all the remaining right part
    while(k<A.size()){
        res[i++]=A[k++];
    }

    return res;
}