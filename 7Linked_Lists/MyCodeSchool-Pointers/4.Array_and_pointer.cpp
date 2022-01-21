#include <bits/stdc++.h>
using namespace std;


int main(){
    int arr[5]={1,2, 3, 4,5};
    /*
    arr is base address
    we cannot use pointer arithmetic on arr
    arr++;   // this is invalid

    int *p = arr;
    p++; // this is valid
    */
    cout<<"address of arr arr: "<<arr+0<<"\n";
    cout<<"address of arr &arr[0]: "<<&arr[0]<<"\n";
    cout<<"value of arr[0] arr[0]: "<<arr[0]<<"\n";
    cout<<"value of arr[0] *arr: "<<*arr<<"\n";

    return 0;
}