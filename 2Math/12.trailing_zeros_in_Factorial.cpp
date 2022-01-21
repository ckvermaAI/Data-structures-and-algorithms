#include <bits/stdc++.h>
using namespace std;

int trailingZeroes2(int A) {
    // Time comeplexity = O(N)
    int steps = A/5;
    int zeros = 0;

    for(int i=1;i<=steps;++i){
        int num=5*i;
        while(num>=5 and num%5==0){
            zeros++;
            num = num/5;
        }
    }
    return zeros;
}

int trailingZeroes(int A) {
    // Time complexity is log(N)
    /*
    To find out number of 5's in the factorial(A),
    we can just divide it by 5 (this will count all 5, 10, 15, 20, 25)
    but will not count another 5 corresponding to 25
    
    Thus, keep on dividing the number by 5 and add the output to 
    res ( similar to decimal representation of number )

    */
    int res=0;
    while(A){
        int temp=A/5;
        res += (temp);
        A = temp;
    }
    return res;
}

