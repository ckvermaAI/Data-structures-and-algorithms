
// https://www.geeksforgeeks.org/counting-sort/

#include <bits/stdc++.h>
using namespace std;

/*

Counting sort is a sorting technique based on keys b/w a specific 
range. It works by counting objects having distinct key values (kind of hashing).
Then doing some arithmetic  to calculae the position of each object in the output 
sequence

*/

vector<int> countSort(vector<int> &A){
    // find the minimum and maximum element 
    int min_ = *min_element(A.begin(), A.end());
    int max_ = *max_element(A.begin(), A.end());
    int range = (max_ - min_ + 1); 
    
    // now we will store the count of minimum element at 0th position
    // and maximum element at (max-min+1)th position
    vector<int> counter(range);
    
    // store the number of occurences of each element in "counter" array
    for(int &x:A)   counter[x-min_]++;

    for(int i=1;i<range;++i){
        counter[i] += counter[i-1];
    }

    vector<int> res(A.size());
    // now iterate through the counter array and fill the position accodingly
    for(int i=A.size()-1;i>=0;--i){
        // fill the position == counter[i] with i in original array
        res[--counter[A[i]-min_]]=A[i];
    }

    return res;
}

void show(vector<int> &A){
    for(int &x:A)   cout<<x<<" ";
    cout<<"\n";
}


int main(){

    vector<int> A = {3,3 ,2, 1, 1, 4 ,5, 5, 5};
    
    show(A);
    vector<int> res=countSort(A);
    show(res);


    return 0;
}