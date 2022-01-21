// https://www.youtube.com/watch?v=TzeBrDU-JaY&list=PL2_aWCzGMAwKedT2KfDMB9YA5DgASZb3U&index=5

#include <bits/stdc++.h>
using namespace std;

/*

MERGE SORT
if we know how to merge two sorted array then 
we can use that fact to sort the array
1) keep on dividing the elements
2) once we left with an array of size == 1 simply return it
3) after that merge two sorted half


ANALYSIS OF MERGE SORT 
1) Divide an d conquer algorithm
2) Recursive algoritjm
3) Stable sorting algorithm
4) Not in place 
    Space complexity = Theta(N)
5) Time complexity = Theta(N*log(N))
*/

void Merge(vector<int> &A, int low, int high, int mid){
    // left half == [low, mid]
    // right half == [mid+1, high]
    int l=low, r=mid+1;     // l for left and r for right
    int i=0;                // to iterate over auxiliary array

    // auxiliary array to store the sorted array
    vector<int> aux(high-low+1);
    while(l<=mid and r<=high){
        if(A[l]<A[r]){
            // smallest element is in left sub array
            aux[i++] = A[l++];
        }
        else{
            // smallest element is in right sub array
            aux[i++] = A[r++];
        }
    }

    while(l<=mid){
        aux[i++] = A[l++];
    }
    while(r<=high){
        aux[i++] = A[r++];
    }

    for(int i=low;i<=high;++i){
        A[i] = aux[i-low];
    }

}


void MergeSortUtil(vector<int> &A, int low, int high){
    // Base case - invalid case
    if(low>high)    return;
    // Base case - array of size 1
    if(low==high)   return;

    // recursion
    int mid = low+(high-low)/2;
    MergeSortUtil(A, low, mid);     // left subarray
    MergeSortUtil(A, mid+1, high);  // right subarray
    Merge(A, low, high, mid);       // merge two sorted halves
}

void MergeSort1(vector<int> &A){
    MergeSortUtil(A, 0, A.size()-1);
}

void show(vector<int>&A){
    for(int &x:A)   cout<<x<<" ";
    cout<<"\n";
}


int main(){

    vector<int> A= {4,3,5,1,2};
    
    show(A);
    MergeSort1(A);
    // MergeSortUtil(A, 0, A.size()-1);
    show(A);

    return 0;
}