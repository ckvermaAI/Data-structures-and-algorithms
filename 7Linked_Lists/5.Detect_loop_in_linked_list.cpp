// Geeks for Geeks problem
// https://www.geeksforgeeks.org/detect-loop-in-a-linked-list/

#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node(int x): data(x), next(NULL) {}
};

void push(Node **head_ref, int new_data){
    Node* new_node = new Node(0);    
    new_node->data=new_data;
    new_node->next=(*head_ref);
    *head_ref = new_node;
}

void print_list(Node *head_ref){
    while(head_ref->next!=NULL){
        cout<<head_ref->data<<"->";
        head_ref=head_ref->next;
    }
    cout<<head_ref->data<<"\n";
}

int detectLoop(Node *A){
    /*
     Floyd’s Cycle-Finding Algorithm
        A) Traverse linked list using two pointers.
        B) Move one pointer(slow_p) by one and another pointer(fast_p) by two.
        C) If these pointers meet at the same node then there is a loop. If pointers do not meet then linked list doesn’t have a loop.
    Time Complexity O(N), Space Complexity O(1)
    */
    Node *fast=A, *slow=A;
    while(slow and fast and fast->next){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)  return 1;
    }
    return 0;
}

int main(){

    Node* head=NULL;
    push(&head, 20);
    push(&head, 4);
    push(&head, 6);
    push(&head, 3);

    head->next->next->next->next=head;
    cout<<detectLoop(head);
    // print_list(head);


    return 0;
}