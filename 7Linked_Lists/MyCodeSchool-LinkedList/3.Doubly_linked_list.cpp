// My Code School
// Doubly Linked List - Implementation in C/C++
// https://www.youtube.com/watch?v=VOQNf1VxU3Q&list=PL2_aWCzGMAwI3W_JlcBbtYTwiQSsOTa6P&index=13

#include <bits/stdc++.h>
using namespace std;

struct ListNode{
    int data;
    ListNode *next;
    ListNode *prev;
    ListNode(int val): data(val), next(NULL), prev(NULL) {}
};

/*

ListNode* GetNewNodeStack(int x){


    // This is wrong way of creating the newNode because as this function call completes the memory allocated to the local variables of this function in stack will be automatically deallocated

    
    ListNode newNode(x);
    return &newNode;
}

*/

ListNode* GetNewNodeHeap(int x){
    /*
    This is correct way of creating a newNode for the linked list
    because after this function call the memory allocated to newNode will remain intact i.e. it will not be de-allocated automatically
    
    */
    ListNode* newNode = new ListNode(x);
    return newNode;
}



void insertHead(ListNode* &head, int x){
    /*
    
    ListNode myNode(x);
    
    we can simply create new node as a local variable but why we create/allocate memory to node dynamically?
    -> local variables will be cleared from memory when fucntion call will finish 
    -> we want to have control over these allocated memory i.e. memory will be de-allocated only when we explicitly delete that memory

    */
   ListNode* temp = GetNewNodeHeap(x);
   if(head==NULL){
       head=temp;
       return;
   }
   head->prev=temp;
   temp->next=head;
   head=temp;
}

void Print(ListNode *head){
    if(head==NULL)  return;
    ListNode* current=head;
    cout<<"Forward: ";
    while(current){
        cout<<current->data<<" ";
        current=current->next;
    }
    cout<<"\n";
}

void ReversePrint(ListNode* head){
    if(head==NULL)  return;
    ListNode*current=head;
    // Going to last Node
    while(current->next!=NULL){
        current=current->next;
    }
    // traversing backward using prev pointer
    cout<<"Reverse: ";
    while(current){
        cout<<current->data<<" ";
        current=current->prev;
    }
    cout<<"\n";
}


int main(){
    ListNode *head=NULL;
    insertHead(head, 2);
    insertHead(head, 4);
    insertHead(head, 6);
    insertHead(head, 5);
    Print(head);
    ReversePrint(head);

    return 0;
}