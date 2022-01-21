// My Code school
// Function Pointers in C / C++
// https://www.youtube.com/watch?v=ynYtgGUNelE&list=PL2_aWCzGMAwLZp6LMUKI3cc7pgGsasm2_&index=15

#include <stdio.h>

/*

Can pointers points to function? - what is the address of function
what is the use case of function pointer?

STORY =>

whenever we say "memory" in context of program we mean "primary storage/Main Memory" -> "RAM". hence when we say application memory == chunk of main memory

Application's memory consist of 4 parts =>
1) Code/text segment
2) static/global variables segment
3) Stack
4) Heap

compiler converts the ".c" or ".cpp" file to "executable file"
and executable file contains the machine code corresponding to the program

Executable file is stored in secondary storage of the device and instructions are not directly executed from secondary storage these are first copied to primary storage.


NOW WHAT HAPPENS IN CODE/TEXT SEGMENT ?
Each memory block in this segment stores a instructions. Instructions in this segment are executed sequentially only exception will be when one segment explicitly tells to go/jump to some other instruction ( happens when we call function or goto statement )

*/


int Add(int a, int b){
    return a+b;
}

void PrintHello(const char *name){
    printf("Hello %s\n", name);
}

int *Func1(int, int);       // declaring a func which retrun pointers
int (*Func2)(int, int);       // declaring a func pointer


int main(){

    // CAUTION - syntax to declare a function pointers
    // (return type of func) (*p)  (arg1 type, arg2 type, .....)
    // int (*p)(int,int);       ---- function pointer
    // int *p (int, int)        ---- declaration of function which return the pointer

    // (return type of func) (*p)  (arg1 type, arg2 type, .....)
    int (*p)(int,int);


    // storing the address of function in the func. pointer
    p = &Add;            // syntax 1
    // p = Add;                // syntax 2
    

    // dereferencing the function pointer to get the function and passing the argument to the function
    int c = (*p)(2,3);          // syntax 1    
    // int c = p(2,3);         // syntax 2


    // printing the value of c 
    // printf("%d", c); 


    // printHello pointer
    void (*ptr)(const char *);
    ptr = &PrintHello;
    ptr("TOM");

    return 0;
}