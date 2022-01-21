// https://www.interviewbit.com/problems/add-two-numbers-as-lists/

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

ListNode* addTwoNumbers(ListNode* A, ListNode* B) {
    ListNode fakeHead(0);
    ListNode *one=A, *two=B, *start=&fakeHead;
    int carry=0, num;
    while(carry>0 || one || two){
        int num1=0,num2=0;
        if(one){
            num1=one->val;
            one=one->next;
        }
        if(two){
            num2=two->val;
            two=two->next;
        }
        num=num1+num2+carry;
        start->next=new ListNode(num%10);
        carry=num/10;
        start=start->next;
    }
    start->next=NULL;
    return fakeHead.next;
}


int main(){

    ListNode *head=NULL, *res;
    ListNode *head2=NULL;
    int n[]={9,9,9,9,9};
    // int n[]={9,8,7,6,5};
    for(int i=0;i<5;++i) insert(n[i], &head);
    int n2[]={1};
    // int n2[]={4,3,2,1};
    for(int i=0;i<1;++i) insert(n2[i], &head2);
    
    printList(head);
    printList(head2);
    res=addTwoNumbers(head, head2);
    printList(res);
    

    return 0;
}