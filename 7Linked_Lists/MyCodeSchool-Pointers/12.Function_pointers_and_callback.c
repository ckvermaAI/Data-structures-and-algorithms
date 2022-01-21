// My code school
// Function pointers and callbacks
// https://www.youtube.com/watch?v=sxTFSDAZM8s&list=PL2_aWCzGMAwLZp6LMUKI3cc7pgGsasm2_&index=16

#include <stdio.h>

void A(){
    printf("Hello\n");
}

void B(void (*ptr)()){  // function pointer as argument
    
    ptr();  // call-back function that "ptr" points to
}


int main(){
    // a void pointer which takes no argument
    // initialize this pointer with A()
    void (*p)() = &A;
    B(p);

    // instead of above two statement we can also write
    B(A);   // because name of function also return the address of function

    return 0;
}