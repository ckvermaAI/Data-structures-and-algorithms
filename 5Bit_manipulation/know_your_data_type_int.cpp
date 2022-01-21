// https://www.youtube.com/watch?v=zxb8DvLUqcM
#include <bits/stdc++.h>
using namespace std;

int main(){
    int a=100000;
    int b=200000;

    cout<<"Binary representation of a*b into 35 bits (because it is 35 bits number)\n => "<<bitset<35>((long long)a*b)<<"\n";
    cout<<"Actual number due to overflow\n=> "<<a*b<<"\n";

    return 0;
}