// My Code School
// Data structures: Array implementation of Queue
// https://www.youtube.com/watch?v=okr-XE8yTO8&list=PL2_aWCzGMAwI3W_JlcBbtYTwiQSsOTa6P&index=23

#include <bits/stdc++.h>
using namespace std;

#define MAX_SIZE  10
int arr[MAX_SIZE];
int front=-1, rear=-1;


void Enqueue(int x){
    if(isFull()){
        cout<<"Queue is full\n";
        return;
    }
    else if(isEmpty()){
        front=0, rear=0;
        arr[rear] = x;
    }
    else{
        rear++;
        arr[rear]=x;
    }
}

void Dequeue(void){
    if(isEmpty()){
        cout<<"Queue is Empty\n";
        return;
    }
    else if(rear==front){
        front=-1, rear=-1;
        return;
    }
    front++; 
}


bool isEmpty(){
    if(front==-1 and rear==-1)
        return true;
    return false;
}


bool isFull(){
    if(rear==MAX_SIZE-1)    return true;
    return false;
}






int main(){


    return 0;
}

