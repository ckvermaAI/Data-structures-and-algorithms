// https://www.geeksforgeeks.org/heap-sort/
#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int> &A, int N, int i){
    // N = size of the segment of A
    // i = element to heapify 
    int root = i;
    int leftchild = 2*i + 1;
    int rightchild = 2*i + 2;

    // if left child is larger than root
    if(leftchild<N and A[leftchild]>A[root])
        root = leftchild;

    // if right child is larger than largest so far
    if(rightchild<N and A[rightchild]>A[root])
        root = rightchild;
    
    // if the largest is not root
    if(root!=i){
        swap(A[root], A[i]);

        // recursively heapify the affected sub tree
        heapify(A, N, root);
    }

}


void heapsort(vector<int>&A){
    const int N=A.size();
    
    // first heapify the current array
    // make max heap out of current array

    // initially all the elements of heap 
    // of leaf are sorted 
    for(int i=N/2-1;i>=0;--i){
        heapify(A, N, i);
    }

    // pick the maximum element from the heap
    // and put the element at last in array
    for(int i=N-1;i>0;--i){
        // move the current root(maximum element)
        // to the end
        swap(A[0], A[i]);

        // call max heapify on the reduced heap
        heapify(A, i, 0);
    }
}

void show(vector<int>&A){
    for(int &x:A)    cout<<x<<" ";
    cout<<"\n";
}

int main(){

    vector<int> A= {4, 2, 1, 3};
    show(A);
    heapsort(A);
    show(A);


    return 0;
}