// My Code school
// Pointers and 2-D arrays
// https://www.youtube.com/watch?v=sHcnvZA2u88&list=PL2_aWCzGMAwLZp6LMUKI3cc7pgGsasm2_&index=10

#include <bits/stdc++.h>
using namespace std;

void print(int (*A)[3]){         // or A[][3]
    // because we are passing the array B
    // and B which is base address of 2d-array B will return 
    // a pointer to one dimensional array of size 3
    printf("yoyo\n");
}

int main(){
    // A[i] is same as *(A+i)
    // &A[i] is same as (A+i)

    int B[2][3]={{1,2,3},{4,5,6}};
    // B is array of size 2 
    // and each element of array B is itself a array of size 3
    // Hence, B is a     int(*)[3]      type

    // This is wrong because B is array of 3 interger 
    // int *p=B;

    int (*p)[3]=B;

    printf("%d  %d\n", B, &B[0]);
    printf("%d  %d  %d\n", *B, B[0], &B[0][0] ) ;
    printf("%d \n", B+1);
    printf("%d  %d  %d\n", *(B+1), B[1], &B[1][0] );
    printf("%d  %d  %d\n", *(B+1)+2, B[1]+2, &B[1][2] );
    print(B);

    /*
    B[i][j] = * (B[i] + j ) = *( *(B + i) + j )
    
    */


    return 0;
}