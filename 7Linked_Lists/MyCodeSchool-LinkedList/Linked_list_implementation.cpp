// My Code School
// Linked List in C/C++ - Inserting a node at beginning
// https://www.youtube.com/watch?v=cAZ8CyDY56s&list=PL2_aWCzGMAwI3W_JlcBbtYTwiQSsOTa6P&index=6

// Linked List in C/C++ - Insert a node at nth position
// https://www.youtube.com/watch?v=IbvsNF22Ud0&list=PL2_aWCzGMAwI3W_JlcBbtYTwiQSsOTa6P&index=7

// Linked List in C/C++ - Delete a node at nth position
// https://www.youtube.com/watch?v=Y0n86K43GO4&list=PL2_aWCzGMAwI3W_JlcBbtYTwiQSsOTa6P&index=8

#include <bits/stdc++.h>
using namespace std;

struct ListNode{
    int data;
    ListNode *next;
    ListNode(int val): data(val), next(NULL) {}
};

void insertBegin(ListNode* &root, int val){
    if(root==NULL){
        root = new ListNode(val);
        return;
    }
    ListNode* temp=root;
    root = new ListNode(val);
    root->next=temp;
    return;
}

void insertAtN(ListNode* & root, int val, int pos){
    // we are assuming the pos is valid
    // pos start from 1
    ListNode* temp = new ListNode(val);
    if(pos==1){
        temp->next=root;
        root=temp;
        return;
    }

    // If we want to insert at Nth pos
    // we should move to N-1 position
    ListNode* current=root;
    pos-=2;
    while(pos--){
        current=current->next;
    }
    temp->next=current->next;
    current->next=temp;
}

void insertAtEnd(ListNode *&head, int val){
    if(head==NULL){
        head=new ListNode(val);
        return;
    }
    ListNode* current=head;
    while(current->next!=NULL){
        current=current->next;
    }
    current->next = new ListNode(val);
}

void deleteAtN(ListNode* & root, int pos){
    // we are assuming the pos is valid
    // pos start from 1
    /*

    1. Fix the links
    When we are deleting some nodes then first thing we do is to fix
    the links ( fixing the links - final links position after some insertion and deletion operation which may affect the links in our linked list )
    In other words, we simply detach the node from linked list but still it is occupying some space in the memory(more particularly as the node is allocated using dynamic memory which is heap section of memory)

    2. Explicitly delete the node which is not the part of the list
     
    */
    if(pos==1){
        ListNode*temp=root;
        root=temp->next;
        delete temp;
        return;
    }

    // if we want to delete the Nth position then
    // we should move to N-1 th position

    ListNode* current=root;
    pos-=2;
    while(pos--){
        current=current->next;
    }
    ListNode* temp=current->next;
    current->next=temp->next;
    delete temp;
}

void ShowList(ListNode* root){
    ListNode* current=root;
    while(current->next!=NULL){
        cout<<current->data<<"->";
        current=current->next;
    }
    cout<<current->data;
}
 

// int main(){
//     ListNode *head=NULL;
//     insertAtEnd(head,2);
//     insertAtEnd(head,4);
//     insertAtEnd(head,6);
//     insertAtEnd(head,5);
//     ShowList(head); 
//     deleteAtN(head,1);
//     cout<<"\n";
//     ShowList(head); 


//     return 0;
// }