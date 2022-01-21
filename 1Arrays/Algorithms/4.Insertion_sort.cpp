// https://www.youtube.com/watch?v=i-SKeOcBwko&list=PL2_aWCzGMAwKedT2KfDMB9YA5DgASZb3U&index=4

#include <bits/stdc++.h>
using namespace std;

/*

Different Factors in a sorting algorithm =>
1) Time complexity
2) Space complexity
3) stability
4) Internal sort vs External sort
5) Recursive vs Non-recursive

*/

/*

INSERTION SORT
Insertion sort is not best sorting algorithm in terms of performance
but in pratice it is little more efficient than selection sort and 
bubble sort

Inuition - Keep unsorted number on one side and sorted numbers on other side.
           Intially numbers on sorted side are empty. And pick a number from
           unsorted side to INSERT this to right position in sorted side

Now, we need not to consider the seperate side/array to do this
1) start with one element in sorted half
    - left most element in sorted ( array of size==1 is sorted )

2) now move to next element and INSERT(shift) this element at right position in 
    sorted half and after this step our sorted half will be increases by one.

3) At any state while sorting, the sorted half will be on left
    and unsorted half will be on right

*/

void insertion_sort(vector<int> &A){
    const int N=A.size();

    // initially we are saying that we are starting with one 
    // element in sorted half - hence start iterating from position "1"
    for(int i=1;i<N;++i){
        int value = A[i];
        int hole = i;
        // now INSERT (shift one position at a time)
        // of the "A[index]" to its correct position in the array
        while(hole>0 and A[hole-1]>A[hole]){
            A[hole] = A[hole-1];
            A[hole-1]=value;
            hole--;
        }
    }
}



int main(){

    vector <int> A = {8, 5, 2, 9, 5, 6, 3};
    insertion_sort(A);

    for(int &x:A)   cout<<x<<" ";

    return 0;
}
