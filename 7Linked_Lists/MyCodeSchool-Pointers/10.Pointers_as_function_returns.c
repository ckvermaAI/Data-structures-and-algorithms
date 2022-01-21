#include <stdio.h>
#include <stdlib.h>

int Add_by_value(int a,int b){
    int c=a+b;
    return c;
}

int *Add_by_ref(int *a, int *b){
    // This is not right 
    // this value can be changed by another function call
    // because after completion of this program 
    // the memory which is used by "c" can be used by some another variable
    int c= (*a)+(*b);
    return &c;
}

int *Add_by_reference(int *a, int *b){
    // instead of returning the local variable address which is allocated on stack and will deallocated automatically when the func call ends
    // we can use/return the address of a variable which is either global or present in heap i.e. dynamically allocated memory
    int *p= (int*) malloc(sizeof(int));
    *p = (*a)+(*b);
    return p;
}

int main(){
    int a=2,b=4;
    
    // Add by value
    // int c = Add_by_value(a,b);
    // printf("%d\n",c);

    // Add be reference -wrong
    // int *d = Add_by_ref(&a,&b);
    // printf("%d\n", *d);

    // Add be reference -right
    int *e = Add_by_reference(&a,&b);
    printf("%d\n", *e);

    

    return 0;
}