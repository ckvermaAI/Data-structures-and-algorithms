// https://www.interviewbit.com/problems/swap-list-nodes-in-pairs/
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

ListNode* reverseKList(ListNode* A, int B=2) {
    if(B==1)   return A;
    ListNode *current=A,*last_node=NULL;
    int count=0, slots, tempB;
    while(current){ 
        if(current->next==NULL){
            last_node=current;
        }
        count++; current=current->next;
        }
    slots=count/B;
    ListNode fakehead(0);
    ListNode *cstart=A, *cend=A, *start=&fakehead,*res,*temp;
    while(slots){
        tempB=B-1;
        while(tempB){  tempB--; cend=cend->next;}
        temp=cend->next;
        
        cend->next=NULL;
        res=reverseListWhole(cstart);      

        start->next=res;
        while(start->next){start=start->next;}

        cstart=temp;
        cend=temp;
        slots--;
    }
    
    if(count%2){
        start->next=last_node;
    }
    return fakehead.next;
}

int main(){

    ListNode *head=NULL, *res;
    int n[]={10,9,8,7,6,5,4,3,2,1};
    for(int i=0;i<10;++i) insert(n[i], &head);

    printList(head);
    res=reverseKList(head);
    printList(res);

    return 0;
}