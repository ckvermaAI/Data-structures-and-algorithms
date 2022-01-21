#include <iostream>
using namespace std;


void increment_by_pointers(int *a){
    // call by reference 
    *a=(*a)+1;
}

void increment_by_ref_operator(int &a){
    // call by reference 
    a=a+1;
}

void increment(int a){
    // call by value 
    a = a + 1;
}

int main(){

    int a= 10;
    cout<<a<<"\n";
    increment_by_pointers(&a);
    cout<<a<<"\n";

    return 0;
}