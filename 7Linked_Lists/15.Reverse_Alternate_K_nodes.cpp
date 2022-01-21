// https://www.interviewbit.com/problems/reverse-alternate-k-nodes/

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

ListNode* reverseKList(ListNode* A, int B) {
    if(B==1)   return A;
    ListNode *current=A;
    int count=0, slots, tempB, temp_slots;
    while(current){ count++; current=current->next;}
    slots=count/B;
    temp_slots=slots;
    ListNode fakehead(0);
    ListNode *cstart=A, *cend=A, *start=&fakehead,*res,*temp;
    while(temp_slots){
        tempB=B-1;
        while(tempB){  tempB--; cend=cend->next;}
        temp=cend->next;
        
        cend->next=NULL;
        // res=reverseListWhole(cstart);      
        // start->next=res;
        // while(start->next){start=start->next;}
        if((slots%2==0 and temp_slots%2==0)|| (slots%2!=0 and temp_slots%2!=0)){
            res=reverseListWhole(cstart);      
            start->next=res;
            while(start->next){start=start->next;}
        }
        else{
            while(cstart){
                start->next=cstart;
                start=start->next;
                cstart=cstart->next;
            }
        }

        cstart=temp;
        cend=temp;
        temp_slots--;
    }
    return fakehead.next;
}


int main(){

    ListNode *head=NULL, *res;
    int n[]={6,5,4,3,2,1};
    for(int i=0;i<6;++i) insert(n[i], &head);
    
    printList(head);
    res=reverseKList(head,2);
    printList(res);
    

    return 0;
}