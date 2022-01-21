// https://www.interviewbit.com/tutorial/heap-sort-algorithm/#heap-sort-algorithm

#include <bits/stdc++.h>
using namespace std;

// To heapify a subtree rooted with node i which is 
// heapify:- A process which helps regaining heap properties in tree after removal
void heapify(int A[], int n, int i){
    // Simply  a implementation of shiftDown
    
    int largest = i; // initialize largest as root
    int left_child = 2*i +  1; 
    int right_child = 2*i + 2;

    // if left child is larger than root
    if(left_child<n and A[left_child]>A[largest])
        largest=left_child;

    // If right child is larger than largest so far
    if(right_child<n and A[right_child]>A[largest])
        largest=right_child;
    
    // if largest is not root 
    if(largest!=i){
        swap(A[i],A[largest]);

        // recursively heapify the affected subtree
        heapify(A,n, largest);
    }
}



// Main function for the heapsort
void heapSort(int A[],int n){
    
    // Build Heap inplace (rearrange array)
    // for(int i=n/2;i>=0;--i) heapify(A,n,i);
    for(int i=n/2;i>=0;--i) siftDown(A,i,n);

    cout<<"here: ";
    for(int i=0;i<n;++i)   cout<<A[i]<<" ";

    // one by one extract an element from the heap
    for(int i=n-1;i>=0;--i){
        // Move current node to the end
        swap(A[0], A[i]);

        // call max heapify on the reduced heap
        // heapify(A,i,0);
        siftDown(A, 0, i);
    }
}


void printArray(int A[], int n){
    for(int i=0;i<n;++i)
        cout<<A[i]<<" ";
    cout<<"\n";
}


int main(){

    int A[]={22,19,3,25,26,7};   // array to be sorted 
    int n=sizeof(A)/sizeof(A[0]);   // n is size of the array

    heapSort(A,n);

    cout<<"Sorted array is \n";
    printArray(A,n);

    return 0;
}