// My Code school
// Pointers to Pointers in C/C++
// https://www.youtube.com/watch?v=d3kd5KbGB48&list=PL2_aWCzGMAwLZp6LMUKI3cc7pgGsasm2_&index=4

#include <iostream>
using namespace std;

int main(){
    int x = 5;
    int *p = &x;
    // Pointer is a type of variable that stores the address of another variable
    cout<<"address of x  &x: "<<&x<<"\n";
    cout<<"address of x  p: "<<&x<<"\n";
    cout<<"value of x  x: "<<x<<"\n";
    cout<<"value of x  x: "<<*p<<"\n";
    *p = 6;

    // so we can also have pointer to the pointer variable
    int **q = &p;
    cout<<"address of p is &p: "<<&p<<"\n";
    cout<<"address of p is q: "<<q<<"\n";
    cout<<"value of p  p: "<<p<<"\n";
    cout<<"value of p  *q: "<<*q<<"\n";

    return 0;
}