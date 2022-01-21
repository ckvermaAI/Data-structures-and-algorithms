// My Code school
// Dynamic memory allocation in C - malloc calloc realloc free
// https://www.youtube.com/watch?v=xDVC3wKjS64&list=PL2_aWCzGMAwLZp6LMUKI3cc7pgGsasm2_&index=13

#include <stdio.h>
#include <stdlib.h>

int main(){


    int n;
    printf("Enter the size: ");
    scanf("%d", &n);
    // malloc
    // int *A = (int*) malloc( n* sizeof(int));

    // calloc
    int *A = (int*) calloc( n, sizeof(int));

    // realloc
    A = (int*) realloc( A,2*n*sizeof(int));

    // if we set the size in realloc to zero then that is equivalent to free
    A = (int*) realloc( A, 0);      // equivalent to free

    // if we set first argument as null then it is equivalent to malloc
    A = (int*) realloc( NULL, n*sizeof(int));      // equivalent to malloc



    // for(int i=0;i<n;++i){
    //     A[i]=i+1;
    // }

    for(int i=0;i<2*n;++i){
        printf("%d ", A[i]);
    }

    return 0;

}