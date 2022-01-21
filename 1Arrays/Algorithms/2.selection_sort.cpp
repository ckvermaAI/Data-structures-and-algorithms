// https://www.youtube.com/watch?v=GUDLRan2DWM&list=PL2_aWCzGMAwKedT2KfDMB9YA5DgASZb3U&index=3
#include <bits/stdc++.h>
using namespace std;

/*

Different aspects in which we can divide the sorting algorithms

1. Time complexity - O(N^2), O(N*log(N))
2. Space complexity - O(1), O(N)
3. Stability - stable, Non-stable algorithm
4. Internal vs External sort
    Internal = All records in main memory
    External = Records are on disk/tapes
5. Recursive vs Non-Recursive

*/

/*

SELECTION SORT (ASCENDING ORDER) =>
    Find the minimum element out of the array 
    and add this element to start of the array

way1 =>
    1) copy the minimum element to the start of new array
    2) and set this element to "max" in original array
    3) repeat
    4) final copy back this new array element to original one
    Time complexity = O(N^2)
    space complexity = O(N)

way2 =>
    Get rid of Auxiliary space 
    1) keep one pointer which point to start of array
    2) scan the whole array and find out the minimum in the array
    3) swap the element at pointer and minimum element of array
    4) increase the pointer to next element and start the search 
        from pointer only

At any state of sorting, the left part will be sorted
and right half will be unsorted

SELECTION = selection of smallest element in each pass
*/

void selection_sort(vector<int>&A){
    // selection sort
    const int N=A.size();
    for(int i=0;i<N-1;++i){
        // no need to iterate over last element which will be 
        // in its final position after N-1 passes

        // to store the index of minimum element
        int index = i;
        for(int j=i+1;j<N;++j){
            if(A[j]<A[index]){
                index = j;
            }
        }
        swap(A[index], A[i]);
    }
}

void show(vector<int> &A){
    for(int &x:A)   cout<<x<<" ";
    cout<<"\n";
}


int main(){
    vector<int> A ={1,7, 3, 2, 4};

    show(A);
    selection_sort(A);
    show(A);


    return 0;
}