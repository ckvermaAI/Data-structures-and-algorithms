// https://www.interviewbit.com/problems/triplets-with-sum-between-given-range/

#include <bits/stdc++.h>
using namespace std;


bool isinA(double x){
    if(x>0 and x<(2.0/3.0)) return true;
    return false;
}

bool isinB(double x){
    if(x>=(2.0/3.0) and x<1.0) return true;
    return false;
}

bool isinC(double x){
    if(x>=1.0 and x<2.0) return true;
    return false;
}


int solve(vector<string> &s) {
    /*

    We have to find a triplet (a,b, c) such that  1< a+b+c <2
    Now, one thing we can do is to divide the interval possible range of numbers in two segments (0, 1) [1,2) 

    Lets say if we further divide the left interval in two parts
        a= (0,⅔) b= [⅔, 1) c =[1,2)

    Choosing whether a particular belong to a particular set
    a a a    
    A a b
    A a c
    A b b
    A b c

    so these are only five possible cases

    Now, for caseI, 
    Maximum range possible is ⅔*2 or 2 ( as we are not including ⅔ ) thus it is safe to say that it will not exclude the maximum range of limit
    Now, if solution exist for this case we need to only ensure that sum is >1
    Max1a, max2a, max3a

    Now, for case II, 
        max1a , max2a, max1b   and    min1a, min2a, min1b

    Case III, IV and V, 
        Min, min, min

    So we need to calculate only
    max1a, max2a, max3a, max1b
    min1a, min2a, min1b, min2b, min1c

    */

    const int N=s.size();
    vector<double> A(N);

    for(int i=0;i<N;++i){
        A[i] = stod(s[i]);
    }

    double max1a= INT_MIN, max2a=INT_MIN, max3a=INT_MIN, max1b = INT_MIN;
    double min1a = INT_MAX, min2a = INT_MAX, min1b = INT_MAX, min2b =INT_MAX, min1c = INT_MAX;

    // calculating all required information
    for(int i=0;i<N;++i){

        // if number is in interval "a" and it is greater than max1a
        if(max1a<A[i] and isinA(A[i])){
            max3a = max2a;
            max2a = max1a;
            max1a = A[i];
        }
 
        // if number is in interval "a" and it is greater than max2a
        else if(max2a<A[i] and isinA(A[i])){
            max3a = max2a;
            max2a = A[i];
        }

        // if number is in interval "a" and it is greater than max3a
        else if(max3a<A[i] and isinA(A[i])){
            max3a = A[i];
        }

        // if number is in interval "b" and it is greater than max1b
        else if(max1b<A[i] and isinB(A[i])){
            max1b = A[i];
        }



        // if number is in "a" and it is smaller than min1a
        if(min1a>A[i] and isinA(A[i])){
            min2a = min1a;
            min1a = A[i];
        }

        // if number is in "a" and it is smaller than min2a
        else if(min2a>A[i] and isinA(A[i])){
            min2a = A[i];
        }

        // if number is in "b" and it is smaller than min1b
        else if(min1b>A[i] and isinB(A[i])){
            min2b = min1b;
            min1b = A[i];
        }

        // if number is in "b" and it is smaller than min2a
        else if(min2b>A[i] and isinB(A[i])){
            min2b = A[i];
        }

        // if number is in "c" and it is smaller than min1c
        else if(min1c>A[i] and isinC(A[i])){
            min1c = A[i];
        }

    }

    // now check all the five cases
    // Case 1 => A A A  
    if((max1a+max2a+max3a)>1.0)   return 1;

    // Case 2 => A A B  
    else if((max1a+max2a+max1b)>1.0 and (max1a+max2a+max1b)<2.0)   return 1;
    else if((min1a+min2a+min1b)>1.0 and (min1a+min2a+min1b)<2.0)   return 1;

    // case 3 => A A C
    else if((min1a+min2a+min1c)<2.0)   return 1;

    // case 4 => A B B
    else if((min1a+min1b+min2b)<2.0)   return 1;

    // case 5 => A B C
    else if((min1a+min1b+min1c)<2.0)   return 1;

    return 0;
}