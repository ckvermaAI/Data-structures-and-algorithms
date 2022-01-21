// https://www.interviewbit.com/problems/rotate-list/
#include <bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(x),next(NULL){}
};

void printList(ListNode *head){
    if(head==NULL){
        cout<<"EMPTY LIST\n";
        return;
    }
    while(head->next!=NULL){
        cout<<head->val<<"->";
        head=head->next;
    }
    cout<<head->val<<"\n";
}

void insert(int value, ListNode** head){
    if(*head==NULL){
        *head=new ListNode(value);
        return;
    }
    ListNode *temp = *head;
    *head= new ListNode(value);
    (*head)->next=temp;
    return;
}


ListNode* rotateRight(ListNode* A, int B) {
    ListNode fakehead(0);
    ListNode *current=A, *start=&fakehead;
    int count=0, rotate;
    while(current){ count++; current=current->next;}
    rotate=count-B%count;
    // cout<<"rotate from start "<<rotate<<"\n";
    if(rotate==count)   return A;
    ListNode *left, *right, *temp=A;
    while(rotate-1){ rotate--; temp=temp->next;}
    left=A;
    right=temp->next;
    temp->next=NULL;
    // printList(left);
    // printList(right);
    while(right){
        start->next=right;
        start=start->next;
        right=right->next;
    }
    while(left){
        start->next=left;
        start=start->next;
        left=left->next;
    }
    start->next=NULL;
    return fakehead.next;
}

int main(){

    ListNode *head=NULL, *res;
    int n[]={5,4,3,2,1};
    for(int i=0;i<5;++i) insert(n[i], &head);

    printList(head);
    res=rotateRight(head,2);
    printList(res);

    return 0;
}