// https://www.interviewbit.com/problems/reorder-list/

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

ListNode *reverseListWhole(ListNode *A){
    ListNode *current=A, *prev=NULL;
    while(current){
        ListNode *temp=current->next;
        current->next=prev;
        prev=current;
        current=temp;

    }
    return prev;
}

ListNode *getMid(ListNode* A){
    ListNode *slow=A,*fast=A->next;
    while(fast and fast->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

ListNode* reorderList(ListNode* A) {
    ListNode fakeHead(0);
    ListNode *mid=getMid(A);
    ListNode *left=A,*right=mid->next, *start=&fakeHead;
    mid->next=NULL;
    // printList(left);
    right=reverseListWhole(right);
    // printList(right);
    int count=0;
    while(left and right){
        if(count%2==0){
            start->next=left;
            left=left->next;
        }
        else{
            start->next=right;
            right=right->next;
        }
        start=start->next;
        count++;
    }
    if(left!=NULL){
        // this will be used when length of linked list is odd
        start->next=left;
        left=left->next;
        start=start->next;
    }
    if(right!=NULL){
        // this will be used when length of linked list is even
        start->next=right;
        right=right->next;
        start=start->next;
    }
    start->next=NULL;
    return fakeHead.next;
}


int main(){

    ListNode *head=NULL, *res;
    int n[]={10,9,8,7,6,5,4,3,2,1};
    for(int i=0;i<10;++i) insert(n[i], &head);
    
    printList(head);
    res=reorderList(head);
    printList(res);
    

    return 0;
}