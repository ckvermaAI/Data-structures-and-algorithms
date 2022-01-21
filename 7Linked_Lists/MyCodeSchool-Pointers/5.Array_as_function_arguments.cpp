// My Code school
// Arrays as function arguments
// https://www.youtube.com/watch?v=CpjVucvAc3g&list=PL2_aWCzGMAwLZp6LMUKI3cc7pgGsasm2_&index=7&t=48s

#include <iostream>

// "int* A" or "int A[]"    ... are the same
// we do not pass the whole array in the function
// we just pass the address of first element or base address of array
int SumOfElements(int *A, int size){
    int sum=0;
    printf("SOE - Size of A = %d, Size of A[0] = %d\n", sizeof(A), sizeof(A[0]));
    for(int i=0; i<size; i++) sum+=A[i];    // A[i] is same *( A + i )
    return sum;
}

int main(){

    int A[]={1,2,3,4,5};
    int size = sizeof(A)/sizeof(A[0]);
    int total = SumOfElements(A,size);  // A can be used for &A[0]
    printf("Sum of elements = %d\n", total);
    printf("Main - Size of A = %d, Size of A[0] = %d\n", sizeof(A), sizeof(A[0]));

    return 0;
}