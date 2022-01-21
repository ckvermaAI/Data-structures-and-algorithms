// https://www.interviewbit.com/problems/distribute-in-circle/

#include <bits/stdc++.h>
using namespace std;

int solve(int A, int B, int C) {
    return (A+C-1)%B;    
}
