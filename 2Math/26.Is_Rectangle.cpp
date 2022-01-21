// https://www.interviewbit.com/problems/is-rectangle/

#include <bits/stdc++.h>
using namespace std;


int solve(int A, int B, int C, int D) {
    if(A==B and C==D)   return 1;
    else if(A==C and B==D)  return 1;
    else if(A==D and B==C)  return 1;
    return 0;
}
