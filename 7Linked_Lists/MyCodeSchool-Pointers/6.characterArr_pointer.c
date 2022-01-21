// My code School

// Character arrays and pointers - part 1
// https://www.youtube.com/watch?v=Bf8a6IC1dE8&list=PL2_aWCzGMAwLZp6LMUKI3cc7pgGsasm2_&index=8

// Character arrays and pointers - part 2
// https://www.youtube.com/watch?v=vFZTxvUoZSU&list=PL2_aWCzGMAwLZp6LMUKI3cc7pgGsasm2_&index=9

#include<stdio.h>
#include <string.h>

/*

1 Array and pointers are different types that are used in similar manner
2 Array are always passed to function by reference

*/

void print(char *C){
    // C[0]='A';
    while(*C!='\0'){
        printf("%c",*C);
        C++;
    }
    printf("\n");
}


int main(){

    // char C[20];
    // C[0]='J';
    // C[1]='O';
    // C[2]='H';
    // C[3]='N';

    // char C[5]="JOHN";

    char C[5]={'J','O','H','N', '\0'};

    // string gets stored as compile time constant
    char *A = "HELLO";      // read only string

    print(C);
    print(A);
    // printf("%s", C);

    return 0;
}