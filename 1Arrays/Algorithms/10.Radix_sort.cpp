// https://www.geeksforgeeks.org/radix-sort/
// https://stackoverflow.com/questions/3539265/why-quicksort-is-more-popular-than-radix-sort

#include <bits/stdc++.h>
using namespace std;

/*

Counting sort is a linear time sorting algorithm that sort in O(N+k) time
when elements are in rangr from 1 to k

what if the elements are in range from 1 to n^2
we can't use counting sort because counting sort will take O(N^2) which is worse than
comparison based sorting algorithm

The idea of radix sort is to do digit by digit sort starting from least significant
digit to most significant digit. Radix sort uses counting sort as a subroutine
to sort.

RADIX SORT ALGORITHM =>
from least significant digit to most significant digit i
    sort input array using counting sort(or any stable sort) 
    according to i'th digit


Is Radix Sort preferable to Comparison based sorting algorithms like Quick-Sort? 
If we have log2n bits for every digit, the running time of Radix appears to be better than Quick Sort for a wide range of input numbers. The constant factors hidden in asymptotic notation are higher for Radix Sort and Quick-Sort uses hardware caches more effectively. Also, Radix sort uses counting sort as a subroutine and counting sort takes extra space to sort numbers.

*/

void countSort(vector<int> &A, int d){
    const int N=A.size();

    vector<int> res(N), counter(10);
    // 10 for "10" digit in a decimal number system

    for(auto &x:A){
        counter[(x/d)%10]++;
    }

    // change counter array so that it contains position of array
    for(int i=1;i<10;++i)   counter[i] += counter[i-1];

    for(int i=N-1;i>=0;--i){
        counter[(A[i]/d)%10]--;
        res[counter[(A[i]/d)%10]] = A[i];
    }

    // copy the "res" array to "A"

}

void radixSort(vector<int> &A){

    // find the maximum number to know number of digits
    int max_ = *max_element(A.begin(), A.end());

    // do counting sort for every digit. Note that instead
    // of passing digit number
    for(int d=1; max_/d>0; d *= 10){
        countSort(A, d);
    }
}



int main(){


    return 0;
}