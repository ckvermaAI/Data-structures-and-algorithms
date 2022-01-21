// My Code School

// Function pointers and callbacks

// https://www.youtube.com/watch?v=sxTFSDAZM8s&list=PL2_aWCzGMAwLZp6LMUKI3cc7pgGsasm2_&index=16
// https://stackoverflow.com/questions/29577833/abs-implicit-declaration-error-after-including-math-h

#include <stdio.h>
// #include <math.h>
#include <stdlib.h>

// As a rule of thumb the mathematical functions that operate on floating point numbers are in math.h, and the ones that operate on integers are in stdlib.h.


int compare(int a, int b){
    // decide the ranking of the element
    if(a>b) return 1;
    else return -1;
}

int abs_compare(int a, int b){
    if(abs(a)>abs(b) ) return 1;
    else return -1;
}   

void BubbleSort(int *A, int n, int (*compare)(int,int) ){
    int i,j,temp;
    for(i=0;i<n;++i){
        for(j=0;j<n-1;++j){
            if(compare(A[j],A[j+1])>0 ){
                temp=A[j];
                A[j]=A[j+1];
                A[j+1]=temp;
            }
        }
    }
}

int quickSortCompare(const void* a, const void *b){
    int A = *((int *) a);   // type casting to int* and getting value
    int B = *((int *) b);
    return A-B;
}

int main(){
    int i, A[]={2,3,-5,-1,6,4};

    // Bubble sort
    // BubbleSort(A,6, compare);
    // for(i=0;i<6;++i)    printf("%d ", A[i]);

    /* 

    quick sort in stdlib.h =>
    qsort(arg1, arg2, arg3)
        arg1 = array of any type
        arg2 = size of array
        arg3 = size of the data type
        arg4 =  comparing function 

                with signature =>
                (data_type) compare (const void * a, const void *b)

                why void pointers because void pointers are generic pointers we can typecase into any other data type

    */


    qsort(A, 6, sizeof(int), quickSortCompare);
    for(i=0;i<6;++i)    printf("%d ", A[i]);

    return 0;
}