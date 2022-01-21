// My Code School
// Data structures: Array implementation of Queue
// https://www.youtube.com/watch?v=okr-XE8yTO8&list=PL2_aWCzGMAwI3W_JlcBbtYTwiQSsOTa6P&index=23

#include <bits/stdc++.h>
using namespace std;

#define MAX_SIZE  10
int arr[MAX_SIZE];
int front=-1, rear=-1;

/*

To implement queue with array we can consider it as a circular array
In circular array, if "current position" is "i" then
                    "next position" will be " (i+1) % N "
                    "prev position" will be " (i+N-1) % N"
                    
                    where N is size of array


*/

void Enqueue(int x){
    if(isFull()){
        cout<<"Queue is full\n";
        return;
    }
    else if(isEmpty()){
        front=0, rear=0;
    }
    // for circular array
    else{
        rear= (rear+1) % MAX_SIZE;

    }
    arr[rear]=x;
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
    // for array
    // if(rear==MAX_SIZE-1)    return true;
    
    // for circular array
    if( (rear+1) % MAX_SIZE==front )  return true; 
    return false;
}


int main(){


    return 0;
}

