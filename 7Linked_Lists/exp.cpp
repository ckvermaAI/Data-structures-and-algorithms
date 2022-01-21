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

ListNode *LoopStart(ListNode *LoopNode, ListNode *list){
    int count=1;
    ListNode* current=LoopNode,*prev=list;
    while(current->next!=LoopNode){count++;current=current->next;}
    current=list;
    while(count){count--; current=current->next;}
    while(prev!=current){
        current=current->next;
        prev=prev->next;
    }
    return  prev;
}

ListNode* detectCycle(ListNode* A) {
    ListNode *slow=A, *fast=A;
    while(fast and fast->next){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)  return LoopStart(slow, A);
    }
    return NULL;
}


int main(){

    ListNode *head=NULL, *res;
    int n[]={5,4,3,2,1};
    for(int i=0;i<5;++i) insert(n[i], &head);
    
    printList(head);
    head->next->next->next->next->next=head->next->next;
    res=detectCycle(head);
    cout<<res->val;
    // printList(res);
    

    return 0;
}