// https://www.interviewbit.com/problems/atoi/

#include <bits/stdc++.h>
using namespace std;

int atoi(const string A) {
    istringstream ss(A);
    int x=0;
    ss>>x;
    return x;
}
