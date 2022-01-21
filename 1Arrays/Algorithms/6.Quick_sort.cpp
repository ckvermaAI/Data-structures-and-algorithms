// https://www.youtube.com/watch?v=COk73cpQbFQ&list=PL2_aWCzGMAwKedT2KfDMB9YA5DgASZb3U&index=7

#include <bits/stdc++.h>
using namespace std;

/*

Merge Sort =>
    Time Complexity = O(N*log(N)) worst case running time
    Space complexity = O(N)     
    Not a in-place sorting algorithm

Quick sort =>
    Time Complexity = O(N*log(N)) Average case running time
                      O(N^2)    Worst case running time
    Space complexity = O(1)
    In-Place sorting algorithm

    Worst case of Quick sort can be always be avoided using 
    randomized version of quick sort

    Quick sort algorithm is very efficient in terms of run-time
    and sort() function provided in all languages mostly uses
    Quick sort 


QUICK SORT ALGORITHM (sort in ascending order) =>
1) choose a pivot (may be leftmost, rightmost or random element )
2) find the right position of the pivot
    ( such that elements on left are smaller than pivot and elements
      larger than pivot are greater than pivot )


ANALYSIS of QUICK SORT =>
1) Divide and conquer
2) Recursive 
3) Not a stable sort algorithm
4) Time complexity 
    O(N*log(N)) - Best or Average Case
    O(N^2)  - Worst Case (can be avoided using randomized pivot)



Heapsort is O(N log N) guaranted, what is much better than worst case in Quicksort. Heapsort doesn't need more memory for another array to putting ordered data as is needed by Mergesort. So why do comercial applications stick with Quicksort? What Quicksort has that is so special over others implementations?

I've tested the algorithms myself and I've seen that Quicksort has something special indeed. It runs fast, much faster than Heap and Merge algorithms.

The secret of Quicksort is: It almost doesn't do unnecessary element swaps. Swap is time consuming.

With Heapsort, even if all of your data is already ordered, you are going to swap 100% of elements to order the array.

With Mergesort, it's even worse. You are going to write 100% of elements in another array and write it back in the original one, even if data is already ordered.

With Quicksort you don't swap what is already ordered. If your data is completely ordered, you swap almost nothing! Although there is a lot of fussing about worst case, a little improvement on the choice of pivot, any other than getting the first or last element of array, can avoid it. If you get a pivot from the intermediate element between first, last and middle element, it is suficient to avoid worst case.

What is superior in Quicksort is not the worst case, but the best case! In best case you do the same number of comparisons, ok, but you swap almost nothing. In average case you swap part of the elements, but not all elements, as in Heapsort and Mergesort. That is what gives Quicksort the best time. Less swap, more speed.

*/

int partition(vector<int>&A, int start, int end){
    // taking righmost element as pivot
    int pivot = A[end];
    int pIndex = start;     // partition index
    // Move all the element lesser or equal to pivot on the 
    // left of pIndex

    for(int i=start;i<end;++i){
        // we do not want to iterate over the last element
        // which is pivot
        if(A[i]<=pivot){
            swap(A[i], A[pIndex]);
            pIndex++;
        }
    }
    // swap the element of pIndex and end index(which is pivot )
    swap(A[pIndex], A[end]);
    return pIndex;
}

void QuickSort(vector<int> &A, int start, int end){
    // Base case
    if(start>=end)  return;

    int pIndex = partition(A, start, end);
    // pIndex is at correct position
    QuickSort(A, start, pIndex-1);
    QuickSort(A, pIndex+1, end);
}

void show(vector<int> &A){
    for(int &x:A) cout<<x<<" ";
    cout<<"\n";
}


int main(){

    vector<int> A={4,1,3,2};

    show(A);
    QuickSort(A, 0, A.size()-1);
    show(A);


    return 0;
}