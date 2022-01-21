// https://www.interviewbit.com/problems/largest-rectangle-in-histogram/

// Using stacks - O(N)
// https://www.geeksforgeeks.org/largest-rectangle-under-histogram/

#include <bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector<int> &A) {
    const int N = A.size();
    
    // stack hold the indices of the histogram
    // the bars stored in stack are always in increasing order
    // of their heights
    stack<int> s;
    
    int max_area=0, i=0;

    while(i<N){
        // if this bar is higher than the bar on top of stack
        // push it to stack
        if(s.empty() or A[s.top()]<=A[i])   s.push(i++);
        
        // If this bar is lower than top of stack then calculate
        // area of rectangle with stack top as the smallest 
        // (or minimum height) bar. "i" is "right index" for top 
        // and element before top in stack is "left index"
        else{
            int top = s.top();
            s.pop();
            
            int width;
            // if this is smallest element 
            if(s.empty())  width = i;
            else    width = i-s.top()-1;

            max_area = max(max_area, width*A[top]);
        }
    }

    // Now pop the remaining bars from stack and calculate area with every 
    // popped bar as smallest bar
    while(!s.empty()){
        int top = s.top();
        s.pop();
        
        int width;
        // if this is smallest element 
        if(s.empty())  width = i;
        else    width = i-s.top()-1;

        max_area = max(max_area, width*A[top]);
    }
    
    return max_area;

}