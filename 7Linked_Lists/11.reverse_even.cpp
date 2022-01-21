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

ListNode* solve(ListNode* A) {
    ListNode fakehead(0), odd(0), even(0);
    ListNode *start=&fakehead, *oddP=&odd, *evenP=&even;
    ListNode *current=A;
    int count=1;
    while(current){
        if(count%2==0){
            // Even position
            evenP->next=current;
            evenP=evenP->next;
        }
        else{
            // Odd position
            oddP->next=current;
            oddP=oddP->next;
        }
        count++;
        current=current->next;
    }
    evenP->next=NULL;
    oddP->next=NULL;
    evenP=reverseListWhole(even.next);
    oddP=odd.next;

    count=1;
    while(evenP and oddP){
        if(count%2==0){
            // Even position
            start->next=evenP;
            evenP=evenP->next;
        }
        else{
            // Odd position
            start->next=oddP;
            oddP=oddP->next;
        }
        count++;
        start=start->next;
    }
    while(evenP){
        start->next=evenP;
        start=start->next;
        evenP=evenP->next;
    }
    while(oddP){
        start->next=oddP;
        start=start->next;
        oddP=oddP->next;
    }
    start->next=NULL;
    return fakehead.next;    
}

int main(){

    ListNode *head=NULL, *res;
    // int n[]={10,9,8,7,6,5,4,3,2,1,0};
    // for(int i=0;i<11;++i) insert(n[i], &head);
    int n[]={4,3,2,1};
    for(int i=0;i<4;++i) insert(n[i], &head);
    
    printList(head);
    res=solve(head);
    printList(res);

    return 0;
}