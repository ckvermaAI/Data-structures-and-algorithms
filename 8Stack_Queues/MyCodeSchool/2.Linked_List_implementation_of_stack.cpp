// My Code School
// Data Structures: Linked List implementation of stacks
// https://www.youtube.com/watch?v=MuwxQ2IB8lQ&list=PL2_aWCzGMAwI3W_JlcBbtYTwiQSsOTa6P&index=16

#include <bits/stdc++.h>
using namespace std;

struct ListNode{
    int data;
    ListNode* next;
    ListNode(int val): data(val), next(NULL) {}
};

ListNode* head=NULL;

void Push(int x){
    if(head==NULL){
        head=new ListNode(x);
        return;
    }
    ListNode* newNode=new ListNode(x);
    newNode->next=head;
    head=newNode;
}

void Pop(){
    if(head==NULL){
        cout<<"Error: EMPTY STACK\n";
        return;
    }
    ListNode* temp=head;
    head=head->next;
    free(temp);

}

int top(void){
    if(head==NULL){
        cout<<"Error: EMPTY STACK\n";
        return -1;
    }
    return head->data;
}

void Print(void){
    ListNode* current=head;
    while(current){
        cout<<current->data<<" ";
        current=current->next;
    }
    cout<<"\n";
    return;
}


int main(){
    Push(5);Print();
    Push(15);Print();
    Push(3);Print();
    Pop();Print();
    Push(8);Print();



    return 0;
}