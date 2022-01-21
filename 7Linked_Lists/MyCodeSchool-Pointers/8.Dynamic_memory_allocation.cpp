#include <stdio.h>
#include <stdlib.h>

int main(){

    int a;      // goes on stack
    int *p;
    
    // dynamically memory allocation
    p = new int;
    *p =10;
    delete p;

    p = new int[20];

    delete p; 

    /*
     
    New and delete operators are type safe 
    type safe => that they are used with a type and return pointers to a particular type

    size_t = unsigned int 

    
    */

}