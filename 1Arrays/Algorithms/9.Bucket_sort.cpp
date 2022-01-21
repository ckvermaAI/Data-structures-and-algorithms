
// https://www.geeksforgeeks.org/bucket-sort-2/

#include <bits/stdc++.h>
using namespace std;

/*

BUCKET SORT
Bucket Sort is mainly useful when input is UNIFORMLY DISTRIBUTED over a range.

For example, consider the following problem ==
sort a large set of floating point numbers which are in range from 0.0 to 1.0 
and are uniformly distributed across the range. How to sort the numbers 
efficiently 


BUCKET SORT for floating number b/w [0,1)
1) create N buckets equal to size of the array
2) insert the ith position of array in bucket i*A[i]
3) now sort the individual buckets


BUCKET SORT for numbes having integer part 
1) Find maximum element and minimum of the array
2) Calculate the range of each bucket
    range = (max - min)/N
    N is number of buckets

3) create N buckets of calculated range
4) scatter the array elements to these buckets
    BucketIndex = (A[i]- min)/range

5) Now sort the bucket individually
6) insert the sorted elements from buckets to original array


*/


void BucketSort1(vector<float>&A){
    // for sorting the float number in range [0,1)

    const int N = A.size();

    // 1) Create n empty buckets
    vector<float> buckets[N];

    // 2) Put array elements
    // in different buckets
    for(int i=0;i<N;++i){
        int bucketIndex = N*A[i];
        buckets[bucketIndex].push_back(A[i]);
    }

    // 3) Sort individual buckets
    for(int i=0;i<N;++i){
        sort(buckets[i].begin(), buckets[i].end());
    }

    // 4) concatenate all the buckets
    int index=0;
    for(int i=0;i<N;++i){
        for(int j=0;j<buckets[i].size();++j){
            A[index++] = buckets[i][j];
        }
    }
}


void BucketSort2(vector<float> &A, int NBuckets){
    const int N=A.size();

    // 1) find the maximum and minimum element
    int min_ = *min_element(A.begin(), A.end());
    int max_ = *max_element(A.begin(), A.end());

    // 2) find the range
    int range_ = (max_ - min_)/NBuckets;

    // create empty buckets
    vector<float> buckets[NBuckets+1];

    // 3) scatter the array elements 
    // into correct bucket
    for(int i=0;i<N;++i){
        int bucketIndex = (A[i]-min_)/range_;
        buckets[bucketIndex].push_back(A[i]);
    }

    // 4) sort the individual buckets
    for(int i=0;i<=NBuckets;++i){
        sort(buckets[i].begin(), buckets[i].end());
    }

    // 5) insert the element in original array
    int index=0;
    for(int i=0;i<=NBuckets;++i){
        for(int j=0;j<buckets[i].size();++j){
            A[index++] = buckets[i][j];
        }
    }
}


void show(vector<float>&A){
    for(auto &x:A)  cout<<x<<"\t";
    cout<<"\n";
}


int main(){

    // vector<float> A = { 0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434 };

    // show(A);
    // BucketSort1(A);
    // show(A);



    vector<float > A = {9.8, 0.6, 10.1, 1.9, 3.07, 3.04, 5.0, 8.0, 4.8, 7.68};
    int NBuckets = 5;

    show(A);
    BucketSort2(A, NBuckets);
    show(A);

    return 0;
}