// https://www.interviewbit.com/problems/reverse-link-list-ii/

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

ListNode* reverseBetween(ListNode* A, int B, int C) {
    if(B==C)    return A;
    ListNode *midS=A, *midE=A;
    ListNode fakehead(0);
    ListNode *left, *mid, *right, *start=&fakehead;
    // Se
    B=B-2; C--;
    // Finding position of the interval which we want to reverse
    // store the start and end position in "midS" and "midE"
    while(C){
        C--;
        midE=midE->next;
        if(B){
            B--;
            midS=midS->next;
        }
    }
    // storing three part in left, mid & right
    left=A;
    mid=midS->next;
    midS->next=NULL;
    right=midE->next;
    midE->next=NULL;

    // reversing the array generally we want to reverse the "mid" one but
    // when B=1 which indicates the part we want to reverse will be stored in "left"
    // Thus we will reverse this left part
    if(B<0) left=reverseListWhole(left);
    else mid=reverseListWhole(mid);
    
    // aligning the different list
    start->next=left;
    while(start->next){start=start->next;}
    start->next=mid;
    while(start->next){start=start->next;}
    start->next=right;

   return fakehead.next;
}


int main(){

    ListNode *head=NULL, *res;
    int n[]={10,9,8,7,6,5,4,3,2,1};
    for(int i=0;i<10;++i) insert(n[i], &head);
    
    printList(head);
    res=reverseBetween(head,1,4);
    printList(res);
    

    return 0;
}