// My code school
// Data structures: Array implementation of stacks
// https://www.youtube.com/watch?v=sFVxsglODoo&list=PL2_aWCzGMAwI3W_JlcBbtYTwiQSsOTa6P&index=15

#include <bits/stdc++.h>
using namespace std;

#define MAX_SIZE 101
int A[MAX_SIZE];
int top=-1;

void Push(int x){
    if(top==MAX_SIZE-1){
        cout<<"Error: Stack Overflow!!\n";
        return ;
    }
    A[++top]=x;
}

void Pop(){
    if(top==-1){
        cout<<"Stack is Empty\n";
        return;
    }
    top--; 
}

int Top(){
    if(top==-1){
        cout<<"Stack is Empty\n";
        return -1;
    }
    return A[top];
}

void Print(){
    for(int i=0;i<=top;++i)
        cout<<A[i]<<" ";
    cout<<"\n";
}


int main(){
    Push(2);Print();
    Push(5);Print();
    Push(10);Print();
    Pop();Print();
    Push(12);Print();


    return 0;
}