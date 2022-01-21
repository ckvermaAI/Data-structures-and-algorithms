// https://www.interviewbit.com/problems/min-stack/

#include <bits/stdc++.h>
using namespace std;

class MinStack{
    MinStack();
    void push(int x);
    void pop(void);
    int top(void);
    int getMin(void);
};

stack <int> num, minS;

MinStack::MinStack() {
    // resetting the global "num"
    while(!num.empty()){
        num.pop();
    }
    // resetting the global "minS"
    while(!minS.empty()){
        minS.pop();
    }
}

void MinStack::push(int x) {
    num.push(x);
    if(minS.empty()){
        minS.push(x);
    }
    else{
        minS.push(min(x, minS.top()));
    }
}

void MinStack::pop() {
    if(!num.empty()){
        num.pop();
        minS.pop();
    }
}

int MinStack::top() {
    if(!num.empty()){
        return num.top();
    }
    return -1;
}

int MinStack::getMin() {
    if(!minS.empty()){
        return minS.top();
    }
    return -1;
}

