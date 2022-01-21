// My Code School
// Data structures: Linked List implementation of Queue
// https://www.youtube.com/watch?v=A5_XdiK4J8A&list=PL2_aWCzGMAwI3W_JlcBbtYTwiQSsOTa6P&index=24

#include <bits/stdc++.h>
using namespace std;

struct ListNode{
    int data;
    ListNode* next;
    ListNode(int val): data(val), next(NULL) {}
};

ListNode *front=NULL, *rear=NULL;

void Enqueue(int x){
    ListNode* newNode = new ListNode(x);
    if(front==NULL and rear==NULL){
       front=rear=newNode;
       return;
    }
    rear->next=newNode;
    rear=newNode;
}

void Dequeue(void){
    ListNode *temp=front;
    if(front==NULL and rear==NULL){
        cout<<"List is Empty\n";
        return;
    }
    else if(front==rear){
        front=rear=NULL;
        free(temp);
        return;
    }
    front=front->next;
    free(temp);
}


int main(){


    return 0;
}