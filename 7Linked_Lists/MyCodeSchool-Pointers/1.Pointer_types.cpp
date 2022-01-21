// My Code School
// Pointer types, pointer arithmetic, void pointers
// https://www.youtube.com/watch?v=JTttg85xsbo&list=PL2_aWCzGMAwLZp6LMUKI3cc7pgGsasm2_&index=3

#include <iostream>
using namespace std;

int main(){
    int a=1025;
    int *p= &a;
    printf("size of interger is %d bytes\n", sizeof(int));
    printf("Address = %d, value = %d\n", p, *p);
    printf("Address = %d, value = %d\n", p+1, *(p+1) );
    // char pointer
    char *p0;
    p0 = (char *)p;     // typecasting
    printf("size of char is %d bytes\n", sizeof(char));
    printf("Address = %d, value = %d\n", p0, *p0);
    printf("Address = %d , value = %d\n", p0+1, *(p0+1) );
    // 1025 = 00000000 00000000 00000100 00000001

    // generic pointer - void pointer 
    

    return 0;
}