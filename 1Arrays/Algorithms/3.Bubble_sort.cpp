// https://www.youtube.com/watch?v=Jdtq5uKz-w4&list=PL2_aWCzGMAwKedT2KfDMB9YA5DgASZb3U&index=3

#include <bits/stdc++.h>
using namespace std;

/*

Different aspects in which we can divide the sorting algorithms
1) Time complexity
2) Space complexity
3) stability
4) Internal vs External sort
5) Recursive or Non-Recursive

*/

/*

BUBBLE SORT
SORTING in ascending order =>
For each pass/scan of the array we will compare the current 
element with next element and if the current element is greater 
than next element (A[i]>A[i+1]) then the property of ascending
sorted array will violates and then we swap these two element
and move to next element.

Thus in one single pass the maximum(maximum of unsorted half) 
will "BUBBLED up" to its right position.

and at any state (while bubble sorting) of the sorting, array
will consist of unsorted part (left half) and sorted part (right
half ).

And we can do some optimisation by not going through the sorted 
half in each iteration

we need to do atmost N passes, because after N-1 pass the sorted 
half will consist of N-1 element and only one element in unsorted 
half which will be definitely less than all elements of sorted half

Worst case = N-1 passes and each pass we are iterating through array
            N, N-1, ...... 1 times
            (N+ N-1 + ..... 1) = O(N^2)
Best case = Array is already sorted - one pass 

Average case = N/2 passes required = O(N^2)

*/
 
void Bubble_sort(vector<int>&A){
    const int N=A.size();
    int pass = N-1, size_of_sorted_half=0;

    while(pass--){
        int flag =0;
        // scan the whole array N-1 times
        for(int i=0;i<N-1-size_of_sorted_half;++i){
            // optimisation = 1
            // by not iterating through the sorted half
            if(A[i]>A[i+1]){
                swap(A[i], A[i+1]);
                flag++;
            }
        }
        size_of_sorted_half++;

        if(flag==0){
            // optimisation = 2
            // when the array is sorted 
            // i.e. there is no violation of property
            break;
        }
    }
}




int main(){

    return 0;
}
